                tmp[j][0] = max(dp[j][0], dp[j][1] - prices[i]);
                tmp[j][1] = max(dp[j][1], dp[j-1][0] + prices[i]);