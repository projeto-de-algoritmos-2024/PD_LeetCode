#include <stdio.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int minimumCoins(int* prices, int pricesSize) {
    int dp[pricesSize + 1];

    for (int i = 0; i <= pricesSize; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0; 

    for (int i = 1; i <= pricesSize; i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i] = min(dp[i], dp[j] + prices[j]);
        }
    }

    return dp[pricesSize];  
}

