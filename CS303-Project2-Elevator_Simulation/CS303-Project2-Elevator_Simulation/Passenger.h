//******************************************************************************
// File Name:     Passenger.h
// File Overview: Represents a Elevator
//******************************************************************************
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************

#ifndef Passenger_h
#define Passenger_h

using namespace std;
//******************************************************************************
// Class:     Passenger
//
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************
class Passenger {
public:
	Passenger(); //Default constructor

	virtual ~Passenger(); //Destructor

	void addPassenger(int maxSize); //Add passenger


	//setters
	void setEndfloor(int endfloor) { this->finalF = endfloor; }
	void setStartfloor(int startfloor) { this->startF = startfloor; }
	void setId(int id) { this->idP = id; }
	void setstartTime(int startT) { this->starttime = startT; }
	void setendTime(int endT) { this->endtime = endT; }
	void setButton(int start, int end);
	void setfinish(int checked) { this->finish = checked; }
	void setonboard(int checked) { this->onboard = checked; }
	void setindex(int ind) { this->indexInelevator = ind; }
	//getters
	int getindex() { return this->indexInelevator; }
	int getfinish() { return this->finish; }
	int getEndfloor() { return this->finalF; }
	int getStartfloor() { return this->startF; }
	int getID() { return this->idP; }
	int getStartTime() { return this->starttime; }
	int getEndTime() { return this->endtime; }
	char getButton() { return this->updown; }
	int getonboard() { return this->onboard; }
private:
	int startF; //start floor 
	int finalF; //destination floor
	char updown; //1 if passenger clicked up button, 0 if passenger click down button
	int idP; //Passenger ID
	int starttime;
	int endtime;
	int finish;
	int onboard;
	int indexInelevator;
}; //End class


#endif // Passenger_h