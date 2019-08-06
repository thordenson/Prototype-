#include "Storage.hpp"

Storage::Storage() {
}

Storage::~Storage() {
}


void Storage::getString() {

	std::string result;
	//goes through the size of the path
	for (int i = 0; i < this->getPath().size(); i++) {
		//gets current state
		auto arcVector = this->getPath()[i]->getVectorOfArcs();
		//goes through all the arcs on that state
		for (int j = 0; j < arcVector.size(); j++) {
			//checks if any arc has status "true"
			if (arcVector[j]->getArcStatus() == "true") {
				auto string = arcVector[j]->getArcAction();
				//adds arc's action to result
				result += string;
				result += " ";
			}
			//clear the arc's status
			arcVector[j]->setArcStatus("");
		}
	}
	//clears the vector
	this->clearPath();

	//is used to push the result on to a vector of sentences
	//and to check if any of the sentence are equal
	//if the sentence is empty then push on
	if (sentence_.empty()) {
		sentence_.push_back(result);
	}
	
	bool equalSentence = false;
	//goes through the size of the vector of sentences
	for (int k = 0; k < this->getSentence().size(); k++) {
		//if any sentence in the vector of sentences are equal to the result
		//then that the result sentence should not be added to the vector of sentences
		if (sentence_[k] == result) {
			equalSentence = true;
		}
	}
	//if result is not equal to any sentence in vector of sentences then
	//add result to vector
	if (equalSentence == false){
		sentence_.push_back(result);
	}
}

void Storage::clearPath() {
	storing_.clear();
}

std::vector<std::string> Storage::getSentence(){
	return sentence_;
}

std::vector<GeneralState*> Storage::getPath() {
	return storing_;
}

void Storage::setPath(GeneralState *state) {
	storing_.push_back(state);
}

void Storage::clearFalseState() {
	storing_.pop_back();
}
