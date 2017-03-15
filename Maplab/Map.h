#pragma once
#include "Location.h"
#include <stack>

class Map
{
	private:
		std::stack<Location*> _locationsVisited;

	public:
		Location *_currentLocation = nullptr;
		void Move(Location *newLocation);
		std::string getPathBackToHome();
		Map(std::string startingLocationName);
		~Map();	
	
};

