#include <stdio.h>

#define MOD 1000000007

int rearrangeSticks(int n, int k) {
    int dp[n+1][k+1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 0;

    dp[0][0] = 1; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j-1];

            dp[i][j] = (dp[i][j] + (long long)(i-1) * dp[i-1][j]) % MOD;
        }
    }

    return dp[n][k];
}
