#include "hotels.h"

hotels::hotels() {
    HotelNum = -1;
    Naming = "";
    Country = "";
    City = "";
    Address = "";
    StarNumber = -1;
    ContactPerson = "";
    isActive = false;
}

void hotels::Activate() {
    isActive = true;
}

void hotels::Deactivate() {
    isActive = false;
}

void hotels::IncreaseStarCount() {
    StarNumber++;
}

void hotels::DecreaseStarCount() {
    StarNumber--;
}

void hotels::SetHotelNum(int inHotelNum) {
    HotelNum = inHotelNum;
}

void hotels::SetNaming(string inNaming)
{
    Naming = inNaming;
}

void hotels::SetCountry(string inCountry)
{
    Country = inCountry;
}

void hotels::SetCity(string inCity)
{
    City = inCity;
}

void hotels::SetAddress(string inAddress)
{
    Address = inAddress;
}

void hotels::SetStarNumber(int inStarNumber)
{
    StarNumber = inStarNumber;
}

void hotels::SetContactPerson(string inContactPerson)
{
    ContactPerson = inContactPerson;
}

int hotels::GetHotelNum()
{
    return HotelNum;
}

string hotels::GetNaming()
{
    return Naming;
}

string hotels::GetCountry()
{
    return Country;
}

string hotels::GetCity()
{
    return City;
}

string hotels::GetAddress()
{
    return Address;
}

int hotels::GetStarNumber()
{
    return StarNumber;
}

string hotels::GetContactPerson()
{
    return ContactPerson;
}

bool hotels::GetIsActive()
{
    return isActive;
}

string hotels::Print()
{
    return "Hotel: " + GetNaming() + "\n" +
    "-------------------------" + "\n" +
    (isActive ? "Active Hotel" : "Inactive Hotel") + "\n" +
    "Hotel Number: " + to_string(GetHotelNum()) + "\n" +
    "Country: " + GetCountry() + "\n" +
    "City: " + GetCity() + "\n" +
    "Address: " + GetAddress() + "\n" +
    "Star Number: " + to_string(GetStarNumber()) + "\n" +
    "Contact Person: " + GetContactPerson() + "\n\n";
}

hotels hotels::fromString(const string &hotelString)
{
    hotels hotelObject;

    istringstream iss(hotelString);
    string line;

    while (getline(iss, line))
    {
        size_t pos = line.find(": ");
        if (pos != string::npos)
        {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 2);

            if (key == "Hotel")
            {
                hotelObject.SetNaming(value);
            }
            else if (key == "Hotel Number")
            {
                hotelObject.SetHotelNum(stoi(value));
            }
            else if (key == "Country")
            {
                hotelObject.SetCountry(value);
            }
            else if (key == "City")
            {
                hotelObject.SetCity(value);
            }
            else if (key == "Address")
            {
                hotelObject.SetAddress(value);
            }
            else if (key == "Star Number")
            {
                hotelObject.SetStarNumber(stoi(value));
            }
            else if (key == "Contact Person")
            {
                hotelObject.SetContactPerson(value);
            }
        }
        else if (line == "Active Hotel" || line == "Inactive Hotel")
        {
            hotelObject.isActive = (line == "Active Hotel");
        }
    }

    return hotelObject;
}
