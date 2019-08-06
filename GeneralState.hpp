#pragma once
#include "Includes.hpp"

class GeneralArc;

class GeneralState {
public:

	GeneralState();
	GeneralState(bool firstState);
	~GeneralState();

	void setVectorOfArcs(std::vector<GeneralArc*> arcs);
	std::vector<GeneralArc*> getVectorOfArcs();

	GeneralArc *pickRandomArc();
	bool getFirstState();

private:

	std::vector<GeneralArc*> vectorOfArcs_;
	bool firstState_;
};
