#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include "fuel.h"
#include "distance.h"
#include "vehicle.h"
using namespace std;


template <class T> void illegal_char(T a) {

    if (a > 10 || a<=0) 
        cout << "The input is invalid, please pick a number from the list above!\n";
}



int main() {
    cout << "This app calculates the distance and price to a journey from Craiova to a certain location\n";
    cout << "Please select the transportation method:\n";
    cout << "1.Personal vehicle.\n2.Common transport.\n3.Special vehicles.\n" "\n";
    int i;
    int comm=0;
    cin >> i;
    illegal_char(i);
        if (i > 10 || i <= 0)
            return 0;
    vehicle* pers = new vehicle("personal", "Car");
    vehicle* common = new vehicle("common_transport", "Bus");
    vehicle* common2 = new vehicle("common_transport", "Trolleybus");
    vehicle* common3 = new vehicle("common_transport", "Tram");
    vehicle* common4 = new vehicle("common_transport", "Taxi");
    vehicle* common5 = new vehicle("common_transport", "Subway");
    vehicle* spec = new vehicle("special_vehicles", "Truck");
    vehicle* spec2 = new vehicle("special_vehicles", "Van");
    vehicle* spec3 = new vehicle("special_vehicles", "Bike");
    vehicle* spec4 = new vehicle("special_vehicles", "Scooter");
    fuel* petrl = new fuel("Petrol", 7.10);
    fuel* dies = new fuel("Diesel", 8.34);
    fuel* ticket = new fuel("Ticket", 2.5);
    fuel* tax = new fuel("Taxi", 2.59);
    distancee* buc = new distancee("Bucuresti", 245);
    distancee* cons = new distancee("Constanta", 472);
    distancee* slat = new distancee("Slatina", 56);
    if (i == 1) {

        cout << pers->category << '\n'; 
    }
    if (i == 2) {
        cout << "1." <<common->category << '\n';
        cout << "2." <<common2->category << '\n';
        cout << "3." <<common3->category << '\n';
        cout << "4." <<common4->category << '\n';
        cout << "5." <<common5->category << '\n';
    }
    if (i == 3)
    {
        cout << "1." <<spec->category << '\n';
        cout << "2." <<spec2->category << '\n';
        cout << "3." <<spec3->category << '\n';
        cout << "4." <<spec4->category << '\n';
    }
    if (i == 1) {
        cout << '\n';
        cout << "What fuel does your vehicle run on?" << '\n' << "(this may varry according to the vehicle type)\n";
        cout << "1." << petrl->type << "(" << petrl->price << "lei/liter)\n" << " or\n" << "2." << dies->type << "(" << dies->price << "lei/liter)\n" "\n";
        double consumption = 0.6;
        int z;
        cin >> z;
        illegal_char(z);

        cout << '\n';
        cout << "Where do you want to go?\n";
        cout << "1." << buc->city << '\n' << "2." << cons->city << '\n' << "3." << slat->city << '\n';
        int x;
        cin >> x;
        illegal_char(x);


        int answer = 0;
        cout << "The total cost of the journey is: ";

        if (x == 1 && z == 1)
            cout << buc->dist * consumption / 10 * petrl->price << " lei for the distance of " << buc->dist << " km.";

        else if (x == 2 && z == 1)
            cout << cons->dist * consumption / 10 * petrl->price << " lei for the distance of " << cons->dist << " km.";

        else if (x == 3 && z == 1)
            cout << slat->dist * consumption / 10 * petrl->price << " lei for the distance of " << slat->dist << " km.";



        else if (x == 1 && z == 2)
            cout << buc->dist * consumption / 10 * dies->price << " lei for the distance of " << buc->dist << " km.";

        else  if (x == 2 && z == 2)
            cout << cons->dist * consumption / 10 * dies->price << " lei for the distance of " << cons->dist << " km.";

        else  if (x == 3 && z == 2)
            cout << slat->dist * consumption / 10 * dies->price << " lei for the distance of " << slat->dist << " km.";
        return 0;
    }
    else if (i == 2)
    {
        cin >> comm;
        illegal_char(comm);
        if (comm == 4)
        {
            cout << "The price for a taxi journey is " << tax->price << " per kilometer." << endl;
            cout << "Avalaible locations:" << endl;
            cout << "1." << buc->city << '\n' << "2." << cons->city << '\n' << "3." << slat->city << '\n';
            cin >> comm;
            cout << "The total cost of the journey is: ";
            if (comm == 1)
            {
                cout << tax->price * buc->dist;
                cout << " lei for the distance of " << buc->dist << " km.";
            }
            else if (comm == 2)
            {
                cout << tax->price * cons->dist;
                cout << " lei for the distance of " << cons->dist << " km.";
            }

            else if (comm == 3)
            {
                cout << tax->price * slat->dist;
                cout << " lei for the distance of " << slat->dist << " km.";
            }
        }
        else {
            cout << endl;
            cout << "Your vehicle only can be used to travel inside the city." << endl;
            cout << "The price for a ticket inside Craiova, " << buc->city << ", " << slat->city << " or " << cons->city << " is " << ticket->price << " lei.";
        }
    }
    else if (i == 3)
        cout << "Your vehicles are curently unavailable for transport outside Craiova.";
}