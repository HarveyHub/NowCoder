#include<iostream>
#include<sstream>
#include<pthread.h>
#include<sched.h>
#include<unistd.h>
#include "timer.h"
using namespace std;

int g_int = 0;
pthread_mutex_t mutex;
// int signal = 0;
void *test_time(void*)
{
	double start, end;
	start = getCurrentTimeStamp();
	if(pthread_self() % 3 == 0)
		usleep(1000);
	usleep(3000);
	end = getCurrentTimeStamp();
	pthread_mutex_lock(&mutex);
	cout << pthread_self() <<"\t" << (end - start)*1e6 << " us" << endl;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *sub(void *)
{
	g_int --;
	cout << "in sub " << g_int << endl;
	return NULL;
}

void *add(void *)
{
	g_int ++;
	cout << "in add " << g_int << endl;
	return NULL;
}

template <typename T>
void str2val(const string &str, T &val)
{
	stringstream ss;
	ss << str;
	ss >> val;
}
template <typename T>
void val2string(const T &val, string &str)
{
	stringstream ss;
	ss << val;
	str = ss.str();
}

int main(int argc, char* argv[])
{
	int thread_cnt = 10;
	pthread_mutex_init(&mutex, NULL);
	if(argc > 1)
	{
		str2val(argv[1], thread_cnt);
		cout << "thread_cnt: " << thread_cnt << endl;
	}
		
	pthread_t *threads_add = new pthread_t[thread_cnt];
	pthread_t *threads_sub = new pthread_t[thread_cnt];
	
	for(int i = 0; i < thread_cnt; i++)
	{
		if(0 != pthread_create(&threads_add[i], NULL, add, NULL))
		{
			cerr << "pthread add[" << i << "] create error!" << endl;
			
		}
		if(0 != pthread_create(&threads_sub[i], NULL, test_time, NULL))
		{
			cerr << "pthread sub[" << i << "] create error!" << endl;
			
		}
	}
	for(int i = 0; i < thread_cnt; i++)
	{
		pthread_join(threads_add[i], NULL);
		pthread_join(threads_sub[i], NULL);
	}
	
	cout << "g_int " << g_int << endl;
	// string result;
	// val2string(3.1415926, result);
	// cout << result << endl;
	
}