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
        dp[i][0] = 1;//ȡ0Ԫ�ǿ��Եġ�//��ʼ���Ĺ��� 
    }
    for (i = 1; i <= n; i++)//[i, j]��ʾ��ǰi��Ӳ���������jԪ��������� 
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