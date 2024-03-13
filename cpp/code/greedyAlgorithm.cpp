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
    int wiggleMaxLength_dp(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int dp[2] = {1, 1};
        int res = 2;
        if(nums[1] > nums[0]) dp[0] = 2;
        else if(nums[1] < nums[0]) dp[1] = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                dp[0] = max(dp[0], dp[1] + 1);
            }
            else if(nums[i] < nums[i-1]){
                dp[1] = max(dp[1],dp[0] + 1);
            }
        }
        return (dp[0] > dp [1])? dp[0]:dp[1];
    }

    int wiggleMaxLength_greedy(vector<int>& nums){
        if(nums.size() == 1) return 1;
        int preDif = 0;
        int curDif = 0;
        int res = 1;
        for(int i = 0; i < nums.size()-1; i++){
            curDif = nums[i+1]-nums[i];
            if((preDif <= 0 && curDif > 0) || (preDif >= 0 && curDif < 0)){
                preDif = curDif;
                res++;
            }
        }
        return res;
    }

    // 53 最大子数组和
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > res) res = count;
            if(count < 0) count = 0;
        }
        return res;
    }

    // 122. 买卖股票的最佳时机 II
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i+1]-prices[i] > 0) res += prices[i+1]-prices[i];
        }
        return res;
    }

    int maxProfit_dp(vector<int>& prices){
        int dp[2] = {0, -prices[0]};
        for(int i = 1; i < prices.size(); i++){
            int tmp0 = dp[0];
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], tmp0 - prices[i]);    
        }
        return dp[0];
    }


    // 55. 跳跃游戏
    bool canJump(vector<int>& nums) {
        int maxJumpIndex = 0;
        int length = nums.size();
        for(int i = 0; i < maxJumpIndex; i++){
            maxJumpIndex = max(maxJumpIndex, i + nums[i]);
            if(maxJumpIndex >= length) return true;
        }
        return false;
    }

    // 45跳跃游戏Ⅱ
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int i = 0;
        int cover = nums[i];
        int step = 1;
        while(cover < nums.size()){
            int nextPlace = i;
            int nextCover = cover;
            for(int j = i; j <= cover; j++){
                if(j + nums[j] > nextCover){
                    nextPlace = j;
                    nextCover = j + nums[j];
                }
            }
            if(cover >= nums.size()-1) break;
            step++;
            cover = nextCover;
            i = nextPlace;
        }
        return step;
    }

    int jump1(vector<int>& nums){
        if(nums.size() == 1) return 0;
        int nextCover = 0;
        int curCover = 0;
        int step = 0;
        for(int i = 0; i < nums.size(); i++){
            nextCover = max(nextCover, i + nums[i]);
            if(i == curCover){
                step++;
                curCover = nextCover;
                if(curCover >= nums.size()-1) break;
            }
        }
        return step;
    }


    // 1005. K 次取反后最大化的数组和
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        quickSortAbs(nums, 0, nums.size()-1);
        int sumResult = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
            sumResult += nums[i];
        }
        if(k % 2 == 0) return sumResult + nums[nums.size()-1];
        else return sumResult - nums[nums.size()-1];
    }
    void quickSortAbs(vector<int>& nums, int beginIndex, int endIndex){
        if(beginIndex >= endIndex) return;
        int left = beginIndex, right = endIndex;
        int tag = left;
        while(left < right){
            while(abs(nums[right]) <= abs(nums[tag]) && left < right) right--;
            if(left < right){
                swap(nums[right], nums[tag]);
                tag = right;
            }
            while(abs(nums[left]) >= abs(nums[tag]) && left < right) left++;
            if(left < right){
                swap(nums[left], nums[tag]);
                tag = left;
            }
        }
        quickSortAbs(nums, beginIndex, tag-1);
        quickSortAbs(nums, tag + 1, endIndex);
    }

    // 134. 加油站
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
    }

};

int main(){
    Solution s;
    vector<int> a{5,6,9,-3,-3};
    s.quickSortAbs(a, 0, a.size()-1);
    for(int num: a) cout <<num<<'\t';
}