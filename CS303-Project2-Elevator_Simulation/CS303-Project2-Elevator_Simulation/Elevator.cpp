#include "Elevator.h"


Elevator::Elevator()
{
	int passengerDesInx = 0;
	string name = ""; 
	int elevatorID = 0;
	int roundcount = 0; 
	int currentFloor = 0;
	int maxFloor = 0;
	int movestep = 0;
	movetitle = 0;
}

Elevator::~Elevator()
{
}

void Elevator::getDirection()
{


	if (!passengerOnBoardList.empty()) {
		if (pickuplst.empty()) {
			if (passengerOnBoardList[0].getButton() == '^') {
				movetitle = 2;
			}
			else {
				movetitle = 1;
			}
		}
		else {
			if (pickuplst[0].getButton() == '^' && movetitle == 0) {
				movetitle = 2;
			}
			else if (pickuplst[0].getButton() == 'v' && movetitle == 0) {
				movetitle = 1;
			}
			if ((pickuplst[0].getButton() == '^' && movetitle == 1)) {
				movetitle = 1;
			}
			if (pickuplst[0].getButton() == 'v' && movetitle == 2) {
				movetitle = 2;
			}
		}
	}
	else {
		movetitle = 3;
		cout << "No passenger in " + name;
	}

}

void Elevator::move()
{

	if (movetitle == 1) {
		decrementFloorNumber();
		timer += SEC_STOP;
		movestep++;
	}
	if (movetitle == 2) {
		incrementFloorNumber();
		timer += SEC_STOP;
		movestep++;
	}
	outOfrange();
	handleOutofRange();
}

void Elevator::outOfrange()
{
	if (currentFloor > maxFloor && outOfRange == false) {
		outOfRange = true;
		decrementFloorNumber();
		timer -= (SEC_STOP  + SEC_STOP);
		movestep -= 2;
	}
	if (currentFloor < 0 && outOfRange == false) {
		outOfRange = true;
		incrementFloorNumber();
		timer -= (SEC_STOP + SEC_STOP);
		movestep -= 2;
	}
}

void Elevator::handleOutofRange()
{
	if (currentFloor == maxFloor && movetitle == 2 && outOfRange == true ) {
		movetitle = 1;
		decrementFloorNumber();
		outOfRange = false;
	}
	if (currentFloor == 0 && movetitle == 1 && outOfRange == true) {
		movetitle = 2;
		incrementFloorNumber();
		outOfRange = false;
	}
}



void Elevator::checkDropoff()
{
	vector<Passenger>::iterator it;
	if(pickuplst.empty()) {
		checkfinish();
	}
	if (!pickuplst.empty()) {
		for (it = pickuplst.begin(); it < pickuplst.end(); it++) {
			auto ind = distance(pickuplst.begin(), it);// it - pickuplst.begin();
			if (pickuplst[ind].getEndfloor() == currentFloor && pickuplst[ind].getfinish() == 0) {
				
				passengerOnBoardList[pickuplst[ind].getindex()].setfinish(1);
				passengerOnBoardList[pickuplst[ind].getindex()].setendTime(timer);
				
				
				cout << name << " at floor " << currentFloor << " : ";
				printMoveTitle();
				cout << " : Drop off passenger ID: "
					<< passengerOnBoardList[pickuplst[ind].getindex()].getID()
					<< " Start time: " << passengerOnBoardList[pickuplst[ind].getindex()].getStartTime()
					<< " End Time: " << passengerOnBoardList[pickuplst[ind].getindex()].getEndTime()
					<< " Waiting time: " 
					<< (passengerOnBoardList[pickuplst[ind].getindex()].getEndTime() - passengerOnBoardList[pickuplst[ind].getindex()].getStartTime())
					<< endl;
				it = pickuplst.erase(it);	//remove this element from pickuplist
				if (!pickuplst.empty()) {
					it = pickuplst.begin(); //set iterator back to begin (avoid iterator not increase error)
					
				}
				else {
					break;
				}
					}
			/*else {
				auto temp = it - 1;

			}*/
			
		}
	}
	
}

void Elevator::checkpickup()
{
	
	for (int index = 0; index < passengerOnBoardList.size(); index++) {
		
		if ((passengerOnBoardList[index].getonboard() == 0) &&
			(currentFloor == passengerOnBoardList[index].getStartfloor()) &&
			(passengerOnBoardList[index].getfinish() == 0)) {

			passengerOnBoardList[index].setonboard(1);
			passengerOnBoardList[index].setstartTime(timer);
			passengerOnBoardList[index].setindex(index);

			pickuplst.push_back(passengerOnBoardList[index]);
			
			cout << name << " at floor " << currentFloor << " : ";
			printMoveTitle();
			cout << " : Pick up  passenger ID: "
				<< passengerOnBoardList[index].getID() << " Start time: "
				<< passengerOnBoardList[index].getStartTime()
				<< endl;
		}
	}
}
void Elevator::checkfinish()
{
	bool something = false;
	for (int index = 0; index < passengerOnBoardList.size(); index++) {
		if (pickuplst.empty()) {
			if (passengerOnBoardList[index].getfinish() == 1) {
				something = true;
			}
			else {
				something = false;
			}
		}
	}
	if (something == true && pickuplst.empty()) {


		movetitle = 3;
		cout << name + " FINISH : Total Movestep: " << movestep;
		for (int i = 0; i < passengerOnBoardList.size(); i++) {
			avg += (passengerOnBoardList[i].getEndTime() - passengerOnBoardList[i].getStartTime());
		}
		cout << " : Average of waiting time: " <<avg / passengerOnBoardList.size() << endl;
	}
}



//Movetitle = 0 => elevator stop no passenger on board
//Movetitle = 1 => elevator moving down
//Movetitle = 2 => elevator moving up
//Movetitle = 3 => no passenger in pickuplist, elevator STOPPED
void Elevator::outputElevatorString()
{
	while (movetitle != 3) {
		if (movetitle == 0 || movetitle == 1 || movetitle == 2) {
			
			checkpickup();
			getDirection();
			move();
			checkDropoff();			
		}
	}
}

void Elevator::printMoveTitle()
{
	switch(this->movetitle)
	{
		case 0:
		{
			cout << "Stop without passenger in list ";
			break;
		}
		case 1:
		{
			cout << "Moving Down";
			break;
		}
		case 2:
		{
			cout << " Moving UP ";
			break;
		}	
		case 3:
		{
			cout << "FINISH ";
			break;
		}
		default:
		{
			throw exception("No move title match");
			break;
		}		
	}
}
