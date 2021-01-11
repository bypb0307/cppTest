#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

void t1thread()
{
	cout<<"this is t1 thread"<<endl;
}

void t2thread()
{
	cout<<"this is t2 thread"<<endl;
	ofstream f("./test.txt");
	f<<"hello thread t2";
	f.close();
}

int main()
{
	cout<<"start main"<<endl;
	
	thread t1(t1thread);
	thread t2(t2thread);
	
	t1.join();
	t2.join();
	
	cout<<"bye main"<<endl;
	return 0;
}