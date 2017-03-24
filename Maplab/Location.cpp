#include <iostream>
#include "Location.h"
using namespace std;


Location::Location(string name, int x, int y)
{
	_name = name;
	_x = x;
	_y = y;
}

Location::~Location() {}

string Location::GetName()
{
	return _name;
}

void Location::DisplayLocationInfo()
{
	cout << _name << " -- (" << this->GetXPos() << ", " << this->GetYPos() << ")." << endl;
}

