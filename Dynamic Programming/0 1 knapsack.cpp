///Masum
// 0/1 Knapsack
#include <bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int value[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (j < weight[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
                }
            }
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n, capacity;
    cin >> n >> capacity;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout << knapsack(weight, value, n, capacity);
}

