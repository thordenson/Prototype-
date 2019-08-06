#include "Test.hpp"
#include "Storage.hpp"
#include "Controller.hpp"
#include "GeneralArc.hpp"
#include "GeneralState.hpp"


Test::Test() {
}

Test::~Test() {
}

bool Test::isTestTrue(TestObject arcObject, TestObject storageObject) {
	if (arcObject.arc != nullptr) {

		//random arc chosen to be tested for traversal
		auto pickedArcType = arcObject.arc->getArcType();

		//storage is going to be used for checking
		auto storage = storageObject.storage->getPath();

		//kan gjør sånn som æ gjorde det i generalArc klassen.
		if (pickedArcType == GeneralArc::ARCS::POP) {
			arcPOP(arcObject, storageObject);
		}
		if (pickedArcType == GeneralArc::ARCS::PUSH) {
			arcPUSH(arcObject, storageObject);
		}
		if (pickedArcType == GeneralArc::ARCS::JUMP) {
			arcJUMP(arcObject, storageObject);
		}
		if (pickedArcType == GeneralArc::ARCS::WRD) {
			arcWRD(arcObject, storageObject);
		}

		//at the end the picked arc has it's status checked
		//if it is "true" then return true
		if (arcObject.arc->getArcStatus() == "true") {
			return true;
		}
		//if it is "false" return false
		else {
			return false;
		}
	}
}


bool Test::arcPOP(TestObject arcObject, TestObject storageObject) {

	auto pickedArcStatus = arcObject.arc->getArcStatus();
	auto pickedArcAction = arcObject.arc->getArcAction();

	//the random arc's current state and the arcs connected to that state
	auto getPickedArcCurrentState = arcObject.arc->getCurrentState();
	auto getPickedArcCurrentVector = getPickedArcCurrentState->getVectorOfArcs();

	//storage is going to be used for checking
	auto storage = storageObject.storage->getPath();


	//should test if i can pop
	if (!storage.empty()) {
		//check if pop is called on a GeneralSubState i henhold til PUSH arc
		//check if pop is called not on a GeneralSubStatae
	}

	//at the end the picked arc has it's status checked
	//if it is "true" then return true
	if (arcObject.arc->getArcStatus() == "true") {
		return true;
	}
	//if it is "false" return false
	else {
		return false;
	}
}

bool Test::arcPUSH(TestObject arcObject, TestObject storageObject) {
	return false;
}

bool Test::arcJUMP(TestObject arcObject, TestObject storageObject) {
	return false;
}

bool Test::arcWRD(TestObject arcObject, TestObject storageObject) {
	//the random arc's status and action
	auto pickedArcStatus = arcObject.arc->getArcStatus();
	auto pickedArcAction = arcObject.arc->getArcAction();

	//the random arc's current state and the arcs connected to that state
	auto getPickedArcCurrentState = arcObject.arc->getCurrentState();
	auto getPickedArcCurrentVector = getPickedArcCurrentState->getVectorOfArcs();

	//storage is going to be used for checking
	auto storage = storageObject.storage->getPath();

	//sets status to all arcs on first state, to "onHold", except the picked one which gets set to true
	//checks also if we're on first state and checks if picked arc has no status
	//if any of these are false then we continue onwards
	if (getPickedArcCurrentState->getFirstState() && pickedArcStatus.empty()) {
		for (int j = 0; j < getPickedArcCurrentVector.size(); j++) {
			getPickedArcCurrentVector[j]->setArcStatus("onHold");
		}
		arcObject.arc->setArcStatus("true");
	}

	//checks if picked arc has no status
	if (arcObject.arc->getArcStatus() == "") {
		int i = 0;
		arcStatusBool_ = true;
		//goes through the storage as long as i is less the size of storage and arcStatusBool_ is true
		while (i < storage.size() && arcStatusBool_ == true) {

			int j = 0;
			auto storagePathVectorOfArcs = storage[j]->getVectorOfArcs();
			//goes through the vector of arcs in storage as long as j is less the size of vector of arcs and arcStatusBool_ is true
			while (j < storagePathVectorOfArcs.size() && arcStatusBool_ == true) {

				//if any arc in the vector of arcs has the value true
				if (storagePathVectorOfArcs[j]->getArcStatus() == "true") {
					//go through states in storage 
					for (int k = 0; k < storage.size(); k++) {
						auto arcsInState = storage[k]->getVectorOfArcs();
						//go through all the arcs in the state
						for (int j = 0; j < arcsInState.size(); j++) {
							//check if any arc has "true"
							if (arcsInState[j]->getArcStatus() == "true") {
								//check if that arc that is "true" also has the same action 
								//as the currently pickedarc has
								if (arcsInState[j]->getArcAction() == pickedArcAction) {
									//then the status of the picked arc is false, because there can not be
									//2 of the same action(word) right after each other
									arcStatusBool_ = false;
								}
							}
						}
					}
				}
				j++;
			}
			i++;
		}
		//checks if bool status of the arc is true
		if (arcStatusBool_) {
			//if it is true then go through all the arcs connected to the current state
			//and give them the status "onHold"
			for (int j = 0; j < getPickedArcCurrentVector.size(); j++) {
				getPickedArcCurrentVector[j]->setArcStatus("onHold");
			}
			//gives the current arc the status "true"
			arcObject.arc->setArcStatus("true");
		}
		//if bool status is false
		else {
			//if it is false then go through all the arcs connected to the current state
			//and give them the status "onHold"
			for (int j = 0; j < getPickedArcCurrentVector.size(); j++) {
				getPickedArcCurrentVector[j]->setArcStatus("onHold");
			}
			//gives the current arc the status "false"
			arcObject.arc->setArcStatus("false");
		}
	}


	//checks if picked arc has the "onHold" status
	if (arcObject.arc->getArcStatus() == "onHold") {
		int i = 0;
		arcStatusBool_ = true;
		//goes through the storage as long as i is less the size of storage and arcStatusBool_ is true
		while (i < storage.size() && arcStatusBool_ == true) {
			int j = 0;
			auto storagePathVectorOfArcs = storage[j]->getVectorOfArcs();
			//goes through the vector of arcs in storage as long as j is less the size of vector of arcs and arcStatusBool_ is true
			while (j < storagePathVectorOfArcs.size() && arcStatusBool_ == true) {
				//if any arc in the vector of arcs has the value true
				if (storagePathVectorOfArcs[j]->getArcStatus() == "true") {
					//go through states in storage 
					for (int k = 0; k < storage.size(); k++) {
						auto arcsInState = storage[k]->getVectorOfArcs();
						//go through states in storage arcs
						for (int j = 0; j < arcsInState.size(); j++) {
							//check if any arc has "true"
							if (arcsInState[j]->getArcStatus() == "true") {
								//check if that arc that is "true" also has the same action 
								//as the currently pickedarc has
								if (arcsInState[j]->getArcAction() == pickedArcAction) {
									//then the status of the picked arc is false, because there can not be
									//2 of the same action(word) right after each other
									arcStatusBool_ = false;
								}
							}
						}
					}
				}
				j++;
			}
			i++;
		}
		//checks if bool status of the arc is true
		if (arcStatusBool_) {
			//if it is true then go through all the arcs connected to the current state
			for (int j = 0; j < getPickedArcCurrentVector.size(); j++) {
				//if any of the arc has false then their status is not changed
				if (getPickedArcCurrentVector[j]->getArcStatus() != "false") {
					//if an arc does not have the status false it gets the status "onHold"
					getPickedArcCurrentVector[j]->setArcStatus("onHold");
				}
			}
			//gives the current arc the status "true"
			arcObject.arc->setArcStatus("true");
		}
		//if bool status is false
		else {
			//if it is false then go through all the arcs connected to the current state
			for (int j = 0; j < getPickedArcCurrentVector.size(); j++) {
				//if any of the arc has false then their status is not changed
				if (getPickedArcCurrentVector[j]->getArcStatus() != "false") {
					//if an arc does not have the status false it gets the status "onHold"
					getPickedArcCurrentVector[j]->setArcStatus("onHold");
				}
			}
			//gives the current arc the status "false"
			arcObject.arc->setArcStatus("false");
		}
	}

	//at the end the picked arc has it's status checked
	//if it is "true" then return true
	if (arcObject.arc->getArcStatus() == "true") {
		return true;
	}
	//if it is "false" return false
	else {
		return false;
	}
}