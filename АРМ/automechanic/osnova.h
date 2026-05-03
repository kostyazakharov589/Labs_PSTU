#ifndef OSNOVA_H
#define OSNOVA_H
#include <QMainWindow>
#include <QMainWindow>
#include "databasemanager.h"
#include <QList>
#include <QSpinBox>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class osnova;
}
QT_END_NAMESPACE
struct SeasonEntry {//структура для разбивки по сезонам
    int year;
    QString seasonName;
    QSpinBox* spinKm;  //указатели на км и тип дороги
    QComboBox* cmbRoad;
};
struct ReplacedPart {
    QString partName;
    int year;
    QString season;
};
class osnova : public QMainWindow
{
    Q_OBJECT

public:
    explicit osnova(QWidget *parent = nullptr);
    ~osnova() override;

private:
    Ui::osnova *ui;
    databasemanager dbManager;
    void saveProfileToJson(const QString &make, const QString &model, int year, int mileage); //жесон профилди
    void prepareSeasonsPage();//сезоны на 3 странице
    QList<SeasonEntry> generatedSeasons;
    void generateTimeline();
    void loadProfile(const QString &profileName);
    double calculateEffectiveMileage();
    QList<ReplacedPart> replacedPartsList;
    void prepareReplacementsPage();
};
#endif // OSNOVA_H
