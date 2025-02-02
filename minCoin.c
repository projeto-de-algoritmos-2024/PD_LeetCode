#include <stdio.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int minimumCoins(int* prices, int pricesSize) {
    int n = pricesSize;
    int current[n + 1]; 

    current[0] = 0;
    current[1] = prices[0];

    for (int i = 2; i <= n; i++) {
        current[i] = current[i - 1] + prices[i - 1];
        for (int j = i - 1; j > 0; j--) {
            if (2 * j < i) {
                break;
            }
            current[i] = min(current[i], current[j - 1] + prices[j - 1]);
        }
    }

    return current[n];  
}
