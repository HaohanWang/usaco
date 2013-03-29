/*
ID: haohanw1
LANG: C
TASK: money
*/
#include<stdio.h>
long long dp[26][10001];
int main()
{
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int i, j, n, m, s[26];
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }
    for (i = 1; i <= n; i++)
    {
        dp[i][0] = 1;//取0元是可以的。//初始化的过程 
    }
    for (i = 1; i <= n; i++)//[i, j]表示在前i种硬币种能组成j元的情况个数 
    {
        for (j = 1; j <= m; j++)
        {
            if (j - s[i] >= 0)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-s[i]];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%lld\n", dp[n][m]);
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}