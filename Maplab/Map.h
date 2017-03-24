#pragma once
#include <stack>
#include <unordered_map>
#include "Location.h"

class Map
{
	private:
		std::stack<Location*> _locationsVisited;
		std::unordered_map<std::string, Location*> _mapLookup;

	public:
		Map(std::string startingLocationName);
		~Map();

		Location* _currentLocation = nullptr;
		Location* LookupLocationOnMap(int x, int y);

		std::string GetPathBackToHome();
		void Move(Location* newLocation);
};

