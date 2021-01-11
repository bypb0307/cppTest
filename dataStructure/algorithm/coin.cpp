/*
 * @Author: chenq
 * @Date: 2020-11-30 10:35:52
 * @LastEditTime: 2020-12-08 22:10:57
 * @Descripttion:动态规划硬币问题
 */
#include <iostream>
#include <iomanip>
using namespace std;

//有n种面值的硬币，硬币面值分别为n1, n2, n3...元，要凑出指定的额度，所需的最少数量的硬币
//t 指定额度，conis 硬币数组，n 硬币面值的种数
int minCoins(int t, int *coins, int n)
{
    //初始化，数组f[t]表示凑出面值t的硬币所需的最少硬币数
    int f[t + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        f[coins[i]] = 1;
    }

    int minCoins = coins[0];
    for (int i = minCoins + 1; i <= t; i++)
    {
        for (int j = 0; j < n && coins[j] <= i; j++)
        {
            if (f[i - coins[j]] == 0)
                continue;
            if (f[i] == 0)
            {
                f[i] = f[i - coins[j]] + 1;
            }
            else
            {
                f[i] = min(f[i - coins[j]] + 1, f[i]);
            }
        }
    }

    for (int i = 0; i <= t; i++)
    {
        cout << setw(2) << i << " : " << setw(2) << f[i] << endl;
    }
    return f[t];
}

int main()
{
    int coins[] = {3, 4, 10, 20};
    int nums = minCoins(30, coins, 4);
    cout << "\nnums:" << nums << endl;
}
