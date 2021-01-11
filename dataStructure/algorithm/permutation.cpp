/*
 * @Author: chenq
 * @Date: 2020-11-18 17:30:15
 * @LastEditTime: 2020-11-19 10:21:56
 * @Descripttion: 全排列
 */
#include <iostream>
#include <cstring>
using namespace std;

void permutation(char* str, int begin, int end)
{
    if(begin == end)
    {
        static int i=1;
        cout<<i++<<". "<<str<<endl;
    }
    else if(begin > end)
    {
        return;
    }
    else
    {
        for(int j=begin;j<=end;j++)
        {
            swap(str[j], str[begin]);
            permutation(str, begin+1, end);
            swap(str[j], str[begin]);
        }
    }
}

// abcd的全排列A44 = 4*3*2*1 = 24
// abcd abdc a
// acbd adcb
// abcd

int main()
{
    char str[] = "abcd";
    permutation(str, 0, 3);

    return 0;
}