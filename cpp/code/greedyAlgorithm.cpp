# include<iostream>
# include<vector>
# include<limits>
# include <algorithm>

using namespace std;

class Solution {
public:

    // 455. 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for(int i = g.size()-1, index = s.size()-1; i >= 0 && index >= 0; i--){
            if(s[index] >= g[i]){
                res++;
                index--;
            }
        }
        return res;
    }

    // 376 摆动序列
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int res = (nums[0] == nums[1])? 1:2;
        
    }
};