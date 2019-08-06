#pragma once
#include "Includes.hpp"
#include "GeneralState.hpp"
#include "GeneralArc.hpp"
class Storage {
public:
	Storage();
	~Storage();

	void getString();
	std::vector<GeneralState*> getPath();
	void setPath(GeneralState *state);
	void clearFalseState();
	void clearPath();


	std::vector<std::string> getSentence();

private:
	std::vector<GeneralState*> storing_;
	std::vector<std::string> sentence_;


};
