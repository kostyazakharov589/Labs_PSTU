#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QDebug>
#include <QStringList>

QStringList getCarMakes();

class databasemanager
{
public:
    databasemanager();//коснтуркетор
    ~databasemanager();//деструктор
    bool connectToDataBase();//подключение к бд
    QStringList getCarModels(const QString &make);
    QList<int> getCarYears(const QString &make, const QString &model);
    QStringList getSavedProfiles();//профили
    QStringList getCarMakes();//получение

private:
    QSqlDatabase db;//объект класса
    bool createTable();//создаём таблицу

};

#endif
