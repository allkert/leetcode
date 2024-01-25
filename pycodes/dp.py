from collections import defaultdict
from hashlib import sha1
from math import inf
from numpy import shape, random
from sympy import N

class sloution(object):

    # 509. 斐波那契数
    def fib(self, n):
        if n <= 1:return n
        dp = [0, 1]
        for _ in range(n-1):
            dp = [dp[1], dp[0]+dp[1]]
        return dp[1]

    # 70. 爬梯子
    def climbStairs(self, n):
        if n <= 2: return n
        dp = [1,2]
        for _ in range(n-2):
            dp = [dp[1], dp[0]+dp[1]]
        return dp[1]
    
    # 746. 使用最小花费爬楼梯
    def minCostClimbingStairs(self, cost):
        dp = [0,0]
        for i in range(len(cost)-1):
            dp = [dp[1], min(dp[0]+cost[i],dp[1]+cost[i+1])]
        return dp[1]

    # 62 不同路径
    def uniquePaths(self, m, n):
        dp = [[0]*n for _ in range(m)]
        for i in range(m):
            dp[i][0] = 1
        dp[0] = [1]*n
        for row in range(1,m):
            for col in range(1,n):
                dp[row][col] = dp[row][col-1] + dp[row-1][col]
        return dp[m-1][n-1]


    #  63 不同路径2
    def uniquePathsWithObstacles(self, obstacleGrid):
        m,n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [1]*n
        for i in range(n):
            if obstacleGrid[0][i] == 1:
                dp = dp[:i]+[0]*len(dp[i:])
                break
        for i in range(1,m):
            if obstacleGrid[i][0]==1:
                dp[0] = 0
            for j in range(1,n):
                if obstacleGrid[i][j] == 1: dp[j] = 0
                else: dp[j] += dp[j-1]
        return dp[-1]

    # 343 整数拆分
    def integerBreak(self, n):
        if n == 2: return 1
        if n == 3: return 2
        dp = [0,1,2,3]
        for i in range(4,n+1):
            tmp = 0
            for a in range(1,i):
                tmp = max(tmp, dp[a]*dp[i-a])
            dp.append(tmp)
        return dp[-1]

    # 96. 不同的二叉搜索树 
    def numTrees(self, n):
        dp = [1]
        for i in range(1,n+1):
            dp.append(sum([dp[k-1]*dp[i-k] for k in range(1,i+1)]))
        return dp[-1]
            
        
    # 416 分割等和子集
    # 使用回溯搜索，果然会超时，因为是指数级复杂度
    def canPartition(self, nums):
        def backtracking(nums, sum1, sum2):
            if len(nums) == 0: return sum1 == sum2
            return backtracking(nums[1:], sum1+nums[0], sum2) or backtracking(nums[1:], sum1, sum2+nums[0])
        return backtracking(nums,0,0)
    
    # 思考
    """
        首先将这个问题转化为了0-1背包问题，cost[i]和value[i]都是nums[i],target == sum//2
        在使用一维dp时出现了一个问题，在递推dp时，存在dp的覆盖，
        dp[j],即二维dp数组中的dp[i][j],j之前的dp数组的值已经被覆盖为dp[i][:j]了，而不是dp[i-1][:j]，因此递推除了错误的dp数组，
        这其实对应的是完全背包问题。
        修改办法：
         1.使用tmp  2.逆序更新dp数组，即dp[j]递推时只需要使用到dp[:j]的值，所以从dp[-1]开始递推就不会出现问题
    """
    def canPartition_(self, nums):
        al = sum(nums)
        if al % 2 != 0: return False
        target = al // 2
        dp = [0]*(target+1)
        for j in range(nums[0],target+1):
            dp[j] = nums[0]
        for i in range(1,len(nums)):
            tmp = dp[:]
            for j in range(1,target+1):
                if j >= nums[i]:
                    dp[j] = max(tmp[j], tmp[j-nums[i]]+nums[i])
            if dp[-1] == target: return True
        return False
    
    def canPartition_1(self, nums):
        al = sum(nums)
        if al % 2 != 0: return False
        target = al // 2
        dp = [0]*(target+1)
        for num in nums:
            for j in range(target,num-1,-1):
                dp[j] = max(dp[j], dp[j-num]+num)
            if dp[-1] == target: return True
        return False

    #  1049. 最后一块石头的重量2
    def lastStoneWeightII(self, stones):
        target = sum(stones) // 2
        dp = [0]*(target+1)
        for stone in stones:
            for j in range(target, stone-1, -1):
                dp[j] = max(dp[j], dp[j-stone]+stone)
        return sum(stones) - 2*dp[-1]

    # 494 目标和
    # 这是我的解法，只想到了dp，但是没想到与01背包问题的关系，因此写出来效率很低，占用空间也较大
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        dp = {nums[0]:1, -nums[0]:1} if nums[0] else {nums[0]:2}
        for num in nums[1:]:
            tmp = {}
            for key in dp:
                if key + num in tmp:
                    tmp[key+num] += dp[key]
                else:
                    tmp[key+num] = dp[key]
                if key - num in tmp:
                    tmp[key-num] += dp[key]
                else:
                    tmp[key-num] = dp[key]
            dp = tmp
        if target in dp: return dp[target]
        else: return 0

    def findTargetSumWays_(self, nums: list[int], target: int) -> int:
        al = target + sum(nums)
        if al % 2 or al < 0: return 0
        bagsize = al // 2
        dp = [0]*(bagsize+1)
        dp[0] = 1
        for num in nums:
            for i in range(bagsize, num-1, -1):
                dp[i] = dp[i]+dp[i-num]
        return dp[-1]

    # 474 一和零
    def findMaxForm(self, strs: list[str], m: int, n: int) -> int:
        def count01(s:str):
            m,n = 0,0
            for ch in s:
                if ch == "0":m += 1
                elif ch == "1":n += 1
            return (m,n)
        num0, num1 = count01(strs[0])
        dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(num0,m+1):
            for j in range(num1, n+1):
                dp[i][j] = 1
        for i in range(1, len(strs)):
            num0, num1 = count01(strs[i])
            print(num0,num1)
            for col in range(m, num0-1, -1):
                for row in range(n, num1-1, -1):
                    dp[col][row] = max(dp[col][row], dp[col-num0][row-num1]+1)
        return dp[-1][-1]

    # 518 零钱兑换2
    def change(self, amount: int, coins: list[int]) -> int:
        dp = [0]*(amount+1)
        dp[0] = 1
        for coin in coins:
            for j in range(coin, amount+1):
                dp[j] += dp[j-coin] 
            print(dp)
        return dp[-1]

    def change_(self, amount: int, coins: list[int]) -> int:
        dp = [0]*(amount+1)
        dp[0] = 1
        for j in range(0, amount+1):
            for coin in coins:
                if j >= coin: dp[j] += dp[j-coin] 
            print(dp)
        return dp[-1]

    # 377 组合总和4
    def combinationSum4(self, nums: list[int], target: int) -> int:
        dp = [0]*(target+1)
        dp[0] = 1
        for num in nums:
            for j in range(nums, target+1):
                dp[j] += dp[j-num]
        return dp[-1]
    
    # 卡玛网 57. 爬楼梯
    def climb_(self):
        n, m = [int(i) for i in input().split()]
        dp = [0]*(n+1)
        dp[0] = 1
        for i in range(0, n+1):
            for j in range(1,m+1):
                if j <= i: dp[i] += dp[i-j]
        print(dp[-1])
    
    # 322 零钱兑换
    def coinChange(self, coins: list[int], amount: int) -> int:
        dp = [-1]*(amount+1)
        dp[0] = 0
        for coin in coins:
            for j in range(coin, amount+1):
                if dp[j] != -1 and dp[j-coin] != -1:
                    dp[j] = min(dp[j], dp[j-coin]+1)
                elif dp[j] == -1 and dp[j-coin] == -1:
                    dp[j] = -1
                else:
                    dp[j] = max(dp[j], dp[j-coin]+1)
        return dp[-1]

    # 279. 完全平方数
    def numSquares(self, n: int) -> int:
        weight = [i**2 for i in range(int(n**0.5)+1)]
        dp = [float("inf")]*(n+1)
        dp[0] = 0
        for w in weight:
            for j in range(w,n+1):
                dp[j] = min(dp[j], dp[j-w]+1)
        return dp[-1]
    
    # 139 单词拆分
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        ls = len(s)
        dp = [False]*(ls+1)
        dp[0] = True
        for i in range(ls+1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
        return dp[-1]

    #198 打家劫舍 
    """
        在这里思考一个关于递推公式正确性的问题：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
        这里如果在dp[i-1]中没偷第i-1家的话， 则可以偷第i家，则最大收益可能为：dp[i-1]+nums[i]
        但实际上此时dp[i-1]=dp[i-2]所以最大收益也为dp[i-2]+nums[i]
    """
    def rob(self, nums: list[int]) -> int:
        if len(nums) == 1: 
            return nums[0]
        dp = [nums[0], max(nums[1], nums[0])]
        for i in range(2, len(nums)):
            dp.append(max(dp[-1], dp[-2]+nums[i]))
        return dp[-1]
    
    #  213 打家劫舍2
    def rob2(self, nums: list[int]) -> int:
        def func(nums: list[int]) -> int:
            if len(nums) == 1: 
                return nums[0]
            dp = [nums[0], max(nums[1], nums[0])]
            for i in range(2, len(nums)):
                dp.append(max(dp[-1], dp[-2]+nums[i]))
            return dp[-1]
        if len(nums) <= 3: return max(nums)
        return max(nums[0] + func(nums[2:-1]), func(nums[1:]))

    # 337 打家劫舍Ⅲ
    def rob3(self, root):
        def postorderTraversal(root):
            if root == None: return []
            stack = [root]
            res = []
            while stack:
                node = stack.pop()
                res.append(node)
                if node.left: stack.append(node.left)
                if node.right: stack.append(node.right)
            return res[::-1]
        postorder = postorderTraversal(root)
        dp = {None:0}
        for node in postorder:
            if node.left and node.right:
                dp[node] = max(node.val+dp[node.left.left]+dp[node.left.right]+dp[node.right.left]+dp[node.right.right],dp[node.left]+dp[node.right])
            elif node.left and node.right == None:
                dp[node] = max(node.val+dp[node.left.left]+dp[node.left.right], dp[node.left])
            elif node.left == None and node.right:
                dp[node] = max(node.val+dp[node.right.left]+dp[node.right.right], dp[node.right])
            else:dp[node] = node.val
        return dp[root]
    
    def rob3_re(self, root):
        def traversal(node):
            if node == None: return (0,0)
            left = traversal(node.left)
            right = traversal(node.right)
            return (max(left)+max(right), node.val+left[0]+right[0])
        dp = traversal(root)
        return max(dp)
    
    # 121 买股票的最佳时机
    # 非dp
    def maxProfit_121(self, prices):
        lowestprice = inf
        profit = 0
        for price in prices:
            profit = max(profit, price-lowestprice)
            lowestprice = min(lowestprice, price)
        return profit
    # dp
    def maxProfit_121_1(self, prices: list[int]) -> int:
        min_ = prices[0]
        dp = [0]*2
        for i in range(1, len(prices)):
            dp[0], dp[1] =dp[1], max(dp[1], prices[i] - min_)
            min_ = min(min_, prices[i])
        return dp[-1]
    
    def maxProfit_121_2(self, prices):
        dp = [-prices[0], 0]
        for i in range(1,len(prices)):
            dp[1] = max(dp[1], dp[0]+prices[i])
            dp[0] = max(-prices[i], dp[0])
        return dp[-1]  

    #188 买股票的最佳时机Ⅳ
    # 垃圾版
    def maxProfit_188_1(self, k: int, prices: list[int]) -> int:   
        days = len(prices)
        dp = [[[0,0] for _ in range(k+1)] for _ in range(days)]
        for times in range(k+1):
            dp[0][times][0] = -prices[0]
        # for day in range(1,days):
        #     dp[day][0][0] = max(dp[day-1][0][0], -prices[day]) 
        for times in range(1,k+1):
            for day in range(1,days):
                dp[day][times][0] = max(dp[day-1][times-1][1]-prices[day], dp[day-1][times][0])
                dp[day][times][1] = max(dp[day-1][times][0]+prices[day], dp[day-1][times][1])
        for i in range(days):
            print(dp[i])
        return dp[-1][-1][-1]
    
    # 参考答案
    def maxProfit_188_ref(self, k: int, prices: list[int])->int:
        dp = [0]*(1+2*k)
        for i in range(1,2*k,2):
            dp[i] = -prices[0]
        for i in range(1,len(prices)):
            for j in range(2*k, 0, -1):
                if j % 2 == 1:
                    
                    dp[j] = max(dp[j], dp[j-1]-prices[i])
                else:
                    dp[j] = max(dp[j], dp[j-1]+prices[i])
        return dp[-1]
    
    # 309 买卖股票的最佳时机含冷冻期
    # 这题不会，直接参考答案
    def maxProfit_froze_4state(self, prices: list[int]) -> int:
        """ 
        分成四种状态:0. 持有股票
                    1. 不持有股票，且不在冷冻期，且不是当天卖出
                    2. 不持有股票，且不在冷冻期，且是当天卖出
                    4. 处于冷冻期
        """
        dp = [[0]*4 for _ in range(len(prices))]
        dp[0][0] = -prices[0]
        for i in range(1, len(prices)):
            # 昨天就持有股票，或者昨天不持有股票今天买入，或者昨天处于冷冻期今天买入
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3])-prices[i])
            dp[i][1] = max(dp[i-1][3], dp[i-1][1])
            dp[i][2] = dp[i-1][0]+prices[i]
            dp[i][3] = dp[i-1][2]
        return max(dp[-1][1:])
    
    def maxProfit_froze_3state(self, prices: list[int]) -> int:
        """ 
        0. 今天持有股票
        1. 今天不持有股票，且明天处于冷冻状态
        2. 今天不持有股票，明天不处于冷冻状态
        """
        dp = [[0]*3 for _ in range(len(prices))]
        dp[0][0] = -prices[0]
        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i])
            dp[i][1] = dp[i-1][0]+prices[i]
            dp[i][2] = max(dp[i-1][2],dp[i-1][1])
        return max(dp[-1][1:])

    # 714. 买股票的最佳时机含手续费
    def maxProfit_fee(self, prices: list[int], fee: int) -> int:
        dp = [-prices[0]-fee, 0]
        for i in range(1, len(prices)):
            dp[0], dp[1] = max(dp[0], dp[1]-fee-prices[i]), max(dp[1], dp[0]+prices[i])
        return dp[-1]
    
    # 300. 最长递增子序列
    # 回溯写法会超时
    def lengthOfLIS_backtracking(self, nums: list[int]) -> int:
        def backtracking(nums, head):
            if len(nums) == 0: return 0
            if nums[0] > head:
                return max(1+backtracking(nums[1:], nums[0]), backtracking(nums[1:], head))
            else:
                return backtracking(nums[1:], head)
        return backtracking(nums, -inf)
    
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = [1]*len(nums)
        for i in range(1, len(nums)):
            for j in range(0,i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp[i])

    # 674. 最长连续递增序列
    def findLengthOfLCIS(self, nums: list[int]) -> int:
        tmp = 1
        res = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                tmp += 1
            else:
                if tmp > res: res = tmp
                tmp = 1
        return max(res, tmp)

    # 718. 最长重复子数组
    def findLength(self, nums1: list[int], nums2: list[int]) -> int:
        a,b = len(nums1), len(nums2)
        dp = [[0]*b for _ in range(a)]
        for i in range(a):
            if nums1[i] == nums2[0]:
                dp[i][0] = 1
        for i in range(b):
            if nums1[0] == nums2[i]:
                dp[0][i] = 1
        for i in range(1,a):
            for j in range(1,b):
                if nums1[i] == nums2[j]:
                    dp[i][j] = dp[i-1][j-1] + 1
        return max([max(dp[i]) for i in range(a)])
    
    def findLength_ref(self, nums1: list[int], nums2: list[int]) -> int:
        """
            这样使用一维dp，且修改dp定义从而简化初始化，
            dp[i][j]： 以i-1，j-1结尾的重复子数组长度
        """
        dp = [0]*(len(nums2)+1)
        res = 0
        for i in range(1, len(nums1)+1):
            for j in range(len(nums2), 0, -1):
                if nums1[i-1] == nums2[j-1]:
                    dp[j] = dp[j-1] + 1
                    if dp[j] > res:
                        res = dp[j]
                else:dp[j] = 0
        return res

    # 1143. 最长公共子序列
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        a, b = len(text1), len(text2)
        dp = [[0]*b for _ in range(a)]
        for i in range(a):
            if text1[i] == text2[0]:
                for j in range(i, a):
                    dp[j][0] = 1
                break
        for i in range(b):
            if text1[0] == text2[i]:
                for j in range(i, b):
                    dp[0][j] = 1
                break
        for i in range(1,a):
            for j in range(1,b):
                if text1[i] == text2[j]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]
    
    # 1035 不相交的线
    def maxUncrossedLines(self, nums1: list[int], nums2: list[int]) -> int:
        a, b = len(nums1), len(nums2)
        dp = [[0]*b for _ in range(a)]
        for i in range(a):
            if nums1[i] == nums2[0]:
                for j in range(i,a):
                    dp[j][0] = 1
                break
        for i in range(b):
            if nums2[i] == nums1[0]:
                for j in range(i, b):
                    dp[0][j] = 1
                break
        for i in range(1, a):
            for j in range(1, b):
                if nums1[i] == nums2[j]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]

    # 53. 最大子数组和
    def maxSubArray(self, nums: list[int]) -> int:
        dp = nums[0]
        res = nums[0]
        for i in range(1, len(nums)):
            if dp <= 0:
                dp = nums[i]
            else:
                dp += nums[i]
            if dp > res: res = dp
        return res

    # 392. 判断子序列
    def isSubsequence(self, s: str, t: str) -> bool:
        dp = [[0]*(len(t)+1) for _ in range(len(s)+1)]
        for i in range(1, len(s)+1):
            for j in range(1, len(t)+1):
                if s[i-1] == t[j-1]: 
                    dp[i][j] = dp[i-1][j-1]+1
                else:dp[i][j] = dp[i][j-1]
        return True if dp[-1][-1] == len(s) else False
    
    # 115. 不同的子序列
    # 思路是对的，但是有一个测试用例会超时
    def numDistinct(self, s: str, t: str) -> int:
        a, b = len(t), len(s)
        dp = [[0]*b for _ in range(a)]
        for i in range(b):
            if t[0] == s[i]:
                dp[0][i] = 1
        for i in range(1, a):
            for j in range(1, b):
                if t[i] == s[j]:
                    dp[i][j] = sum(dp[i-1][0:j])
        return sum(dp[-1])

    def numDistinct_ref(self, s: str, t: str) -> int:
        b = len(s)
        dp = [1]*(b + 1)
        dp[0] = 0
        pre = 1
        cur = 0
        for i in range(len(t)):
            for j in range(1, b + 1):
                cur = dp[j] 
                if t[i] == s[j-1]:
                    dp[j] = dp[j-1] + pre
                else:
                    dp[j] = dp[j-1]
                pre = cur
            pre = 0
        return dp[-1]

    # 583. 两个字符串的删除操作
    def minDistance(self, word1: str, word2: str) -> int:
        a, b = len(word1), len(word2)
        dp = [[0]*(b+1) for _ in range(a+1)]
        for i in range(a+1):
            dp[i][0] = i
        for j in range(b+1):
            dp[0][j] = j
        for i in range(1, a+1):
            for j in range(1, b+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1
        return dp[-1][-1]

    # 72. 编辑距离
    def minDistance(self, word1: str, word2: str) -> int:
        a, b = len(word1), len(word2)
        dp = [[0]*(b+1) for _ in range(a+1)]
        dp[0] = [i for i in range(b+1)]
        for i in range(a+1):
            dp[i][0] = i
        for i in range(1, a+1):
            for j in range(1, b+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1)
        return dp[-1][-1]
    
    # 根据参考答案修改的滚动dp数组的方法，效率更优
    def minDistance_scroll(self, word1: str, word2: str) -> int:
        a, b = len(word1), len(word2)
        dp = [i for i in range(b+1)]

        for i in range(1, a+1):
            pre = dp[0]
            cur = dp[0]
            dp[0] = i
            for j in range(1, b+1):
                cur = dp[j]
                if word1[i-1] == word2[j-1]:
                    dp[j] = pre
                else:
                    dp[j] = min(dp[j-1], dp[j], pre)+1
                pre = cur
        return dp[-1]

    # 647 回文子串
    # 动态规划很占内存
    def countSubstrings(self, s: str) -> int:
        dp = [[0]*len(s) for _ in range(len(s))]
        res = 0
        for i in range(len(s)):
            for j in range(i, -1, -1):
                if s[i] == s[j]:
                    if i - j <= 1:
                        dp[i][j] = True
                        res += 1
                    elif dp[i-1][j+1]:
                        res += 1
                        dp[i][j] = True
        return res

    # 双指针法
    def countSubstrings_doublePointer(self, s: str) -> int:
        def extend(s, i, j, n):
            res = 0
            while i >=0 and j < n and s[i] == s[j]:
                i -= 1
                j += 1
                res += 1
            return res
        
        length = len(s)

        res = 0
        for i in range(len(s)):
            res += extend(s, i, i, length)
            res += extend(s, i, i+1, length)
        return res
    
    # 516. 最长回文子序列
    def longestPalindromeSubseq(self, s: str) -> int:
        dp = [[0]*len(s) for _ in range(len(s))]
        for i in range(len(s)):
            for j in range(i, -1, -1):
                if s[i] == s[j]:
                    if i == j:
                        dp[i][j] = 1
                    elif i-j == 1:
                        dp[i][j] = 2
                    else:
                        dp[i][j] = dp[i-1][j+1] + 2
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j+1])
        return dp[-1][0]
        
        

    

