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
    

};

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
}

int main(){
    int m;
    int n;
    cin >> m;
    cin >> n;
    cout << m<<endl;
}
