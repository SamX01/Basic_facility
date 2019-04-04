#include<chrono>
#include<iostream>

using namespace std;
using namespace chrono;

#define TIME_COUNT_START auto start = chrono::steady_clock::now(); 
#define TIME_COUNT_END auto end = chrono::steady_clock::now();
#define TIME_COST 	auto duration = duration_cast<microseconds>(end - start);\
cout << "������"\
<< double(duration.count()) * microseconds::period::num / microseconds::period::den\
<< "��" << endl;

//�÷�ʾ��
/*
TIME_COUNT_START;
for (int i = 0; i < 100000; ++i) {
	add_one(3);
}
TIME_COUNT_END;
TIME_COST;
*/