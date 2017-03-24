#include "Map.h"
using namespace std;

Map::Map(string startingLocationName)
{
	string hash = "(0,0)";
	_currentLocation = new Location(startingLocationName, 0, 0);
	_locationsVisited.push(_currentLocation);
	_mapLookup[hash] = _currentLocation;
}

Map::~Map() {}

void Map::Move(Location* newLocation)
{
	string hash = "(" + to_string(_currentLocation->GetXPos()) + ", " 
					  + std::to_string(_currentLocation->GetYPos()) + ")";
	_mapLookup[hash] = _currentLocation;
	_locationsVisited.push(newLocation);
	_currentLocation = newLocation;
}

string Map::GetPathBackToHome()
{
	//TO-DO!
	string path;

	/*if (_locationsVisited.top() == _mapLookup[(0,0)]);
	{
		path = "You're already at home!";
	}*/

	while (_locationsVisited.size() != 0)
	{
		path += _locationsVisited.top()->GetName() + " --> ";
		_locationsVisited.pop();
	}
	
	/*else
	{
		while (_locationsVisited.size() != 0)
		{
			path += _locationsVisited.top()->GetName() + " --> ";
			_locationsVisited.pop();
		}
	}*/
	

	/*if (_locationsVisited.top() == _mapLookup[0, 0])
	{
		path = "You're already at home!";
	}
	else
	{
		while (_locationsVisited.top() != _mapLookup[0, 0] && _locationsVisited.size() != 0)
		{
			path += _locationsVisited.top()->GetName() + " --> ";
			_locationsVisited.pop();
		}
	}*/
	
	return path;
}

Location* Map::LookupLocationOnMap(int x, int y)
{
	string hash = "(" + to_string(x) + ", " + std::to_string(y) + ")";
	return _mapLookup[hash];
}