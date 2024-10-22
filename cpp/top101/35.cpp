#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param triangle int整型vector<vector<>> 
     * @return int整型
     */
    int minTrace(vector<vector<int> >& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(triangle);
        dp[0][0] = triangle[0][0];
        for(int i = 1; i <n; ++i){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            for(int j = 1; j < i; ++j) dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};