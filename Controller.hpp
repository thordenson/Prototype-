#pragma once
#include "Includes.hpp"
#include "Network.hpp"
#include "Storage.hpp"

class Controller {
public:
	Controller();
	~Controller();

	void runATN();
	void printout();

	Storage *getStorage();

private:

	Network *network_;
	Storage *storage_;
	GeneralState *state_;
	GeneralArc *arc_;

	std::vector<GeneralState> vecState_;
};
