# include<iostream>
# include<vector>
# include<numeric>
# include<string>
#include <unordered_map>
#include <map>

using namespace std;

class SolutionKama{
public:

    // 46. 携带研究材料（第六期模拟笔试）
    int KaMa_46(){
        int m, n;
        cin >> m;
        cin >> n;
        vector<int> weight(m);
        vector<int> value(m);
        for(int i = 0; i < m; i++){
            cin >> weight[i];
        }
        for(int i = 0; i < m; i++){
            cin >> value[i];
        }
        vector<int> dp(n+1);
        for(int i = weight[0]; i <= n; i++){
            dp[i] = value[0];
        }
        for(int epoch = 1; epoch < m; epoch++){
            for(int j = n; j > 0; j--){
                if(j >= weight[epoch]){
                    dp[j] = max(dp[j-weight[epoch]]+value[epoch], dp[j]);
                }
            }
        }
        cout << *dp.rbegin() << endl;
        return 1;
    }

    // 52. 携带研究材料（第七期模拟笔试）
    int kama52(){
        int m, n;
        cin >> m;
        cin >> n;
        vector<int> weight(m);
        vector<int> value(m);
        for(int i = 0; i < m; i++){
            cin >> weight[i];
            cin >> value[i];
        }
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++){
            dp[i] = value[0]*(i / weight[0]);
        }
        for(int i = 1; i < m; i++){
            for(int j = weight[i]; j <= n; j++){
                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            }
        }
        cout << dp[n] << endl;
}

};

class Solution{
public:

    // 509 斐波那契数
    int fib(int n) {
        if(n <= 1) return n;
        int dp[2] = {0, 1};
        int tmp;
        for(int i = 1; i < n; i++){
            tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 70 爬楼梯
    int climbStairs(int n) {
        if(n <= 2) return n;
        int dp[2] = {1, 2};
        int tmp;
        for(int i = 3; i <= n; i++){
            tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 746. 使用最小花费爬楼梯
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[2] = {0, 0};
        for(int n = 2; n <= cost.size(); n++){
            int tmp = min(dp[0] + cost[n-2], dp[1] + cost[n-1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

    // 62. 不同路径
    int uniquePaths(int m, int n) {
        int dp[n];
        for(int i = 0; i < n; i++) dp[i] = 1;
        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                dp[col] += dp[col-1];
            }
        }
        return dp[n-1];
    }

    // 63. 不同路径 II
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int> dp(obstacleGrid[0].size(), 0);
        for(int i = 0; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i] == 0){
                dp[i] = 1;
            }
            else break;
        }
        for(int i = 1; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1) dp[0] = 0;
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += dp[j-1];
            }
        }
        return *dp.rbegin();
    }

    // 343 整数拆分
    int integerBreak(int n) {
        if(n <= 2) return 1;
        if(n == 3) return 2;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                dp[i] = max(dp[i], dp[j]*dp[n-j]);
            }
        }
        return *dp.crbegin();
    }

    // 96. 不同的二叉搜索树
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-j-1];                
            }
        }
        return dp[n];
    }

    // 416 分割等和子集
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int bagSize = sum / 2;
        vector<int> dp(bagSize + 1);
        for(int i = nums[0]; i <= bagSize; i++){
            dp[i] = nums[0];
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = bagSize; j > 0; j--){
                if(j >= nums[i]){
                    dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
                }
            }
        }
        if(*dp.rbegin() == bagSize) return true;
        return false;
    }


    // 1049. 最后一块石头的重量 II
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int bagSize = total/2;
        vector<int> dp(bagSize + 1);
        for(int i = stones[0]; i <= bagSize; i++){
            dp[i] = stones[0];
        }
        for(int i = 1; i < stones.size(); i++){
            for(int j = bagSize; j > 0; j--){
                if(j >= stones[i]){
                    dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
                }
            }
        }
        return total - 2*(*dp.rbegin());
    }


    // 494. 目标和
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> pre;
        unordered_map<int, int> cur;
        pre[nums[0]]++;
        pre[-nums[0]]++;
        for(int i = 1; i < nums.size(); i++){
            for(auto it: pre){
                cur[it.first + nums[i]] += it.second;
                cur[it.first - nums[i]] += it.second;
            }
            swap(cur, pre);
            cur.clear();
        }
        return pre[target];
    }

    // 背包问题的思路
    int findTargetSumWaysBagSolution(vector<int>& nums, int target){
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum + target) % 2 != 0) return 0;
        if(abs(target) > sum) return 0;
        int bagSize = (sum + target)/2;
        vector<int> dp(bagSize + 1);
        dp[0] = 1;
        if(nums[0] <= bagSize){
            dp[nums[0]]++;
        }
        for(int i = 1; i < nums.size(); i++){
            for(int j = bagSize; j >= 0; j--){
                if(j >= nums[i]){
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return *dp.rbegin();
    }

    // 474 一和零
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string str: strs){
            int oneNum = 0, zeroNum = 0;
            for(char ch: str){
                if(ch == '1') oneNum++;
                else zeroNum++;
            }
            for(int i = m; i >= zeroNum; i--){
                for(int j = n; j >= oneNum; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum]+1);
                }
            }
        }
        return dp[m][n];
    }

};


int main(){
    Solution s;
    vector<string> a{"10","0001","111001","1","0"};
    int m = 5; 
    int n = 3;
    cout << s.findMaxForm(a, m, n);

}
