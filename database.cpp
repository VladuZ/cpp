#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
#include <QErrorMessage>
#include <fstream>

using namespace std;

database::database()
{
}
database::~database()
{
}
hotels& database::AddHotel(int HotelNum,
                           string Naming,
                           string Country,
                           string City,
                           string Address,
                           int StarNumber,
                           string ContactPerson)
{
    if (HotelArray.size() >= MaxHotels) {
        QErrorMessage *errorMessage = new QErrorMessage;
        errorMessage->showMessage("There is no more room to add the new hotel!");
        throw exception();

    }
    hotels* TheHotel = new hotels();
    TheHotel->SetHotelNum(HotelNum);
    TheHotel->SetNaming(Naming);
    TheHotel->SetCountry(Country);
    TheHotel->SetCity(City);
    TheHotel->SetAddress(Address);
    TheHotel->SetStarNumber(StarNumber);
    TheHotel->SetContactPerson(ContactPerson);
    TheHotel->Activate();
    HotelArray.push_back(*TheHotel);
    return *TheHotel;
}
hotels& database::GetHotel(int HotelNum)
{
    for (int i = 0; i < HotelArray.size(); i++) {
        if (HotelArray[i].GetHotelNum() == HotelNum) {
            return HotelArray[i];
        }
    }
    QErrorMessage *errorMessage = new QErrorMessage;
    errorMessage->showMessage("No hotel with this number");
    throw exception();
}
/*hotels& database::GetHotel(string Naming)
{
    for (int i = 0; i < NextSlot; i++) {
        if (HotelArray[i].GetNaming() == Naming) {
            return HotelArray[i];
        }
    }
    QErrorMessage *errorMessage = new QErrorMessage;
    errorMessage->showMessage("No match with this naming ");
    throw exception();Z
}*/
string database::DisplayAll()
{
    string result;
    for (int i = 0; i < HotelArray.size(); i++) {
        result += HotelArray[i].Print();
    }
    return result;
}
string database::DisplayCurrent()
{
    string result;
    for (int i = 0; i < HotelArray.size(); i++) {
        if (HotelArray[i].GetIsActive()) {
            result += HotelArray[i].Print();
        }
    }
    return result;
}
string database::DisplayFormer()
{
    string result;
    for (int i = 0; i < HotelArray.size(); i++) {
        if (!HotelArray[i].GetIsActive()) {
            result += HotelArray[i].Print();
        }
    }
    return result;
}

bool database::saveInFile(string fileRoute)
{
    std::ofstream myFile;
    myFile.open(fileRoute);
    if(myFile.is_open())
    {
        myFile << DisplayAll();
        myFile.close();
        return true;
    }
    else
        return false;
}

bool database::readFromFile(string fileRoute)
{
    ifstream myFile;
    myFile.open(fileRoute);

    if(!myFile.is_open())
        return false;

    HotelArray.clear();

    string line;
    hotels hotels;
    while (getline(myFile, line))
    {
        string separateHotels = "";
        for (int i = 0; i < 9; i++)
        {
            separateHotels += line+'\n';
            getline(myFile, line);
        }
        HotelArray.push_back(hotels.fromString(separateHotels));
    }
    myFile.close();
    return true;
}
