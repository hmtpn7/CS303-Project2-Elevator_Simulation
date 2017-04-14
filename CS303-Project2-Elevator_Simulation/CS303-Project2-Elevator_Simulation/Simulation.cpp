#include "Simulation.h"
#include <iostream>
#include <string>
Simulation::Simulation()
{
}
Simulation::~Simulation()
{
}
//Add passenger to passenger list
void Simulation::addInformation(Passenger passenger, Elevator elevator)
{
	
	for (int index = 0; index < NUMBER_OF_PASSENGER; index++) {
		passenger.addPassenger(NUMBER_OF_FLOOR);
		passenger.setId(index);		
		passenger.setfinish(0);
		passenger.setonboard(0);
		passenger.setstartTime(0);
		passenger.setendTime(0);
		this->passengerList.push_back(passenger);
	}
	for (int ind = 1; ind <= NUMBER_OF_ELEVATOR; ind++) {
		
		elevator.setCurrentFloor(0);
		elevator.setElevatorID(ind);
		elevator.setMaxFloor(NUMBER_OF_FLOOR);
		elevator .setName("Elevator " + to_string(ind) + " ");
		this->elevatorList.push_back(elevator);
	}
	

}



void Simulation::outputString()
{
	Passenger passenger;
	Elevator elevate;
	for (int index = 0; index < NUMBER_OF_PASSENGER; index++) {
		passenger.addPassenger(NUMBER_OF_FLOOR);
		passenger.setId(index);
		passenger.setfinish(0);
		passenger.setonboard(0);
		passenger.setstartTime(0);
		passenger.setendTime(0);
		this->passengerList.push_back(passenger);
	}

	elevate.setCurrentFloor(0);
	elevate.setElevatorID(1);
	elevate.setMaxFloor(NUMBER_OF_FLOOR);
	elevate.setName("Elevator " + to_string(1) + " ");
	
	cout << "\t\t\t\t SINGLE ELEVATOR" << endl;

	////test string for passengerlist
	//cout << "passenger list:{ Id:Button:StartF:EndF" << endl;
	//for (int a = 0; a < NUMBER_OF_PASSENGER; a++) {		
	//	cout << "\t\t  "<< passengerList.at(a).getID() << "   " << passengerList.at(a).getButton() << "      " << passengerList.at(a).getStartfloor() << "     " << passengerList.at(a).getEndfloor() << endl;
	//}
	//cout << " \t\t\t\t\t}" << endl;


	while (!passengerList.empty()) {		
	
				elevate.passengerOnBoardList.push_back(passengerList[0]);
				passengerList.erase(passengerList.begin());
					
	}
	elevate.outputElevatorString();
	cout << "______________________________________________________" << endl;
	
	cout << endl << endl << endl;

	
}

void Simulation::multipleElevatorsoutputString()
{
	Passenger passenger;
	Elevator elevate;
	addInformation(passenger, elevate);


	////test string for passengerlist
	//cout << "passenger list:{ Id:Button:StartF:EndF" << endl;
	//for (int a = 0; a < NUMBER_OF_PASSENGER; a++) {		
	//	cout << "\t\t  "<< passengerList.at(a).getID() << "   " << passengerList.at(a).getButton() << "      " << passengerList.at(a).getStartfloor() << "     " << passengerList.at(a).getEndfloor() << endl;
	//}
	//cout << " \t\t\t\t\t}" << endl;

	cout << "\t\t\t\t\t MULTIPLE ELEVATORS" << endl;
	vector<Passenger>::iterator temp;
	temp = passengerList.begin();
	while (temp != passengerList.end()) {

		if (!passengerList.empty()) {

			for (int ind = 0; ind < NUMBER_OF_ELEVATOR; ind++) {

				if (elevatorList[ind].getMoveTitle() == 0) {
					elevatorList[ind].passengerOnBoardList.push_back(*temp);
					temp = passengerList.erase(temp);

				}
				if (elevatorList[ind].getMoveTitle() == 1 && temp->getButton() == 'v') {
					elevatorList[ind].passengerOnBoardList.push_back(*temp);
					temp = passengerList.erase(temp);


				}
				if (elevatorList[ind].getMoveTitle() == 2 && temp->getButton() == '^') {
					elevatorList[ind].passengerOnBoardList.push_back(*temp);
					temp = passengerList.erase(temp);
				}
				if (passengerList.empty()) {
					break;
				}
			
				pickup(ind);
				getDirection(ind);
				moving(ind);
				dropoff(ind);
				
			}

		}
		else {
			temp++;
		}

	}
	for (int b = 0; b < NUMBER_OF_ELEVATOR; b++) {
		for (int a = 0; a < elevatorList[b].passengerOnBoardList.size(); a++) {

			cout << elevatorList[b].getName() <<elevatorList[b].passengerOnBoardList[a].getID() << " "
				<< elevatorList[b].passengerOnBoardList[a].getButton() << " "
				<< elevatorList[b].passengerOnBoardList[a].getStartfloor() << " "
				<< elevatorList[b].passengerOnBoardList[a].getEndfloor() << endl;

		}
		elevatorList[b].outputElevatorString();
	}

	/*for (int ind = 0; ind < NUMBER_OF_ELEVATOR; ind++) {
		while (elevatorList[ind].getMoveTitle() != 3) {
			if (elevatorList[ind].getMoveTitle() == 0 || elevatorList[ind].getMoveTitle() == 1 || elevatorList[ind].getMoveTitle() == 2) {
				pickup(ind);
				getDirection(ind);
				moving(ind);
				dropoff(ind);
			}
		}
	}*/


}


void Simulation::pickup(int ind)
{

	for (int index = 0; index < elevatorList[ind].passengerOnBoardList.size(); index++) {

		if ((elevatorList[ind].passengerOnBoardList[index].getonboard() == 0) &&
			(elevatorList[ind].getCurrentFloor() == elevatorList[ind].passengerOnBoardList[index].getStartfloor()) &&
			(elevatorList[ind].passengerOnBoardList[index].getfinish() == 0)) {

			elevatorList[ind].passengerOnBoardList[index].setonboard(1);
			elevatorList[ind].passengerOnBoardList[index].setstartTime(elevatorList[ind].gettime());
			elevatorList[ind].passengerOnBoardList[index].setindex(index);

			elevatorList[ind].pickuplst.push_back(elevatorList[ind].passengerOnBoardList[index]);

			cout << elevatorList[ind].getName() << " at floor " << elevatorList[ind].getCurrentFloor() << " : ";
			elevatorList[ind].printMoveTitle();
			cout << " : Pick up  passenger ID: "
				<< elevatorList[ind].passengerOnBoardList[index].getID() << " Start time: "
				<< elevatorList[ind].passengerOnBoardList[index].getStartTime()
				<< endl;
		}
	}

}

void Simulation::getDirection(int ind)
{
	if (!elevatorList[ind].passengerOnBoardList.empty()) {
		if (elevatorList[ind].pickuplst.empty()) {
			if (elevatorList[ind].passengerOnBoardList[0].getButton() == '^') {
				elevatorList[ind].setMoveTitle(2);
			}
			else {
				elevatorList[ind].setMoveTitle(1);
			}
		}
		else {
			if (elevatorList[ind].pickuplst[0].getButton() == '^' && elevatorList[ind].getMoveTitle() == 0) {
				elevatorList[ind].setMoveTitle(2);
			}
			else if (elevatorList[ind].pickuplst[0].getButton() == 'v' &&elevatorList[ind].getMoveTitle() == 0) {
				elevatorList[ind].setMoveTitle(1);
			}
			if ((elevatorList[ind].pickuplst[0].getButton() == '^' && elevatorList[ind].getMoveTitle() == 1)) {
				elevatorList[ind].setMoveTitle(1);
			}
			if (elevatorList[ind].pickuplst[0].getButton() == 'v' && elevatorList[ind].getMoveTitle() == 2) {
				elevatorList[ind].setMoveTitle(2);
			}
		}
	}
	else {
		elevatorList[ind].setMoveTitle(3);
		cout << "No passenger in " + elevatorList[ind].getName();
	}
}

void Simulation::moving(int ind)
{
	if (elevatorList[ind].getMoveTitle() == 1) {
		elevatorList[ind].decrementFloorNumber();
		elevatorList[ind].settime(elevatorList[ind].SEC_STOP);
		elevatorList[ind].setmovestep(1);
	}
	if (elevatorList[ind].getMoveTitle() == 2) {
		elevatorList[ind].incrementFloorNumber();
		elevatorList[ind].settime(elevatorList[ind].SEC_STOP);
		elevatorList[ind].setmovestep(1);
	}
	if (elevatorList[ind].getCurrentFloor() > NUMBER_OF_FLOOR && elevatorList[ind].getOutofRange() == false) {
		elevatorList[ind].setOutofRange(true);
		elevatorList[ind].decrementFloorNumber();
		int a = elevatorList[ind].gettime();
		//a -= (elevatorList[ind].SEC_STOP + elevatorList[ind].SEC_STOP);
		elevatorList[ind].settime(-(elevatorList[ind].SEC_STOP + elevatorList[ind].SEC_STOP));

		elevatorList[ind].setmovestep(-2);
	}
	if (elevatorList[ind].getCurrentFloor() < 0 && elevatorList[ind].getOutofRange() == false) {
		elevatorList[ind].setOutofRange(true);
		elevatorList[ind].incrementFloorNumber();
		elevatorList[ind].settime(-(elevatorList[ind].SEC_STOP + elevatorList[ind].SEC_STOP));
		elevatorList[ind].setmovestep(-2);
	}
	if (elevatorList[ind].getCurrentFloor() == NUMBER_OF_FLOOR && elevatorList[ind].getMoveTitle() == 2 && elevatorList[ind].getOutofRange() == true) {
		elevatorList[ind].setMoveTitle(1);
		elevatorList[ind].decrementFloorNumber();
		elevatorList[ind].setOutofRange(false);
	}
	if (elevatorList[ind].getCurrentFloor() == 0 && elevatorList[ind].getMoveTitle() == 1 && elevatorList[ind].getOutofRange() == true) {
		elevatorList[ind].setMoveTitle(2);
		elevatorList[ind].incrementFloorNumber();
		elevatorList[ind].setOutofRange(false);
	}
}

void Simulation::dropoff(int ind)
{
	vector<Passenger>::iterator it;
	if (elevatorList[ind].pickuplst.empty()) {
		//finish();
	}
	if (!elevatorList[ind].pickuplst.empty()) {
		for (it = elevatorList[ind].pickuplst.begin(); it < elevatorList[ind].pickuplst.end(); it++) {
			auto index = distance(elevatorList[ind].pickuplst.begin(), it);// it - pickuplst.begin();
			if (elevatorList[ind].pickuplst[ind].getEndfloor() == elevatorList[ind].getCurrentFloor() && elevatorList[ind].pickuplst[index].getfinish() == 0) {

				elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].setfinish(1);
				elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].setendTime(elevatorList[ind].gettime());


				cout << elevatorList[ind].getName() << " at floor " << elevatorList[ind].getCurrentFloor() << " : ";
				elevatorList[ind].printMoveTitle();
				cout << " : Drop off passenger ID: "
					<< elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].getID()
					<< " Start time: " << elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].getStartTime()
					<< " End Time: " << elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].getEndTime()
					<< " Waiting time: "
					<< (elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].getEndTime() - elevatorList[ind].passengerOnBoardList[elevatorList[ind].pickuplst[index].getindex()].getStartTime())
					<< endl;
				it = elevatorList[ind].pickuplst.erase(it);	//remove this element from pickuplist
				if (!elevatorList[ind].pickuplst.empty()) {
					it = elevatorList[ind].pickuplst.begin(); //set iterator back to begin (avoid iterator not increase error)

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

void Simulation::finish(int ind)
{
	bool something = false;
	for (int index = 0; index < elevatorList[ind].passengerOnBoardList.size(); index++) {
		if (elevatorList[ind].pickuplst.empty()) {
			if (elevatorList[ind].passengerOnBoardList[index].getfinish() == 1) {
				something = true;
			}
			else {
				something = false;
			}
		}
	}
	if (something == true && elevatorList[ind].pickuplst.empty()) {


		elevatorList[ind].setMoveTitle(3);
		cout << elevatorList[ind].getName() + " FINISH : Total Movestep: " << elevatorList[ind].getmovestep();
		for (int i = 0; i < elevatorList[ind].passengerOnBoardList.size(); i++) {
			avg += (elevatorList[ind].passengerOnBoardList[i].getEndTime() - elevatorList[ind].passengerOnBoardList[i].getStartTime());
		}
		cout << " : Average of waiting time: " << avg / elevatorList[ind].passengerOnBoardList.size() << endl;
	}
}