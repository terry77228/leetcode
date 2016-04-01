#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> powers(primes.size(), 0);
        vector<int> superugly;
        superugly.push_back(1);

        for(int i = 1 ; i < n ; ++i){
            superugly.push_back(INT_MAX);

            for(int j = 0; j < primes.size(); ++j){
                superugly[i] = min(superugly[i], primes[j]*superugly[powers[j]]);
            }

            for(int j = 0 ; j < primes.size(); ++j)
                while(primes[j]*superugly[powers[j]] <= superugly[i]) powers[j]++;
        }
        return superugly.back();

    }
};

int main() {

    Solution s;
    vector<int> primes ={2,7,13,19};
    cout<<s.nthSuperUglyNumber(12, primes)<<endl;

}
