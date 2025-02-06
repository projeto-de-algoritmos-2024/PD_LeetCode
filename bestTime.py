class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lucro = 0
        for i in range(len(prices) - 1):
            if(prices[i] > prices[i + 1]):
               lucro += prices[i] - prices[i + 1]
               return lucro
            elif(prices[i+1] > prices[i]):
                lucro += prices[i+1] - prices[i]
            return lucro 
