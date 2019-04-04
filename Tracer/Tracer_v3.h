#pragma once
#ifndef _TRACERV3_H_
#define _TRACERV3_H_

//use string* to replace string

#include<string>
#include<iostream>
using namespace std;
class Tracer_v3
{
public:
	//Tracer(const string &name);
	Tracer_v3(const char* name);
	void debug(const char* msg);
	static bool traceIsActive;
	~Tracer_v3();
private:
	string* theFunctionName;
};



#endif // !_TRACERV3_H_



