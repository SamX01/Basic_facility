#include"Tracer_v1.h"
#include"Tracer_v2.h"
#include"Tracer_v3.h"

#include<chrono>
#include<string>
#include<iostream>

using namespace std;
using namespace chrono;

#define TIME_COUNT_START auto start = chrono::steady_clock::now(); 
#define TIME_COUNT_END auto end = chrono::steady_clock::now();
#define TIME_COST 	auto duration = duration_cast<microseconds>(end - start);\
cout << "花费了"\
<< double(duration.count()) * microseconds::period::num / microseconds::period::den\
<< "秒" << endl;
int add_one(int x) {
	return x + 1;
}

int add_one_trace_v1_off(int x) {
	string name("add_one_trace_v1");
	Tracer_v1 t(name);
	t.debug(name);

	return x + 1;
}

int add_one_trace_v2_off(int x) {
	const char* name = "add_one_trace_v2";
	Tracer_v2 t(name);

	return x + 1;
}

int add_one_trace_v3_off(int x) {
	const char* name = "add_one_trace_v3";
	Tracer_v3 t(name);
	return x + 1;
}

void multiscale_test() {
	cout << "Origin edition ";
	//auto start = chrono::steady_clock::now();
	TIME_COUNT_START;
	for (int i = 0; i < 100000; ++i) {
		add_one(3);
	}
	TIME_COUNT_END;
	TIME_COST;

	cout << "Tracer-off edition ";
	start = chrono::steady_clock::now();
	for (int i = 0; i < 100000; ++i) {
		add_one_trace_v1_off(3);
	}
	end = chrono::steady_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;

	cout << "Tracer-off edition 2 ";
	start = chrono::steady_clock::now();
	for (int i = 0; i < 100000; ++i) {
		add_one_trace_v2_off(3);
	}
	end = chrono::steady_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;

	cout << "Tracer-off edition 3 ";
	start = chrono::steady_clock::now();
	for (int i = 0; i < 100000; ++i) {
		add_one_trace_v3_off(3);
	}
	end = chrono::steady_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;
}

void sig_test() {
	Tracer_v1::traceIsActive = true;
	Tracer_v2::traceIsActive = true;
	Tracer_v3::traceIsActive = true;
	cout << "Origin edition " << endl;
	auto start = chrono::steady_clock::now();
	add_one(3);
	auto end = chrono::steady_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;

	cout << "Tracer-off edition " << endl;
	start = chrono::steady_clock::now();
	add_one_trace_v1_off(3);
	end = chrono::steady_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;

	cout << "Tracer-off edition 2 " << endl;
	start = chrono::steady_clock::now();
	add_one_trace_v2_off(3);
	end = chrono::steady_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;

	cout << "Tracer-off edition 3 " << endl;
	start = chrono::steady_clock::now();
	add_one_trace_v3_off(3);
	end = chrono::steady_clock::now();
	duration = duration_cast<microseconds>(end - start);
	cout << "花费了"
		<< double(duration.count()) * microseconds::period::num / microseconds::period::den
		<< "秒" << endl;
}

int main(int argc,char* argv[]){
	multiscale_test();
	sig_test();

	return 0;
}