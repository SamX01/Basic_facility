#include "Tracer_v3.h"

bool Tracer_v3::traceIsActive = false;

Tracer_v3::Tracer_v3(const char* func_name) :
	theFunctionName(nullptr) {
	if (traceIsActive) {
		cout << "Enter function" << endl;
		theFunctionName = new string(func_name);
	}
}

void Tracer_v3::debug(const char* msg) {
	if (this->traceIsActive) {
		cout << msg << endl;
	}
}

Tracer_v3::~Tracer_v3() {
	if (traceIsActive) {
		cout << "Exit function" << *theFunctionName << endl;
		delete theFunctionName;
	}
}
