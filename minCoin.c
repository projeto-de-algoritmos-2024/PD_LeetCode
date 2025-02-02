#include <stdio.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int minimumCoins(int* prices, int pricesSize) {
    int dp[pricesSize];  
    
    for (int i = 0; i < pricesSize; i++)
        dp[i] = INT_MAX;

    dp[0] = prices[0];  

    for (int i = 1; i < pricesSize; i++) {
        dp[i] = dp[i - 1] + prices[i];

        for (int j = 0; j < i; j++) {
            if (i + j < pricesSize) {
                dp[i + j] = min(dp[i + j], (i > 0 ? dp[i - 1] : 0) + prices[i]);
            }
        }
    }

    return dp[pricesSize - 1];  
}

