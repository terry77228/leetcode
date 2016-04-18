#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:

//Compare palindrome
    int match(const string &s, int left, int right){
        int res = 0;
        while(left >= 0 && right < s.size() && s[left--] == s[right++]){
            res++;
        }
        return res;
    }


    string shortestPalindrome(string s) {
        if(s.empty())
            return s;
        //Manacher's algorithm, O(n)
        string extend("@");
        for(int i = 0; i < s.size(); ++i){
            extend.push_back(s[i]);
            extend.push_back('#');
        }
        vector<int> Pa(extend.size(), 0);
        int Center = 0, Right = 0;
        for(int i = 1; i < extend.size(); ++i){

            int mirror_i = 2*Center - i;
            if(Right < i){
                Pa[i] = match(extend, i, i);
                Right = Pa[i] + i - 1;
                Center = i;
            }
            else{
                if(i + Pa[mirror_i] - 1 == Right){
                    Pa[i] = Pa[mirror_i] + match(extend, i - Pa[mirror_i] , i + Pa[mirror_i]);
                    Center = i;
                    Right = i + Pa[i] - 1;
                }
                else{
                    Pa[i] = Pa[mirror_i] - 1;
                }
            }

        }

        int maxLen = 0;
        int index = 0;
        for(int i = 1; i < Pa.size(); ++i){
            if(i - Pa[i] == 0){
                maxLen = max(maxLen, Pa[i]);
                index = i;
            }
        }

        string ans = s.substr(((index + 1) / 2) + (maxLen / 2));
        reverse(ans.begin(), ans.end());
        ans.append(s);
        return ans;
    }
};

int main() {


    Solution s;
    cout<<s.shortestPalindrome("abcd")<<endl;
    cout<<s.shortestPalindrome("aacecaaa")<<endl;
}
