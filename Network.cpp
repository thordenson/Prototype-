#include "Network.hpp"

Network::Network() {

	state1_ = new GeneralState(true);
	state2_ = new GeneralState(false);
	state3_ = new GeneralState(false);
	state4_ = new GeneralState(false);
	state5_ = new GeneralState(false);
	state6_ = new GeneralState(false);
	state7_ = new GeneralState(false);
	state8_ = new GeneralState(false);
	state9_ = new GeneralState(false);
											   //current       arcType         arcAction next
	state1VectorofArcs_.push_back(new GeneralArc(state1_, GeneralArc::ARCS::WRD, "Once upon a time,", state2_));							
	state1VectorofArcs_.push_back(new GeneralArc(state1_, GeneralArc::ARCS::WRD, "A long time ago,", state2_));								
	state1VectorofArcs_.push_back(new GeneralArc(state1_, GeneralArc::ARCS::WRD, "There once was a time when", state2_));					
	state1VectorofArcs_.push_back(new GeneralArc(state1_, GeneralArc::ARCS::WRD, "In a faraway place,", state2_));							
																																			
												//previous current       arcType          arcAction next									
	state2VectorofArcs_.push_back(new GeneralArc(state1_, state2_, GeneralArc::ARCS::WRD, "a great evil", state3_));						
	state2VectorofArcs_.push_back(new GeneralArc(state1_, state2_, GeneralArc::ARCS::WRD, "a magical forest", state3_));					
	state2VectorofArcs_.push_back(new GeneralArc(state1_, state2_, GeneralArc::ARCS::WRD, "a fantastical beast", state3_));					
	state2VectorofArcs_.push_back(new GeneralArc(state1_, state2_, GeneralArc::ARCS::WRD, "a conflict", state3_));							
	state2VectorofArcs_.push_back(new GeneralArc(state1_, state2_, GeneralArc::ARCS::WRD, "a magical artifact", state3_));		
																 
												//previous current       arcType          arcAction next									
	state3VectorofArcs_.push_back(new GeneralArc(state2_, state3_, GeneralArc::ARCS::WRD, "appeared,", state4_));							
	state3VectorofArcs_.push_back(new GeneralArc(state2_, state3_, GeneralArc::ARCS::WRD, "originated,", state4_));							
	state3VectorofArcs_.push_back(new GeneralArc(state2_, state3_, GeneralArc::ARCS::WRD, "emerged,", state4_));							
	state3VectorofArcs_.push_back(new GeneralArc(state2_, state3_, GeneralArc::ARCS::WRD, "transpired,", state4_));							
																																			
												 //previous current       arcType          arcAction next									
	state4VectorofArcs_.push_back(new GeneralArc(state3_, state4_, GeneralArc::ARCS::WRD, "with great power to", state5_));					
	state4VectorofArcs_.push_back(new GeneralArc(state3_, state4_, GeneralArc::ARCS::WRD, "arising out of", state5_));						
	state4VectorofArcs_.push_back(new GeneralArc(state3_, state4_, GeneralArc::ARCS::WRD, "for the reason that", state5_));					
	state4VectorofArcs_.push_back(new GeneralArc(state3_, state4_, GeneralArc::ARCS::WRD, "as a result of", state5_));						
	state4VectorofArcs_.push_back(new GeneralArc(state3_, state4_, GeneralArc::ARCS::WRD, "a great evil", state5_));										
																			
												 //previous current       arcType          arcAction next									
	state5VectorofArcs_.push_back(new GeneralArc(state4_, state5_, GeneralArc::ARCS::WRD, "conquer the entire world.", state6_));			
	state5VectorofArcs_.push_back(new GeneralArc(state4_, state5_, GeneralArc::ARCS::WRD, "a magical artifact", state6_));					
	state5VectorofArcs_.push_back(new GeneralArc(state4_, state5_, GeneralArc::ARCS::WRD, "monsters", state6_));							
	state5VectorofArcs_.push_back(new GeneralArc(state4_, state5_, GeneralArc::ARCS::WRD, "as a result of", state6_));						
	state5VectorofArcs_.push_back(new GeneralArc(state4_, state5_, GeneralArc::ARCS::WRD, "a conflict", state6_));				
																																
												//previous current       arcType          arcAction next									
	state6VectorofArcs_.push_back(new GeneralArc(state5_, state6_, GeneralArc::ARCS::WRD, "with an iron fist,", state7_));					
	state6VectorofArcs_.push_back(new GeneralArc(state5_, state6_, GeneralArc::ARCS::WRD, "hunted by", state7_));							
	state6VectorofArcs_.push_back(new GeneralArc(state5_, state6_, GeneralArc::ARCS::WRD, "the creature hunted", state7_));					
	state6VectorofArcs_.push_back(new GeneralArc(state5_, state6_, GeneralArc::ARCS::WRD, "monsters", state7_));							
																																			
												//previous current       arcType          arcAction next									
	state7VectorofArcs_.push_back(new GeneralArc(state6_, state7_, GeneralArc::ARCS::WRD, "magical creatures", state8_));					
	state7VectorofArcs_.push_back(new GeneralArc(state6_, state7_, GeneralArc::ARCS::WRD, "controlled by humans", state8_));				
	state7VectorofArcs_.push_back(new GeneralArc(state6_, state7_, GeneralArc::ARCS::WRD, "everyone and everything", state8_));				
	state7VectorofArcs_.push_back(new GeneralArc(state6_, state7_, GeneralArc::ARCS::WRD, "hunted by", state8_));							
																																			
												//previous current       arcType          arcAction next									
	state8VectorofArcs_.push_back(new GeneralArc(state7_, state8_, GeneralArc::ARCS::WRD, "was defeated", state9_));						
	state8VectorofArcs_.push_back(new GeneralArc(state7_, state8_, GeneralArc::ARCS::WRD, "for food", state9_));							
	state8VectorofArcs_.push_back(new GeneralArc(state7_, state8_, GeneralArc::ARCS::WRD, "to annihilation", state9_));						
	state8VectorofArcs_.push_back(new GeneralArc(state7_, state8_, GeneralArc::ARCS::WRD, "heroes", state9_));		

										       //previous current       arcType          
	state9VectorofArcs_.push_back(new GeneralArc(state8_, state9_, GeneralArc::ARCS::POP));

	state1_->setVectorOfArcs(state1VectorofArcs_);
	state2_->setVectorOfArcs(state2VectorofArcs_);
	state3_->setVectorOfArcs(state3VectorofArcs_);
	state4_->setVectorOfArcs(state4VectorofArcs_);
	state5_->setVectorOfArcs(state5VectorofArcs_);
	state6_->setVectorOfArcs(state6VectorofArcs_);
	state7_->setVectorOfArcs(state7VectorofArcs_);
	state8_->setVectorOfArcs(state8VectorofArcs_);
	state9_->setVectorOfArcs(state9VectorofArcs_);
}

Network::~Network() {
}


GeneralState *Network::getState1() {
	return state1_;
}