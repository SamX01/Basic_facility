#include "Tracer_v1.h"

bool Tracer_v1::traceIsActive = false;
;
void Tracer_v1::debug(const string &msg) {
	if (this->traceIsActive) {
		cout << msg << endl;
	}
}

Tracer_v1::Tracer_v1(const string& name) :
	theFunctionName(name)
{
	if (this->traceIsActive) {
		cout << "Enter function name: " << name << endl;
	}
}
Tracer_v1::Tracer_v1(const char* name):
	theFunctionName(name)
{
	if (this->traceIsActive) {
		cout << "Enter function name: " << name << endl;
	}
}
Tracer_v1::~Tracer_v1()
{
	if (this->traceIsActive) {
		cout << "Exit Funtcion" << theFunctionName << endl;
	}
}
