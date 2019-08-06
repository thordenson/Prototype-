#include "GeneralArc.hpp"
#include "GeneralState.hpp"

GeneralArc::GeneralArc() {
}


GeneralArc::GeneralArc(GeneralState *currentState, GeneralArc::ARCS arcType, std::string action, GeneralState *nextState) {
	currentState_ = currentState;
	nextState_ = nextState;
	arcType_ = arcType;
	arcAction_ = action;
}

GeneralArc::GeneralArc(GeneralState * prevState, GeneralState *currentState, GeneralArc::ARCS arcType, std::string action, GeneralState * nextState){
	prevState_ = prevState;
	currentState_ = currentState;
	nextState_ = nextState;
	arcType_ = arcType;
	arcAction_ = action;
}

GeneralArc::GeneralArc(GeneralState *prevState, GeneralState *currentState, GeneralArc::ARCS arcType) {
	prevState_ = prevState;
	currentState_ = currentState;
	arcType_ = arcType;
}

GeneralArc::~GeneralArc() {
}

GeneralArc::ARCS GeneralArc::getArcType() {
	return arcType_;
}

std::string GeneralArc::getArcAction() {
	return arcAction_;
}

GeneralState *GeneralArc::getPreviousState() {
	return prevState_;
}

GeneralState * GeneralArc::getCurrentState(){
	return currentState_;
}

GeneralState *GeneralArc::getNextState() {
	return nextState_;
}

void GeneralArc::setArcStatus(std::string status) {
	arcStatus_ = status;
}

std::string GeneralArc::getArcStatus() {
	return arcStatus_;
}

bool GeneralArc::arcTestTrue(TestObject arcObject, TestObject storageObject) {
	return test_.isTestTrue(arcObject, storageObject);
}
