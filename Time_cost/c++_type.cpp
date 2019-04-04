#include<chrono>
#include<iostream>

using namespace std;
using namespace chrono;

#define TIME_COUNT_START auto start = chrono::steady_clock::now(); 
#define TIME_COUNT_END auto end = chrono::steady_clock::now();
#define TIME_COST 	auto duration = duration_cast<microseconds>(end - start);\
cout << "花费了"\
<< double(duration.count()) * microseconds::period::num / microseconds::period::den\
<< "秒" << endl;

//用法示例
/*
TIME_COUNT_START;
for (int i = 0; i < 100000; ++i) {
	add_one(3);
}
TIME_COUNT_END;
TIME_COST;
*/