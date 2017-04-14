#include "Passenger.h"
#include <random>

Passenger::Passenger()
{
	int startF = 0; //start floor 
	int finalF = 0; //destination floor
	char updown = ' '; 
	int idP = 0; //Passenger ID
	int starttime = 0;
	int endtime = 0;
	int finish = 0;
	int onboard = 0;
}

Passenger::~Passenger()
{
}

void Passenger::addPassenger(int maxSize)
{
	int rng1 = rand() %maxSize; //random number for passenger start floor
	int rng2 = rand() %maxSize; //random number for passenger final floor

	setStartfloor(rng1); 
	
	if (rng1 == 0) {
		rng2 = rand() % (maxSize - 1) + 1;
		

	}
	else if (rng1 == maxSize) {
		rng2 = rand() % (maxSize - 1);
		
	}
	while (rng1 == rng2) {
		rng2 = rand() % maxSize;
	}
	setEndfloor(rng2);
	setButton(rng1, rng2);
}

void Passenger::setButton(int start, int end)
{
	if (start > end) {
		this->updown = 'v';
	}
	if (start < end) {
		this->updown = '^';
	}
}




