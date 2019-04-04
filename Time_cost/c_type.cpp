#include<ctime>
#include<iostream>

using namespace std;

#define TIME_COUNT_START auto start = clock(); 
#define TIME_COUNT_END auto end = clock();
#define TIME_COST 	auto duration = end-start;\
cout << "»¨·ÑÁË"\
<< duration \
<< "Ãë" << endl;