#pragma once
#ifndef _TRACER_H_
#define _TRACER_H_

#include<string>
#include<iostream>
using namespace std;
class Tracer_v1
{
public:
	Tracer_v1(const string &name);
	Tracer_v1(const char* name);
	void debug(const string &msg);
	static bool traceIsActive;
	~Tracer_v1();
private:
	string theFunctionName;
};


#endif // !_TRACER_H_