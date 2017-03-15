#include "Map.h"


void Map::Move(Location *newLocation)
{
	_locationsVisited.push(newLocation);
	_currentLocation = newLocation;
}

std::string Map::getPathBackToHome()
{
	//TO-DO!
	std::string path = _currentLocation->getName();

	if (_locationsVisited.size > 0)
	{
		for (int i = 0; i < _locationsVisited.size(); i++)
		{
			//path += _locationsVisited

		}
	}
	
	return std::string();
}

Map::Map(std::string startingLocationName)
{
	_currentLocation = new Location(startingLocationName);
}


Map::~Map()
{
}
