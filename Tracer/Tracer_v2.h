#pragma once
#ifndef _TRACERV2_H_
#define _TRACERV2_H_

#include<string>
#include<iostream>
using namespace std;
class Tracer_v2
{
public:
	Tracer_v2(const char* name);
	void debug(const char* msg);
	static bool traceIsActive;
	~Tracer_v2();
private:
	string theFunctionName;
};

#endif