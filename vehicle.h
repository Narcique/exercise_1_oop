#pragma once
using namespace std;
class vehicle {
public:
    string type, category;
    vehicle(string _type, string _category)
    {
        type = _type;
        category = _category;
    }
};