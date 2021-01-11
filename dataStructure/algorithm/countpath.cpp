/*
 * @Author: chenq
 * @Date: 2020-11-26 23:19:28
 * @LastEditTime: 2020-12-08 22:12:09
 * @Descripttion: 计算路径，每次只能往右或者往下走一步，从左上角到达右下角有多少种走法
 */
#include <iostream>
#include <iomanip>
using namespace std;

void countpath(int i, int j)
{
    int dp[i][j] = {0};
    for(int x=0;x<i;x++)
        dp[x][0]=1;
    for(int y=0;y<j;y++)
        dp[0][y]=1;
    for(int x =1;x<i;x++)
        for(int y=1;y<j;y++)
        dp[x][y]=dp[x-1][y] + dp[x][y-1];
    for(int x =0;x<i;x++)
    {
        for(int y=0;y<j;y++)
        {
            cout<<"("<<x<<", "<<y<<"):"<<setw(2)<<dp[x][y]<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    countpath(3, 7);
}