#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

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
		cout << "6) Show Your Path To Home" << endl;
		cout << "0) Exit" << endl;

		cin >> choice;
		switch (choice)
		{
			case 1: 
				cout << "Your current location is ";
				map._currentLocation->DisplayLocationInfo();
				break;
			case 2: GoNorth(map); break;
			case 3: GoEast(map); break;
			case 4: GoSouth(map); break;
			case 5: GoWest(map); break;
			case 6: 
				system("cls");  
				cout << "Here's how to get back to home: " << endl
					<< map.GetPathBackToHome() 
					<< "HOME"; 
				break;
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
	int currentX = map._currentLocation->GetXPos();
	int currentY = map._currentLocation->GetYPos();

	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			string name;

			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called ";
			newLocation->DisplayLocationInfo();
		}
		else
		{
			cout << "You've been here before! You are at ";
			existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at ";
		newLocation->DisplayLocationInfo();
	}

	newLocation->South = map._currentLocation;
	map.Move(newLocation);
	return;
}

void GoSouth(Map &map) 
{
	auto newLocation = map._currentLocation->South;
	int currentX = map._currentLocation->GetXPos();
	int currentY = map._currentLocation->GetYPos();

	if (newLocation == nullptr)
	{
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			string name;

			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called ";
			newLocation->DisplayLocationInfo();
		}
		else
		{
			cout << "You've been here before! You are at ";
			existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at ";
		newLocation->DisplayLocationInfo();
	}

	newLocation->North = map._currentLocation;
	map.Move(newLocation);
	return;
}

void GoEast(Map &map) 
{
	auto newLocation = map._currentLocation->East;
	int currentX = map._currentLocation->GetXPos();
	int currentY = map._currentLocation->GetYPos();

	if (newLocation == nullptr)
	{
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			string name;

			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called ";
			newLocation->DisplayLocationInfo();
		}
		else
		{
			cout << "You've been here before! You are at ";
			existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at ";
		newLocation->DisplayLocationInfo();
	}

	newLocation->West = map._currentLocation;
	map.Move(newLocation);
	return;
}

void GoWest(Map &map) 
{
	auto newLocation = map._currentLocation->West;
	int currentX = map._currentLocation->GetXPos();
	int currentY = map._currentLocation->GetYPos();

	if (newLocation == nullptr)
	{
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);

		if (existing == nullptr)
		{
			string name;

			system("cls");
			cout << "You haven't been here before, enter a name for this place: ";
			cin >> name;
			newLocation = new Location(name, newX, newY);
			cout << "This place is now called ";
			newLocation->DisplayLocationInfo();
		}
		else
		{
			cout << "You've been here before! You are at ";
			existing->DisplayLocationInfo();
		}
	}
	else
	{
		cout << "You are at ";
		newLocation->DisplayLocationInfo();
	}

	newLocation->East = map._currentLocation;
	map.Move(newLocation);
	return;
}