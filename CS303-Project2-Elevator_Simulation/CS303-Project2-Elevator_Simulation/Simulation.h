//******************************************************************************
// File Name:     Simulation.h
// File Overview: Represents a Simulation
//******************************************************************************
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************

#ifndef Simulation_h
#define Simulation_h

#include <string>
#include <vector>
#include "Elevator.h"
//#include "Floor.h"
#include "Passenger.h"
class Simulation {
private:
	vector<double> avgWaitTime; //Vector of average waiting time
	vector<double> avagTravelTime; //Vector of average traveling time

	string output; //Output datat string
	vector<Passenger> passengerList;
	vector<Elevator> elevatorList;

	int avg;
public:
	static const int NUMBER_OF_FLOOR = 50;
	static const int NUMBER_OF_PASSENGER = 100;
	static const int NUMBER_OF_ELEVATOR = 4;
	static const int ELEVATOR_SIZE = 8;

	Simulation(); //Constructor
	virtual ~Simulation();
	void addInformation(Passenger passenger, Elevator elevator); //Add passenger

	void outputString();
	void multipleElevatorsoutputString();
	void pickup(int ind);

	void getDirection(int ind);

	void moving(int ind);
	void dropoff(int ind);

	void finish(int ind);



	
}; //End class


#endif // Simulation_h