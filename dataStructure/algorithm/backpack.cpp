/*
 * @Author: chenq
 * @Date: 2020-11-29 22:33:06
 * @LastEditTime: 2020-12-08 22:10:39
 * @Descripttion: 动态规划背包问题
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//v 物品价值的数组
//w 物品重量的数组
//n 物品个数
//c 背包容量
int backpack(int *v, int *w, int n, int c)
{
    //初始化物品下标从0到n-1,背包容量从0到c，计算得到一个n*(c+1)二维数组
    int m[n][c+1]; //m[0][0]表示有一个物品可选，并且背包容量为0时的最大价值
    memset(m, 0, sizeof(m));
    for(int i = 0;i<=c;i++) //只有一个物品时是需要考虑物品重量跟背包的容量
    {
        if(w[0] <= i)
        {
            m[0][i] = v[0];
        }
    }
    for(int i = 1;i < n;i++) //循环计算二维数组
    {
        for(int j = 0;j<=c;j++)
        {
            if(w[i] > j)    //物品重量大于背包容量装不下
            {
                m[i][j] = m[i-1][j];
            }
            else
            {
                m[i][j] = max(m[i-1][j], m[i-1][j - w[i]] + v[i]);
            }
        }
    }
    //打印二维数组
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<c;j++)
        {
            cout<<setw(2)<<m[i][j]<<"  ";
        }
        cout<<endl;
    }
    //计算背包容量为c时，所装物品的最大价值
    int total_value = 0;
    for(int i =0;i<n;i++)
    {
        if(m[i][c] > total_value)
        {
            total_value = m[i][c];
        }
    }
    return total_value;
}

int main()
{
    int v[] = {6, 3, 5, 4, 6}; //物品价值
    int w[] = {2, 2, 6, 5, 4}; //物品重量
    int n = 5;  //物品数量
    int c = 7; //背包容量
    int m = backpack(v, w, n, c); //背包容量为c时所装物品的最大价值
    cout<<"c="<<c<<", max m="<<m<<endl;
}