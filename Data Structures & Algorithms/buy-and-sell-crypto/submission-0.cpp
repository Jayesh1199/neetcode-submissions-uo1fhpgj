#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Initialize to a very high value (or the first element)
        int min_price = 1e9; 
        int max_profit = 0;
        
        for (int price : prices) {
            // Update the lowest price seen so far
            min_price = std::min(min_price, price);
            
            // Calculate potential profit and update max_profit if it's higher
            max_profit = std::max(max_profit, price - min_price);
        }
        
        return max_profit;
    }
};