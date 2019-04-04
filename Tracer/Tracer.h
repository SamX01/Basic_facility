#pragma once
#include<string>
#include<iostream>
using namespace std;
class Tracer
{
public:
	//current final edition
	Tracer(const char* name);
	void debug(const char* msg);
	static bool traceIsActive;
	~Tracer();
private:
	string * theFunctionName;
};

