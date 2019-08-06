#include "GeneralState.hpp"
#include "GeneralArc.hpp"

GeneralState::GeneralState(){
}

GeneralState::GeneralState(bool firstState) {
	srand(time(0));
	firstState_ = firstState;
}

GeneralState::~GeneralState() {
}

void GeneralState::setVectorOfArcs(std::vector<GeneralArc*> arcs) {
	vectorOfArcs_ = arcs;
}

std::vector<GeneralArc*> GeneralState::getVectorOfArcs() {
	return vectorOfArcs_;
}

GeneralArc *GeneralState::pickRandomArc() {

	int k = rand() % vectorOfArcs_.size();
	auto getArcStatus = vectorOfArcs_[k]->getArcStatus();
	
	//if the chosen arc has no status return it
	if (getArcStatus.empty()) {
		return vectorOfArcs_[k];
	}
	else {
		//a check to see if an arc chosen has the status "false"
		//if so chose a new one until something other then
		//"false" is chosen
		while (getArcStatus == "false") {
			k = rand() % vectorOfArcs_.size();
			getArcStatus = vectorOfArcs_[k]->getArcStatus();

		}
		//if an arc with status "onHold" is picked
		if (getArcStatus == "onHold") {
			//then check if any arc on the current state has status "true"
			for (int i = 0; i < vectorOfArcs_.size(); i++) {
				//if yes then set that arc's status to "false"
				if (vectorOfArcs_[i]->getArcStatus() == "true") {
					vectorOfArcs_[i]->setArcStatus("false");
				}
			}
			//after that return the arc with status "onHold"
			return vectorOfArcs_[k];
		}
		//if an arc with status "true" is picked just return that value to
		//the controller class, there it will be set to "false"
		else {
			return vectorOfArcs_[k];
		}
	}
}

bool GeneralState::getFirstState(){
	return firstState_;
}


