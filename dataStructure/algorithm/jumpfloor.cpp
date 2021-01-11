/*
 * @Author: chenq
 * @Date: 2020-11-29 21:53:37
 * @LastEditTime: 2020-12-08 22:16:37
 * @Descripttion: 输入台阶的级数，输出一种有多少种跳法，每次可以跳1级或者两级
 */
#include <iostream>
using namespace std;

//输入台阶的级数，输出一种有多少种跳法，每次可以跳1级或者两级
int jump_floor1(int n)
{
    if (n < 1) return -1;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else //跳1级还有n-1级要跳，跳2级还有n-2级要跳
        return jump_floor1(n - 1) + jump_floor1(n - 2);
}

int jump_floor2(int n)
{
    if (n < 1) return -1;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else
    {
        int a = 1; //1级台阶总共的跳法
        int b = 2; //2级台阶总共的的跳法
        int t;
        for (int i = 3; i <= n; i++)
        {
            t = a;
            a = b;
            b = a + t;
        }
        return b;
    }
}

int main()
{
    int n;
    cout << "please input the nums of floor:";
    cin >> n;
    int count1 = jump_floor1(n);
    int count2 = jump_floor2(n);
    cout << "jump_floor1 count = " << count1 << endl;
    cout << "jump_floor2 count = " << count2 << endl;
}