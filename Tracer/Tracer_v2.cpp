#include "Tracer_v2.h"

//use char* to replace string
bool Tracer_v2::traceIsActive = false;

Tracer_v2::Tracer_v2(const char* name) 
	:theFunctionName(name)
{
	if (this->traceIsActive) {
		cout << "Enter function name: " << name << endl;
	}
}
void Tracer_v2::debug(const char* msg) {
	if (this->traceIsActive) {
		cout << msg << endl;
	}
}

Tracer_v2::~Tracer_v2() {
	if (this->traceIsActive) {
		cout << "Exit Funtcion" << theFunctionName << endl;
	}
}



