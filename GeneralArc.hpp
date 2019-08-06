#pragma once
#include "Includes.hpp"
#include "Test.hpp"

//class Storage;
class GeneralState;

class GeneralArc {
public:
	enum class ARCS {
		POP,
		PUSH,
		JUMP,
		WRD,
	};


	GeneralArc();
	//first arc (basically initial state)
	GeneralArc(GeneralState *currentState, GeneralArc::ARCS arcType, std::string action, GeneralState *nextState);

	//middle arcs
	GeneralArc(GeneralState *prevState, GeneralState *currentState, GeneralArc::ARCS arcType, std::string action, GeneralState *nextState);
	
	//last arc (POP basically)
	GeneralArc(GeneralState *prevState, GeneralState *currentState, GeneralArc::ARCS arcType);

	~GeneralArc();

	ARCS getArcType();

	GeneralState *getPreviousState();
	GeneralState *getCurrentState();
	GeneralState *getNextState();

	bool arcTestTrue(TestObject arcObject, TestObject storageObject);

	void setArcStatus(std::string status);
	std::string getArcStatus();

	std::string getArcAction();



private:
	std::string arcStatus_;
	std::string arcAction_;
	ARCS arcType_;
	Test test_;
	GeneralState *prevState_, *currentState_, *nextState_;

	std::vector<std::string> stringValue_;
};
