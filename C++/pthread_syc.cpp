#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define MAX_THREAD_CNT 20

vector<double> v_start(MAX_THREAD_CNT,0), v_end(MAX_THREAD_CNT, 0);

void * deploy_task(void* arg)
{
	return NULL;
}

int thread_generator(unsigned thread_cnt)
{
	// 亲和性设置
	
	// 创建线程
	
	// 设置同步
	
	// 等待线程结束	
	return 0;
}

int main()
{
}