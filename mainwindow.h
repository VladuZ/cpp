#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QLabel>

#include <stdexcept>
#include <string>
#include "database.h"

int DisplayMenu();
void DoActivate(database& inDB, string, string, string, string, string, string, string);
void DoDeactivate(database& inDB, string HotelNum);
void DoIncreaseStarCount(database& inDB, string HotelNum);
void DoDecreaseStarCount(database& inDB, string HotelNum);

using namespace::std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void handleButton();
private:
    QLineEdit *inputFieldHotelNum;
    QLineEdit *inputFieldNaming;
    QLineEdit *inputFieldCountry;
    QLineEdit *inputFieldCity;
    QLineEdit *inputFieldAddress;
    QLineEdit *inputFieldStarNum;
    QLineEdit *inputFieldContactPerson;
    QLineEdit *inputFieldIsActive;

    QTextEdit *outputField;

    QComboBox *comboBox;

    QLabel *labelHotelNum;
    QLabel *labelNaming;
    QLabel *labelCountry;
    QLabel *labelCity;
    QLabel *labelAddress;
    QLabel *labelStarNum;
    QLabel *labelContactPerson;
    QLabel *labelIsActive;
    QLabel *labelComboBox;
    void saveFile();
    void openFile();
public:
    database hotelsDB;
};
#endif // MAINWINDOW_H
