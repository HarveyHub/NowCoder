#include <stdio.h>
#include <stdlib.h>
#ifdef 	_WIN32
	#include <windows.h>
#else
	#include <unistd.h>
	#include <time.h>
#endif
double getCurrentTimeStamp()
{
	double current;
	#ifdef _WIN32
	static LARGE_INTEGER fre = {};
	LARGE_INTEGER cur_clock;
	if(0 == fre.QuadPart)
		QueryPerformanceFrequency(&fre);
	QueryPerformanceCounter(&cur_clock);
	current = (double)cur_clock.QuadPart / (double)fre.QuadPart;
	#else
		struct timespec ts;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		current = (double)ts.tv_nsec * 10e-9 + (double)ts.tv_sec;
	#endif
	return current;
}
// int main()
// {
	// double start, end;
	// start = getCurrentTimeStamp();
	// int sum = 0, i;
	// for(i = 0; i < 10000000; i++)
	// {
		// sum += i;
	// }
	// end = getCurrentTimeStamp();
	// printf("time %f seconds\n", end - start);
	// return 0;
// }