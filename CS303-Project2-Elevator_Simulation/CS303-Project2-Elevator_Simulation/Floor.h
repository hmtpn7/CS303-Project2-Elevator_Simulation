//******************************************************************************
// File Name:     Floor.h
// File Overview: Represents a Floor
//******************************************************************************
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************

#ifndef Floor_h
#define Floor_h

using namespace std;
//******************************************************************************
// Class:     Floor
//
// Revision History:
// Date             Author               Description 
// 3/29/2017        Hung Tran			 Added new class
//******************************************************************************
class Floor {
private:
	int number; //Floor number
public:
	Floor() { this->number = Floor::START_FLOOR; }; //Constructor

	int getNumber() { return this->number; } //Getter of floor number
	void setNumber(int number) { this->number = number; } //Setter

	void decrementFloorNumber() { this->number--; } //Decrease the floor number by one
	void incrementFloorNumber() { this->number++; } //Increase floor number

	static const int START_FLOOR = 1; //Start at the first floor

}; //End class


#endif // Floor_h