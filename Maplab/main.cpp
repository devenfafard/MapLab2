#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

int main();

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);

int main()
{
	Map map = Map("Home");

	int choice = -1;
	while (choice != 0)
	{
		cout << "1) Display Current Location" << endl;
		cout << "2) Go North" << endl;
		cout << "3) Go East" << endl;
		cout << "4) Go South" << endl;
		cout << "5) Go West" << endl;
		cout << "6) Path To Home" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		switch (choice)
		{
			case 1: cout << "Current Location: " << map._currentLocation->getName() << endl; break;
			case 2: GoNorth(map); break;
			case 3: GoEast(map); break;
			case 4: GoSouth(map); break;
			case 5: GoWest(map); break;
			case 6: system("cls");  cout << map.getPathBackToHome() << endl; break;
			default: cout << "Enter a valid option" << endl; break;
		}

		system("pause");
	}

	system("pause");
	return 0;
}

void GoNorth(Map &map)
{
	auto newLocation = map._currentLocation->North;

	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;
	}
	else
	{
		cout << "You are at: " + newLocation->getName() << endl;
	}

	newLocation->South = map._currentLocation;
	map.Move(newLocation);
	return;
}

void GoSouth(Map &map)
{
	auto newLocation = map._currentLocation->South;

	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;
	}
	else
	{
		cout << "You are at: " + newLocation->getName() << endl;
	}

	newLocation->North = map._currentLocation;
	map.Move(newLocation);
	return;
}

void GoEast(Map &map)
{
	auto newLocation = map._currentLocation->East;

	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;
	}
	else
	{
		cout << "You are at: " + newLocation->getName() << endl;
	}

	newLocation->West = map._currentLocation;
	map.Move(newLocation);
	return;
}

void GoWest(Map &map)
{
	auto newLocation = map._currentLocation->West;

	if (newLocation == nullptr)
	{
		system("cls");
		cout << "You haven't been here before, enter a name for this place: ";
		string name;
		cin >> name;
		newLocation = new Location(name);
		cout << "This place is now called: " + name << endl;
	}
	else
	{
		cout << "You are at: " + newLocation->getName() << endl;
	}

	newLocation->East = map._currentLocation;
	map.Move(newLocation);
	return;
}