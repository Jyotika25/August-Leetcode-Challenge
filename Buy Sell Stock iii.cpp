class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        
        int p1 = prices[0];
        int p2 = prices[prices.size()-1];
        
        vector<int> profit1(prices.size(),0);
        vector<int> profit2(prices.size(),0);
        
        for(int i=1;i<prices.size();i++){
            profit1[i] = max(profit1[i-1],prices[i]-p1);
            p1 = min(p1,prices[i]);
            
            int j=prices.size()-i-1;
            profit2[j] = max(profit2[j+1],p2-prices[j]);
            p2 = max(p2,prices[j]);
        }
        int profit = 0;
        
        for(int i=0;i<prices.size();i++){
            profit = max(profit , profit1[i] + profit2[i]);
        }
        return profit;
    }
};
