#include "Includes.hpp"
#include "Controller.hpp"


Controller ContATN;

int main(int argc, char** argv) {

	char i;
	
	for (int i = 0; i < 20; i++) {
		ContATN.runATN();
	}
	ContATN.printout();
	std::cin >> i;

	return 0;
}

