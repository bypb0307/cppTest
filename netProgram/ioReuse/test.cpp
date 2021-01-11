#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    
    cout<<"sizeof buf:"<<sizeof(buf)<<endl;
    return 0;
}
