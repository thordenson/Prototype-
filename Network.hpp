#pragma once
#include "Includes.hpp"
#include "GeneralArc.hpp"
#include "GeneralState.hpp"

class Network {
public:
	Network();
	~Network();


	GeneralState *getState1();


private:

	GeneralState *state1_, *state2_, *state3_, *state4_, *state5_, *state6_, *state7_, *state8_, *state9_;

	std::vector<GeneralArc*> state1VectorofArcs_, state2VectorofArcs_, state3VectorofArcs_, state4VectorofArcs_,
							 state5VectorofArcs_, state6VectorofArcs_, state7VectorofArcs_, state8VectorofArcs_, state9VectorofArcs_;


};