#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *mainfunc(void* arg)
{
    for(auto i=0; i<5;i++)
    {
	sleep(1);
	cout<<"i:"<<i<<endl;
    }
    return 0;
}

int main()
{
    pthread_t pthid = 0;    //typedef unsigned long int pthread_t
    
    if(pthread_create(&pthid, NULL, mainfunc, NULL) != 0)
    {
	cout<<"thread create failed"<<endl;
    }
    cout<<"pthid:"<<pthid<<endl;
    pthread_join(pthid, NULL);
    return 0;
}

