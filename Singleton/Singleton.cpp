#include "Singleton.h"
#include<mutex>
#include<atomic>
#include<thread>
using namespace std;

/*
//非线程安全版本
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr)
		m_instance = new Singleton();
	else
		;
	return m_instance;
}
*/

//TODO
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;
//线程安全版本
Singleton* Singleton::getInstance_s() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::_Atomic_thread_fence(std::memory_order_acquire);
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release);
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}

