#include "Controller.hpp"

Controller::Controller() {
	network_ = new Network;
	storage_ = new Storage;
}

Controller::~Controller() {
}

void Controller::runATN() {
	auto currentState = network_->getState1(); //starting at state1
	auto currentArc = currentState->pickRandomArc(); //pick arc out of state1

	TestObject testStorage;
	storage_->setPath(currentState);//adds the start info and is updated with a new arc if the first arc fails
	testStorage.storage = storage_;


	TestObject testArc;
	testArc.arc = currentArc;

	bool popCalled = false;
	while (popCalled == false) { //keep going until pop is found on the last state

		if (currentArc->getArcType() == GeneralArc::ARCS::POP) {
			popCalled = true;
		}

		if (currentArc->arcTestTrue(testArc, testStorage)) {
				currentState = currentArc->getNextState(); //updates currentState to nextState
				currentArc = currentState->pickRandomArc(); //ckurrentArc is updated with new arcs based on the new state

				storage_->setPath(currentState);//adds the start info and is updated with a new arc if the first arc fails
				testStorage.storage = storage_;

				testArc.arc = currentArc;
		}
		else {
			bool remainingArc = false;
			//checks if current state has other arcs that are not false for backtracking
			for (int i = 0; i < currentState->getVectorOfArcs().size(); i++) {
				if (currentState->getVectorOfArcs()[i]->getArcStatus() != "false") {
					remainingArc = true;
				}
			}
			//if yes then another arc will be chosen
			if (remainingArc == true) {
				currentArc = currentState->pickRandomArc(); //currentArc is updated with the arcs of the previousState
			}
			//if not then go back to previous state, set the previous arc status from "true" to "false" and chose a new arc
			else {
				//clears the state that is false from the storage.
				storage_->clearFalseState();

				currentState = currentArc->getPreviousState();//updates currentState to previousState				
				currentArc = currentState->pickRandomArc(); //currentArc is updated with the new picked arc

				if (currentArc->getArcStatus() == "true") {//if the current arc picked has status "true"
					currentArc->setArcStatus("false"); //then set that arc status to "false", and then pick a new arc	
					currentArc = currentState->pickRandomArc(); //currentArc picks a new random arc [is updated with the arcs of the previousState]
				}
			}
			testArc.arc = currentArc; //adds the new currentArc to the testArc so as to test again
		}
	}
	//pop arc is true
	if (popCalled == true) {

		storage_->getString();
	}
}

Storage *Controller::getStorage() {
	return storage_;
}

void Controller::printout() {

	for (int i = 0; i < storage_->getSentence().size(); i++) {
		std::cout << storage_->getSentence()[i];
		std::cout << " " << std::endl;
	}
}


