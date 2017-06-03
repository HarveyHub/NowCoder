#include <pthread.h>  
#include <unistd.h>  
#include <stdio.h>  
#include <windows.h>
#include <iostream>

using namespace std;
void *thread(void *str)  
{  
    int i;  
    for (i = 0; i < 10; ++i)  
    {  
        Sleep(2);  
        printf( "This in the thread : %d\n" , i );  
    }  
    return NULL;  
}  
  
int main()  
{  
    pthread_t pth;  
    int i =0;  
    int ret = pthread_create(&pth, NULL, thread, (void *)(i));  
    cout << ret << endl;  
    pthread_join(pth, NULL);  
    for (i = 0; i < 10; ++i)  
    {  
        Sleep(1);  
        printf( "This in the main : %d\n" , i );  
    }  
      
    return 0;  
} 