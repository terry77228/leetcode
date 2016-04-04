#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1)
            return 0;

        int minStock = prices[0];
        int maxVal = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] - minStock > maxVal)
                maxVal = prices[i] - minStock;

            if(prices[i] < minStock)
                minStock = prices[i];
        }

        return maxVal;
    }
};
int main() {

    vector<int> prices({4,3,2,9,12,3,6}); // 10
    vector<int> prices2({10,9,8,7,6,5,4,3,2,1}); // 0
    Solution s;
    cout<<s.maxProfit(prices)<<endl;
    cout<<s.maxProfit(prices2)<<endl;
}
