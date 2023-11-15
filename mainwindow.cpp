#include "mainwindow.h"
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QErrorMessage>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Lab 3");
    setGeometry(700, 200, 600, 310);
    setMinimumSize(600, 310);

    inputFieldHotelNum = new QLineEdit(this);
    inputFieldHotelNum->setGeometry(160, 10, 140, 20);

    inputFieldNaming = new QLineEdit(this);
    inputFieldNaming->setGeometry(160, 40, 140, 20);

    inputFieldCountry = new QLineEdit(this);
    inputFieldCountry->setGeometry(160, 70, 140, 20);

    inputFieldCity = new QLineEdit(this);
    inputFieldCity->setGeometry(160, 100, 140, 20);

    inputFieldAddress = new QLineEdit(this);
    inputFieldAddress->setGeometry(160, 130, 140, 20);

    inputFieldStarNum = new QLineEdit(this);
    inputFieldStarNum->setGeometry(160, 160, 140, 20);

    inputFieldContactPerson = new QLineEdit(this);
    inputFieldContactPerson->setGeometry(160, 190, 140, 20);

    inputFieldIsActive = new QLineEdit(this);
    inputFieldIsActive->setGeometry(160, 220, 140, 20);

    comboBox = new QComboBox(this);
    comboBox->setGeometry(160, 250, 140, 20);
    comboBox->addItem("Add hotel");
    comboBox->addItem("Remove hotel");
    comboBox->addItem("Increase star count");
    comboBox->addItem("Decrease star count");
    comboBox->addItem("List all hotels");
    comboBox->addItem("List all active hotels");
    comboBox->addItem("List all inactive hotels");
    comboBox->addItem("Write into a file");
    comboBox->addItem("Read a file");

    labelHotelNum = new QLabel("Enter Hotel Number: ", this);
    labelHotelNum->setGeometry(10, 10, 140, 20);

    labelNaming = new QLabel("Enter Hotel Naming: ", this);
    labelNaming->setGeometry(10, 40, 140, 20);

    labelCountry = new QLabel("Enter Hotel Country: ", this);
    labelCountry->setGeometry(10, 70, 140, 20);

    labelCity = new QLabel("Enter Hotel City: ", this);
    labelCity->setGeometry(10, 100, 140, 20);

    labelAddress = new QLabel("Enter Hotel Address: ", this);
    labelAddress->setGeometry(10, 130, 140, 20);

    labelStarNum = new QLabel("Enter Number of Stars: ", this);
    labelStarNum->setGeometry(10, 160, 140, 20);

    labelContactPerson = new QLabel("Enter Contact Person: ", this);
    labelContactPerson->setGeometry(10, 190, 140, 20);

    labelIsActive = new QLabel("Enter if Hotel is Active: ", this);
    labelIsActive->setGeometry(10, 220, 140, 20);

    labelComboBox = new QLabel("Choose an action: ", this);
    labelComboBox->setGeometry(10, 250, 140, 20);

    QPushButton *processButton = new QPushButton("Proceed", this);
    processButton->setGeometry(160, 280, 60, 20);
    connect(processButton, SIGNAL (released()), this, SLOT (handleButton()));

    outputField = new QTextEdit("Here you will see output", this);
    outputField->setGeometry(310, 10, 280, 290);
    outputField->setReadOnly(true);
}

void MainWindow::handleButton()
{
    switch (comboBox->currentIndex()) {
    case 0:
        DoActivate(hotelsDB, inputFieldHotelNum->text().toStdString(), inputFieldNaming->text().toStdString(), inputFieldCountry->text().toStdString(), inputFieldCity->text().toStdString(), inputFieldAddress->text().toStdString(), inputFieldStarNum->text().toStdString(), inputFieldContactPerson->text().toStdString());
        break;
    case 1:
        DoDeactivate(hotelsDB, inputFieldHotelNum->text().toStdString());
        break;
    case 2:
        DoIncreaseStarCount(hotelsDB, inputFieldHotelNum->text().toStdString());
        break;
    case 3:
        DoDecreaseStarCount(hotelsDB, inputFieldHotelNum->text().toStdString());
        break;
    case 4:
        outputField->setText(QString::fromStdString(hotelsDB.DisplayAll()));
        break;
    case 5:
        outputField->setText(QString::fromStdString(hotelsDB.DisplayCurrent()));
        break;
    case 6:
        outputField->setText(QString::fromStdString(hotelsDB.DisplayFormer()));
        break;
    case 7:
        saveFile();
        break;
    case 8:
        openFile();
        break;
    default:
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("Unknown command");
    }
}

void DoActivate(database& inDB, string HotelNum, string Naming, string Country, string City, string Address, string StarNum, string ContactPerson)
{
    try {
        inDB.AddHotel(stoi(HotelNum), Naming,	Country, City, Address, stoi(StarNum), ContactPerson);
    }
    catch (std::exception ex) {
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("Unable to add new hotel!");
    }
}

void DoDeactivate(database& inDB, string HotelNum)
{
    try {
        hotels& hotel = inDB.GetHotel(stoi(HotelNum));
        hotel.Deactivate();
    }
    catch (std::exception ex) {
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("Unable to remove hotel!");
    }
}

void DoIncreaseStarCount(database& inDB, string HotelNum)
{
    try {

        hotels& hotel = inDB.GetHotel(stoi(HotelNum));
        hotel.IncreaseStarCount();
    }
    catch (...) {
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("Unable to increase star count!");
    }
}

void DoDecreaseStarCount(database& inDB, string HotelNum)
{
    try {

        hotels& hotel = inDB.GetHotel(stoi(HotelNum));
        hotel.DecreaseStarCount();
    }
    catch (...) {
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("Unable to decrease star count!");
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, "Save Text File", "D:\\temp", "Text files(*.txt);;All files (*.*)");
    if(!path.isEmpty())
        hotelsDB.saveInFile(path.toStdString());
}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this, "Open Text File", "D:\\temp", "Text files(*.txt);;All files (*.*)");
    if(!path.isEmpty())
        hotelsDB.readFromFile(path.toStdString());
    outputField->setText(QString::fromStdString(hotelsDB.DisplayAll()));
}

MainWindow::~MainWindow()
{
}

