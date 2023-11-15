#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "hotels.h"

using namespace std;

const int MaxHotels = 100;

class database
{
public:
    database();
    ~database();
    hotels& AddHotel(int HotelNum,
                     string Naming,
                     string Country,
                     string City,
                     string Address,
                     int StarNumber,
                     string ContactPerson);
    hotels& GetHotel(int HotelNum);
    //hotels& GetHotel(string Naming);
    string DisplayAll();
    string DisplayCurrent();
    string DisplayFormer();
    bool saveInFile(string);
    bool readFromFile(string);
protected:
    vector<hotels> HotelArray;
};

#endif // DATABASE_H
