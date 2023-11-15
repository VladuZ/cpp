#ifndef HOTELS_H
#define HOTELS_H
#include <iostream>
#include <sstream>

using namespace std;

class hotels
{
    int HotelNum;
    string Naming;
    string Country;
    string City;
    string Address;
    int StarNumber;
    string ContactPerson;
    bool isActive;

public:
    hotels();

    string Print();

    void IncreaseStarCount();
    void DecreaseStarCount();

    void Activate();
    void Deactivate();
    void SetHotelNum(int);
    void SetNaming(string);
    void SetCountry(string);
    void SetCity(string);
    void SetAddress(string);
    void SetStarNumber(int);
    void SetContactPerson(string);

    hotels fromString(const string&);

    int GetHotelNum();
    string GetNaming();
    string GetCountry();
    string GetCity();
    string GetAddress();
    int GetStarNumber();
    string GetContactPerson();
    bool GetIsActive();
};

#endif // HOTELS_H
