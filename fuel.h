#pragma once
using namespace std;
class fuel {
public:
    string type;
    double price;

    fuel(string _type, double _price)
    {
        type = _type;
        price = _price;
    }
};
