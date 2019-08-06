#pragma once
#include "Includes.hpp"
class Storage;
class Controller;
class GeneralArc;
class GeneralState;

struct TestObject {
public:
	GeneralArc *arc = nullptr;
	Storage *storage = nullptr;
};


class Test {
public:
	Test();
	~Test();
	
	bool isTestTrue(TestObject arcObject, TestObject storageObject);

	bool arcPOP(TestObject arcObject, TestObject storageObject);
	bool arcPUSH(TestObject arcObject, TestObject storageObject);
	bool arcJUMP(TestObject arcObject, TestObject storageObject);
	bool arcWRD(TestObject arcObject, TestObject storageObject);

private:

	bool arcStatusBool_;

	Controller *controller_;

	GeneralArc *arc_;

};
