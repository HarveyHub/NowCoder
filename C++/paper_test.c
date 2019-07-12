#include "stdio.h"

union{
    int i;
    char x[2];
}a;

void test1()
{
    a.x[0] = 10;
    a.x[1] = 1;
    printf("test1: %d\n", a.i);
}

int foo(int x, int y)
{
    if(x <= 0 || y <= 0)
        return 1;
    return 3*foo(x-1, y/2);
}

void test2()
{
    printf("test2: %d\n", foo(3, 5));
}

void test3()
{
    // int a[10]; a = a + 1;
    // const int a[] = {1, 2, 3, 4, 5}; int b[a[2]];


}

void test4()
{
    int count = 0;
    int x = 999;
    while(x)
    {
        count ++;
        x = x & (x-1);
    }
    printf("test4: %d\n", count);
}

#define MAX 255
void test5()
{
    unsigned char A[MAX+1], i;
    for(i = 0; i <= MAX; i++)
    {
        A[i] = i;
    }
    printf("test5: %d\n", A[0]);
}

struct s1
{
    int i:8;
    int j:4;
    int a:3;
    double b;
};

struct s2
{
    int i:8;
    int j:4;
    double b;
    int a:3;
};


void test9()
{
    printf("test9: %d %d \n", sizeof(struct s1), sizeof(struct s2));
}

void copystring(char* dest, char* source)
{
    while(*source != NULL){
        *dest = *source;
        dest++;
        source++;
    }
   
}

void test10()
{
    char input[10] = "hello";
    char* dest;
    dest = &input[1];
    copystring(dest, input);
    printf("test10: %s\n", input);
}
static int array[1000];
int findN(int n)
{
    int  i = 0;
    while(array[i] != n)
    {
        if(array[i] < n)
            i++;
        if(array[i] > n)
            return 0;
        

    }
    return 1;
    
}


int f()
{
    return 1;
}

int g()
{
    return f()>1?0:1;
}

int sol()
{
    int v = f()+g();
    if(v==0)
        return 0;
    else if(v==2)
        return 1;
    else
        sol();
    
}

int main()
{
    printf("%s\n", "hello world");
    test1();
    test2();
    test4();
    // test5();
    test9();
    // test10();
    return 0;
}