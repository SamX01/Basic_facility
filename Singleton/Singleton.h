#pragma once
#include<mutex>
using namespace std;
class Singleton
{
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* getInstance_s();
	
	static Singleton* m_instance;
	static mutex m_mutex;
};

Singleton* Singleton::m_instance = nullptr;

