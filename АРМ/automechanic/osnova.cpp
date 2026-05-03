#include "osnova.h"
#include "ui_osnova.h"
#include <QMessageBox>
#include <QCompleter>
#include <QStringListModel>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QDir>
#include <QDate>
#include <QLabel>
#include <QHBoxLayout>
#include <QGroupBox>

osnova::osnova(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::osnova)
{
    ui->setupUi(this);

    if (dbManager.connectToDataBase()) {
        qDebug() << "База данных успешно подключена";

        ui->profileSelector->addItems(dbManager.getSavedProfiles());


        QStringList makeList = dbManager.getCarMakes(); //подключаем профили и выводим их
        QCompleter *makeCompleter = new QCompleter(makeList, this);//создаём ядро из профилей
        makeCompleter->setCaseSensitivity(Qt::CaseInsensitive);//сделать все буквы однострочными
        ui->makeInput->setCompleter(makeCompleter);//прикручиваем к полю ядро


        QCompleter *modelCompleter = new QCompleter(this);// для моделей
        modelCompleter->setCaseSensitivity(Qt::CaseInsensitive);//сделать все буквы однострочными
        ui->modelInput->setCompleter(modelCompleter);//прикручиваем к полю ядро

        ui->modelInput->setEnabled(false); //всё заблокировано
        ui->yearInput->setEnabled(false);
        ui->mileageInput->setEnabled(false);
        ui->btnNext->setEnabled(false);


        connect(ui->makeInput, &QLineEdit::textChanged, this, [this, modelCompleter]() { //ищем модель после ввода марки
            ui->modelInput->clear(); // Стираем старую модель
            ui->yearInput->clear();  // Стираем старые года

            // СБРОС: блокируем нижние поля, если марку стерли или изменили
            ui->modelInput->setEnabled(false);
            ui->yearInput->setEnabled(false);
            ui->mileageInput->setEnabled(false);
            ui->btnNext->setEnabled(false);

            QString currentMake = ui->makeInput->text(); //ввод
            QStringList models = dbManager.getCarModels(currentMake); //вывод моделей машин

            if (!models.isEmpty()) { // Если модели найдены, то разблокируем поле
                modelCompleter->setModel(new QStringListModel(models, modelCompleter)); // Загружаем найденные модели в подсказки
                ui->modelInput->setEnabled(true);
            }
        });

        connect(ui->modelInput, &QLineEdit::textChanged, this, [this]() {
            QString currentMake = ui->makeInput->text();//ищем год выпуска после ввода модели
            QString currentModel = ui->modelInput->text();

            const QList<int> years = dbManager.getCarYears(currentMake, currentModel);
            ui->yearInput->clear();


            ui->yearInput->setEnabled(false);//если модель поменялась, то блокируем, то что ниже
            ui->mileageInput->setEnabled(false);
            ui->btnNext->setEnabled(false);

            if (!years.isEmpty()) { //проверяем, что список годов не пуст
                for (int y : years) { //перебираем все готовые года, которые отдала база
                    ui->yearInput->addItem(QString::number(y));//выводим года
                }

                // Разблокируем последние элементы
                ui->yearInput->setEnabled(true);
                ui->mileageInput->setEnabled(true);
                ui->btnNext->setEnabled(true);
            }
        });
    }

    ui->detailsBox->setVisible(false);
    ui->replaceBox->setVisible(false);

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->btnAddNewCar, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->profileSelector, &QComboBox::activated, this, [this](int) {
        QString selectedName = ui->profileSelector->currentText();
        loadProfile(selectedName); // подгружаем инфу в память
        ui->stackedWidget->setCurrentIndex(4); // А потом показываем результат
    });
    //

    //1 страница
    connect(ui->btnBackToCar, &QPushButton::clicked, this, [this]() {
        prepareSeasonsPage();
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnNext, &QPushButton::clicked, this, [this]() {
        prepareSeasonsPage();
        ui->stackedWidget->setCurrentIndex(2);
    });
    //

    //2 страница
    connect(ui->btnBackToCar2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->radioRefine, &QRadioButton::toggled, this, [this](bool checked) {
        ui->detailsBox->setVisible(checked);
    });

    connect(ui->btnCalculate, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->btnGenerateTimeline, &QPushButton::clicked, this, &osnova::generateTimeline);

    connect(ui->radioSkip, &QRadioButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3);
    });
    //

    //3 страница
    connect(ui->btnBackToSeasons, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->radioReplaceYes, &QRadioButton::toggled, this, [this](bool checked) {
        ui->replaceBox->setVisible(checked);
    });

    connect(ui->radioReplaceSkip, &QRadioButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(4);
        QString make = ui->makeInput->text();
        QString model = ui->modelInput->text();
        int year = ui->yearInput->currentText().toInt();
        int mileage = ui->mileageInput->value();

        saveProfileToJson(make, model, year, mileage);//сохраняем в жесон


        ui->profileSelector->clear();//динамически обновляем список
        ui->profileSelector->addItems(dbManager.getSavedProfiles());//добавляем в список наших профиоей
    });

    connect(ui->btnGoToResults, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(4);
        QString make = ui->makeInput->text();
        QString model = ui->modelInput->text();
        int year = ui->yearInput->currentText().toInt();
        int mileage = ui->mileageInput->value();

        saveProfileToJson(make, model, year, mileage);//сохраняем в жесон

        ui->profileSelector->clear();//динамически обновляем список
        ui->profileSelector->addItems(dbManager.getSavedProfiles());//добавляем в список наших профиоей
    });
    //

    //4 страница
    connect(ui->btnBackToHistory, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btnRestart, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
}


void osnova::saveProfileToJson(const QString &make, const QString &model, int year, int mileage)//сохраняем профили в жесон
{
    QJsonObject profileObj;
    profileObj["make"] = make;
    profileObj["model"] = model;
    profileObj["year"] = year;
    profileObj["mileage"] = mileage;
    double avgKm = calculateEffectiveMileage();

    profileObj["startMonthIdx"] = ui->cmbStartMonth->currentIndex();
    profileObj["endMonthIdx"] = ui->cmbEndMonth->currentIndex();
    profileObj["startYear"] = ui->spinStartYear->currentText().toInt();
    profileObj["endYear"] = ui->spinEndYear->currentText().toInt();
    //сохраняем всё в жесон сначала базовый профиль, а потом начало и конец использования
    QJsonArray timelineArray; // Создаем массив для истории

    for (const SeasonEntry &entry : generatedSeasons) {//перебираем для сохранения года
        QJsonObject seasonObj;
        seasonObj["year"] = entry.year;
        seasonObj["season"] = entry.seasonName;
        int val = entry.spinKm->value();
        int finalKm = val;
        if (val == 0) {
            finalKm = (int)avgKm;//для среднего арифм
        }
        seasonObj["km"] = entry.spinKm->value();
        seasonObj["road_k"] = entry.cmbRoad->currentText(); //собираем сезоны

        timelineArray.append(seasonObj); // Добавляем сезон в историю
    }

    profileObj["timeline"] = timelineArray; //прикрепляем историю к профилю

    QJsonDocument doc(profileObj);
    QDir().mkpath("profiles");

    QString fileName = QString("%1-%2(%3).json").arg(make, model, QString::number(year));//сохраняем
    QFile file("profiles/" + fileName);

    if (file.open(QIODevice::WriteOnly)) {//открываем и записываем в жесон
        file.write(doc.toJson());
        file.close();
        qDebug() << "Профиль успешно сохранен со всеми сезонами в " << fileName;
    } else {
        qDebug() << "Ошибка! Не удалось создать файл " << fileName;//проверка на всякий
    }
}

void osnova::prepareSeasonsPage() {//подготовка страницы с сезонами года
    int carYear = ui->yearInput->currentText().toInt();//берём год выпуска машины, выбранную юзером

    int currentYear = QDate::currentDate().year();//какой текущий год?

    ui->spinStartYear->clear();//очищаем от старых данных
    ui->spinEndYear->clear();

    for (int y = carYear; y <= currentYear; ++y) {//создаём списки с годами владения
        ui->spinStartYear->addItem(QString::number(y));
        ui->spinEndYear->addItem(QString::number(y));//начало и конец соответственно
    }
}


QStringList getActiveSeasonsForYear(int currentYear, int startYear, int startMonth, int endYear, int endMonth) {//для сезонов года
    QStringList activeSeasons;//подключаем сезоны


    int mStart = (currentYear == startYear) ? startMonth : 1; //если год первый, то начинаем с месяца покупки, иначе с января
    int mEnd   = (currentYear == endYear)   ? endMonth   : 12; //если год последний, то заканчиваем месяцем продажи, иначе декабрем

    auto hasMonth = [&](int m) {
        return m >= mStart && m <= mEnd;
    };//проверяем на соотвествие месяцам

    if (hasMonth(1) || hasMonth(2) || hasMonth(12)) activeSeasons << "Зима";//присваиеваем сезоны
    if (hasMonth(3) || hasMonth(4) || hasMonth(5))  activeSeasons << "Весна";
    if (hasMonth(6) || hasMonth(7) || hasMonth(8))  activeSeasons << "Лето";
    if (hasMonth(9) || hasMonth(10) || hasMonth(11)) activeSeasons << "Осень";

    return activeSeasons;
}
void osnova::generateTimeline()//генерируем сезоны исходя из введенных дат владения
{
    // 1. Очищаем старые виджеты
    QLayoutItem *child;
    while ((child = ui->verticalLayout_2->takeAt(0)) != nullptr) {//чё-то для работы, без него плохо чому-то
        if (child->widget())
            delete child->widget();
        delete child;
    }
    generatedSeasons.clear();//очищаем от предыдущей генерации

    // Берем Месяцы и Года из интерфейса
    int startMonth = ui->cmbStartMonth->currentIndex() + 1;
    int endMonth   = ui->cmbEndMonth->currentIndex() + 1;
    int startYear  = ui->spinStartYear->currentText().toInt();
    int endYear    = ui->spinEndYear->currentText().toInt();


    if (endYear < startYear || (endYear == startYear && endMonth < startMonth)) {
        qDebug() << "Ошибка: Период конца указан раньше периода начала!";//защита на всякий случай
        return;
    }

    QStringList roadTypes = {"Город", "Трасса", "Грунтовые", "Бездорожье", "Гараж"};//типы дорог

    for (int y = startYear; y <= endYear; ++y) {//генерация блоков по годам

        QStringList activeSeasons = getActiveSeasonsForYear(y, startYear, startMonth, endYear, endMonth);//получаем список из введённых данных
        if (activeSeasons.isEmpty()) continue;

        QGroupBox *yearBox = new QGroupBox("Год " + QString::number(y), this);//создаём виджет из года и сезона
        QVBoxLayout *yearLayout = new QVBoxLayout(yearBox);

        for (const QString &seasonName : activeSeasons) {
            QWidget *rowWidget = new QWidget(yearBox);//создаём виджеты для отображения годов
            QHBoxLayout *rowLayout = new QHBoxLayout(rowWidget);
            rowLayout->setContentsMargins(5, 5, 5, 5);

            QLabel *lblSeason = new QLabel(seasonName, rowWidget);//выгрузка сезонов
            lblSeason->setMinimumWidth(60);

            QSpinBox *spinKm = new QSpinBox(rowWidget);//выгрузка км
            spinKm->setMaximum(500000);//максимальный
            spinKm->setSuffix(" км");//ввод км

            QComboBox *cmbRoad = new QComboBox(rowWidget);//создаём комбобокс для ввода дорог
            cmbRoad->addItems(roadTypes);

            rowLayout->addWidget(lblSeason);
            rowLayout->addWidget(spinKm);
            rowLayout->addWidget(cmbRoad);
            yearLayout->addWidget(rowWidget);//добавляем виджеты по дорогам и прочим для ввода

            SeasonEntry entry;
            entry.year = y;
            entry.seasonName = seasonName;
            entry.spinKm = spinKm;
            entry.cmbRoad = cmbRoad;
            generatedSeasons.append(entry); // Сохраняем для JSON
        }

        ui->verticalLayout_2->addWidget(yearBox);
    }

   ui->verticalLayout_2->addStretch();
}
void osnova::loadProfile(const QString &profileName) {//загружаем профили машин
    QFile file("profiles/" + profileName + ".json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonObject obj = QJsonDocument::fromJson(file.readAll()).object();
    file.close();

    ui->makeInput->setText(obj["make"].toString());//заполняем всё на первой странице
    ui->modelInput->setText(obj["model"].toString());


    ui->yearInput->clear();//добавляем год чтобы ничего не ломалось
    ui->yearInput->addItem(QString::number(obj["year"].toInt()));
    ui->yearInput->setCurrentIndex(0);
    ui->mileageInput->setValue(obj["mileage"].toInt());

    prepareSeasonsPage();//списки на странице сезонов

    ui->cmbStartMonth->setCurrentIndex(obj["startMonthIdx"].toInt());//восстанавливаем всё из жесона в сезоны
    ui->cmbEndMonth->setCurrentIndex(obj["endMonthIdx"].toInt());
    ui->spinStartYear->setCurrentText(QString::number(obj["startYear"].toInt()));
    ui->spinEndYear->setCurrentText(QString::number(obj["endYear"].toInt()));

    generateTimeline();//всё отрисовываем

    QJsonArray timeline = obj["timeline"].toArray();//вписываем все изменения в поля
    for (int i = 0; i < timeline.size() && i < generatedSeasons.size(); ++i) {
        QJsonObject sObj = timeline[i].toObject();
        generatedSeasons[i].spinKm->setValue(sObj["km"].toInt());//км
        generatedSeasons[i].cmbRoad->setCurrentText(sObj["road_k"].toString());//тип дороги
    }
}
double osnova::calculateEffectiveMileage() {//функция подсчёта среднего пробега по сезонам
    int totalBaseMileage = ui->mileageInput->value();
    double totalUserEntered = 0;
    int emptySeasonsCount = 0;

    for (const SeasonEntry &entry : generatedSeasons) { //подсчитываем то, что пользователь уже ввёл
        int val = entry.spinKm->value();
        if (val > 0) {
            totalUserEntered += val;

        }
        else {
            emptySeasonsCount++;
        }
    }

    double distributedKm = 0;
    if (emptySeasonsCount > 0 && totalBaseMileage > totalUserEntered) {
        distributedKm = (double)(totalBaseMileage - totalUserEntered) / emptySeasonsCount; //вычисление среднего пробега для невведённых полей
    }

    return distributedKm; //возвращаем
}
osnova::~osnova()
{
    delete ui;
}