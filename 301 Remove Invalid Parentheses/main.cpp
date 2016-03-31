#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        findValidParentheses(s,0,0, false);
        return ans;
    }

    void findValidParentheses(string s, int last_i, int last_j, bool reversed){
        string par;
        if(reversed)
            par = ")(";
        else
            par = "()";

        int stack = 0 , i = 0;

        for( i =  last_i ; i < s.size(); ++i){
            if(s[i] == par[0])
                stack++;
            if(s[i] == par[1])
                stack--;

            if(stack < 0)
                break;
        }


        if(stack < 0){
            for(int j = last_j ; j <= i ; ++j){
                if(s[j] == par[1] && (j == last_j || (s[j - 1] != par[1]))){
                    string newS = s.substr(0, j) + s.substr(j + 1);
                    findValidParentheses(newS, i, j, reversed);
                }
            }
            return;
        }
        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        if(!reversed)
            findValidParentheses(reverseS, 0, 0, true);
        else
            ans.push_back(reverseS);


    }

    vector<string> ans;
};

int main() {

    Solution s;

    auto ans = s.removeInvalidParentheses("(a)())()");
    for(auto &str : ans)
        cout<<str<<endl;

}
