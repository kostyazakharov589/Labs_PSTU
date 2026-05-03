#include "databasemanager.h"
#include <QDir>
#include <algorithm>
#include <QFileInfo>

databasemanager::databasemanager() {}//конструктор базы

databasemanager::~databasemanager()//деконструкторк для её закрытия после выхода из приложения
{
    if(db.isOpen()) {
        db.close();
    }
}

bool databasemanager::connectToDataBase()//открытие бд
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cars_database.db");//создаём файл с бд
    if (!db.open()) {
        qDebug() << "Ошибка при открытии БД" << db.lastError().text();
        return false;
    }
    return createTable();
}


bool databasemanager::createTable(){//создание бд
    QSqlQuery query;
    QString str = "CREATE TABLE IF NOT EXISTS SavedCars ("//задаём правила для правильного отображения данных
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "profile TEXT NOT NULL, "
                  "make TEXT NOT NULL, "
                  "model TEXT NOT NULL, "
                  "year INTEGER NOT NULL, "
                  "mileage INTEGER NOT NULL"
                  ");";
    if (!query.exec(str)) {
        qDebug() << "Ошибка создания таблицы " << query.lastError().text();
        return false;
    }
    return true;
}

QStringList databasemanager::getCarMakes()//обращение к дб к 1 странице с вводом профиля
{
    QStringList makes;
    QSqlQuery query("SELECT DISTINCT make FROM CarCatalog ORDER BY make ASC");

    while (query.next()) {
        makes.append(query.value(0).toString());
    }

    return makes;
}
QStringList databasemanager::getSavedProfiles() //получаем профили через жесон
{
    QStringList profiles;
    QDir dir("profiles");

    if (!dir.exists()) {//создаём папку
        dir.mkpath(".");
        return profiles;
    }


    QStringList filters;//поиск по json
    filters << "*.json";
    QStringList files = dir.entryList(filters, QDir::Files);


    for (QString &file : files) {    // Добавляем имена файлов в список без .json
        QFileInfo fileInfo(file);
        profiles.append(fileInfo.baseName());
    }
    return profiles;
}

QStringList databasemanager::getCarModels(const QString &make)//ввод моделей
{
    QStringList models;
    QSqlQuery query;

    query.prepare("SELECT DISTINCT model FROM CarCatalog WHERE make = :make ORDER BY model ASC");
    query.bindValue(":make", make);

    if (query.exec()) {
        while (query.next()) {
            models.append(query.value(0).toString());
        }
    }
    return models;
}

QList<int> databasemanager::getCarYears(const QString &make, const QString &model)//ввод годов
{
    QList<int> years; //берём лист годов
    QSqlQuery query;


    query.prepare("SELECT start_year, end_year FROM CarCatalog WHERE make = :make AND model = :model");
    query.bindValue(":make", make);
    query.bindValue(":model", model); //подгружаем из базы данных по моделям и маркам

    if (query.exec()) {
        while (query.next()) {
            int startYear = query.value(0).toInt(); //берём значения годов и добавляем в программиу
            int endYear = query.value(1).toInt();


            for (int y = endYear; y >= startYear; --y) {//генерируем года для каждого периода
                if (!years.contains(y)) {
                    years.append(y);
                }
            }
        }
    }
    //сортируем убыванию
    std::sort(years.begin(), years.end(), std::greater<int>());

    return years;
}