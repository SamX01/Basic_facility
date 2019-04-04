#include "Tracer.h"


bool Tracer::traceIsActive = false;

Tracer::Tracer(const char* func_name) :
	theFunctionName(nullptr) {
	if (traceIsActive) {
		cout << "Enter function" << endl;
		theFunctionName = new string(func_name);
	}
}

void Tracer::debug(const char* msg) {
	if (this->traceIsActive) {
		cout << msg << endl;
	}
}

inline
Tracer::~Tracer() {
	if (traceIsActive) {
		cout << "Exit function" << *theFunctionName << endl;
		delete theFunctionName;
	}
}
