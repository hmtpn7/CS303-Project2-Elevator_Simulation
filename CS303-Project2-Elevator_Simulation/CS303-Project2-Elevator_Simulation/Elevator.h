//******************************************************************************
// File Name:     Elevator.h
// File Overview: Represents a Elevator
//******************************************************************************
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************
#ifndef Elevator_h
#define Elevator_h

#include "Passenger.h"

#include <string>
#include <iostream>
#include <vector>
using namespace std;

//******************************************************************************
// Class:     Elevator
//
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************
class Elevator {

public:

	
	Elevator(); //Constructor

	virtual ~Elevator(); //destructor

	void getDirection();


	void move(); //Find next move for elevator

	void outOfrange(); //check out if elevator out of range from  0 to maxFloor
	void handleOutofRange(); //change elevator direction if it out of range
	void printStep();
	void checkDropoff();
	void checkpickup();
	void checkfinish();

	void outputElevatorString(); //print output for elevator
	void printMoveTitle(); //switch enum movetitle to string and print out 

	void setmovestep(int index) { this->movestep += index; } //set passengerdesindex
	int getmovestep() { return this->movestep; } //get passengerdesindex
	void setOutofRange(bool bol) { this->outOfRange = bol; }
	bool getOutofRange() { return outOfRange; }

	void decrementFloorNumber() { this->currentFloor--; } //Decrease the floor number by one
	void incrementFloorNumber() { this->currentFloor++; } //Increase floor number
	
	//setters & getters
	void setCurrentFloor(int floor) { this->currentFloor = floor; } //set current floor for elevator
	int getCurrentFloor() {return this->currentFloor; } //get current floor

	
	void setPassengerDesInx(int index) { this->passengerDesInx = index; } //set passengerdesindex
	int getPassengerDesInx() {return this->passengerDesInx; } //get passengerdesindex

	void setElevatorID(int id) { this->elevatorID = id; } //set elevator id
	int getElevatorID() {return this->elevatorID; } //get elevator id

	void setName(string name) { this->name = name; } //setter for elevator name
	string getName() {return this->name; } //getter for elevator name
	
	void setMaxFloor(int max) {this->maxFloor = max; }

	void setMoveTitle(int moveTitle) { this->movetitle = moveTitle; }
	int getMoveTitle() { return this->movetitle; }
	
	void settime(int time) { this->timer = time; }
	int gettime() { return timer; }
	
	//constant number for elevator class
	static const int MAX_PASSENGERS = 10;  // Number of passengers in elevator
	static const int SEC_STOP = 5;  // Time moving from each floor
	
	vector<Passenger> passengerOnBoardList;
	vector<Passenger> pickuplst;
private:
	int passengerDesInx; // Destination of passenge index
	string name; // Elevator name
	int elevatorID;
	int roundcount; //variable to count how many time elevator finish it rotation.
	int currentFloor;
	int maxFloor;
	int movetitle; //Elevator Move title
	int timer;
	int movestep;
	int avg;
	bool outOfRange = false;
	
	
	
}; // end class 


#endif // Elevator_h