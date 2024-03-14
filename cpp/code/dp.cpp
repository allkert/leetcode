# include<iostream>
# include<vector>
# include<numeric>
# include<string>

using namespace std;

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
        int dp[2] = {0, min(cost[0], cost[1])};
        for(int n = 2; n <= cost.size(); n++){
            int tmp = min(dp[0] + cost[n-2], dp[1] + cost[n-1]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }

};
