from os import curdir
import re


class Solution(object):

    # 455. 分发饼干
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        i,j = 0,0
        num = 0
        while j < len(s) and i < len(g):
            if s[j] >= g[i]:
                num += 1
                i += 1
            j += 1
        return num
    
    # 376 摆动序列
    def wiggleMaxLength(self, nums):
        if len(nums) <= 1:
            return len(nums)  # 如果数组长度为0或1，则返回数组长度
        preDiff,curDiff ,result  = 0,0,1  #题目里nums长度大于等于1，当长度为1时，其实到不了for循环里去，所以不用考虑nums长度
        for i in range(len(nums) - 1):
            curDiff = nums[i + 1] - nums[i]
            if curDiff * preDiff <= 0 and curDiff !=0:  #差值为0时，不算摆动
                result += 1
                preDiff = curDiff  #如果当前差值和上一个差值为一正一负时，才需要用当前差值替代上一个差值
        return result

    # 53. 最大子数组和
    def maxSubArray(self, nums):
        j = 0
        res = float("-inf")
        cursum = 0
        while j < len(nums):
            cursum += nums[j]
            res = max(res, cursum)
            if cursum < 0:
                cursum = 0
            j += 1
        return res
    
    # 122. 买股票的最佳时机2
    def maxProfit(self, prices):
        if len(prices) == 0: return 0
        res = 0
        for i in range(len(prices)-1):
            if prices[i+1] > prices[i]:
                res += prices[i+1] - prices[i]
        return res
    
    # 55. 跳跃游戏
    # 逆序遍历，遇到0就判断能不能跳过去
    def canJump(self, nums):
        if len(nums) <= 1: return True
        j = len(nums)-2
        while j >= 0:
            if nums[j] == 0:
                i = j - 1
                tag = False
                need = 2
                while i >= 0:
                    if nums[i] >= need:
                        tag = True
                        break
                    i -= 1
                    need += 1
                if tag == False: return False
                j = i
            j -= 1
        return True
    
    # 正序遍历，记录能到达的最远位置
    def canJump2(self, nums):
        if len(nums) <= 1: return True
        cover = 0
        i = 0
        while i <= cover:
            cover = max(i+nums[i], cover)
            if cover >= len(nums) - 1: return True
            i += 1
        return False
    
    # 45. 跳跃游戏二
    """
        1. 将区域划分为两部分： 一步可到达的区域，一步不能到达的区域
        2. 终点在可到达区域，return，否则，找两步可到达的最大区域
        3. 以此类推，三步，四步...
    """
    def jump(self, nums):
        step = 0
        i = 0
        curregion = 0
        nextregion = 0
        # 注意理解一下这里为什么要减一
        while i < len(nums) - 1:
            nextregion = max(i+nums[i], nextregion)
            if i == curregion:
                curregion = nextregion
                step += 1
            i += 1
        return step
    
    # 1005. K 次取反后最大化的数组和
    def largestSumAfterKNegations(self, nums, k):
        nums.sort(key=lambda x: abs(x), reverse=True)
        for i in range(len(nums)):
            if k > 0 and nums[i] < 0:
                nums[i] = -nums[i]
                k -= 1
        if k % 2 == 1:
            nums[-1] = -nums[-1]
        return sum(nums)


    # 134 加油站
    def canCompleteCircuit(self, gas, cost):
        """先写数学分析 
            只要所有站点油总和大于cost总和，则一定可以找到一个出发点满足题目条件
            0,1,...,n 个站，先从0开始出发，观察邮箱油量（可为负），在n1处油量达到最小
            则此时出发点一点在n1之后（这里很好理解，反证法即可，假设在前找出悖论）
            之后从n倒着找，找到累加可以弥补到n1处亏的油的位置即可，记为n2
            则n2一定可以到n1处，由于油总和大于油耗总和，所以n1也一定可以到n2处
        """
        if sum(gas) < sum(cost): return -1
        minFuel = float('inf')
        curFuel = 0
        for i in range(len(gas)):
            curFuel = curFuel + gas[i] - cost[i]
            if curFuel < minFuel:
                minFuel = curFuel
        if minFuel >= 0: return 0
        print(minFuel)
        n = len(cost)
        while minFuel < 0:
            n -= 1
            minFuel += gas[n] - cost[n]
        return n
    
    # 这个是贪心
    def canCompleteCircuit_(self, gas, cost):
        curSum = 0  # 当前累计的剩余油量
        totalSum = 0  # 总剩余油量
        start = 0  # 起始位置
        
        for i in range(len(gas)):
            curSum += gas[i] - cost[i]
            totalSum += gas[i] - cost[i]
            
            if curSum < 0:  # 当前累计剩余油量curSum小于0
                start = i + 1  # 起始位置更新为i+1
                curSum = 0  # curSum重新从0开始累计
        
        if totalSum < 0:
            return -1  # 总剩余油量totalSum小于0，说明无法环绕一圈
        return start

    # 135 分发糖果
    def candy(self, ratings):
        candyVec = [1] * len(ratings)
        
        # 从前向后遍历，处理右侧比左侧评分高的情况
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                candyVec[i] = candyVec[i - 1] + 1
        
        # 从后向前遍历，处理左侧比右侧评分高的情况
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1)
        
        # 统计结果
        result = sum(candyVec)
        return result
    
    # 860. 柠檬水找零
    def lemonadeChange(self, bills):
        change = [0,0]
        for bill in bills:
            if bill == 5:change[0]+=1
            elif bill == 10:
                change[1] += 1
                if change[0] == 0: 
                    return False
                change[0] -= 1
            else:
                if change[0] == 0:
                    return False
                if change[1] == 0 and change[0] <= 2: 
                    return False
                if change[1] >= 1:
                    change[0] -= 1
                    change[1] -= 1
                else:
                    change[0] -= 3
        return True
    
    # 406.根据身高重建队列
    # 这是我的方法，根据提示写的，性能很差
    def reconstructQueue(self, people):
        people.sort(key = lambda x: x[0])
        quene = [0]*len(people)
        for i in range(len(people)):
            count = 0
            pos = 0
            while count < people[i][1] or quene[pos]!=0:
                if quene[pos] == 0:
                    count += 1
                elif quene[pos][0] == people[i][0]:
                    count += 1
                pos += 1
            quene[pos] = people[i]
        return quene
    
    def reconstructQueue_(self, people):
        people.sort(key = lambda x: (-x[0], x[1]))
        que = []
        for p in people:
            que.insert(p[1], p)
        return que
    
    # 452. 用最少数量的箭引爆气球
    def findMinArrowShots(self, points):
        points.sort(key = lambda x: x[0])
        baloon = 0
        res = 0
        while baloon < len(points):
            left = points[baloon][0]
            right = points[baloon][1]
            res += 1
            while baloon < len(points):
                left = max(left, points[baloon][0])
                right = min(right, points[baloon][1])
                if left <= right:
                    baloon += 1
                else:break
        return res
    
    def findMinArrowShots_(self, points):
        points.sort(key = lambda x: x[0])
        sl,sr = points[0][0],points[0][1]
        count = 1
        for i in points:
            if i[0]>sr:
                count+=1
                sl,sr = i[0],i[1]
            else:
                sl = max(sl,i[0])
                sr = min(sr,i[1])
        return count

    # 435. 无重叠区间
    def eraseOverlapIntervals(self, intervals):
        if len(intervals) == 0: return 0
        intervals.sort(key = lambda x: x[0])
        r =intervals[0][1]
        count = 0
        j = 1
        while j < len(intervals):
            if intervals[j][0] >= r:
                r = intervals[j][1]
            else:
                count += 1
                r = min(intervals[j][1], r)
            j += 1
        return count

    # 763. 划分字母区间
    def partitionLabels(self, s):
        def findlast(a, index, s):
            for i in range(len(s)-1, index, -1):
                if s[i] == a: return i
            return 0
        last = 0
        num = 1
        res = []
        for i in range(len(s)):
            last = max(findlast(s[i], i, s),last)
            if i >= last:
                res.append(num)
                num = 1
            else:num += 1
        return res
    
    def partitionLabels_(self, s):
        last_occour = {}
        for i in range(len(s)):
            last_occour[s[i]] = i
        res = []
        last = 0
        num = 1
        for i in range(len(s)):
            last = max(last, last_occour[s[i]])
            if i == last:
                res.append(num)
                num = 1
            else:num += 1
        return res


    # 56.合并区间
    def merge(self, intervals):
        intervals.sort(key = lambda x:x[0])
        res = []
        start, end = intervals[0][0], intervals[0][1]
        for i in range(len(intervals)):
            if intervals[i][0] > end:
                res.append([start, end])
                start, end = intervals[i]
            else:
                end = max(end, intervals[i][1])
        res.append([start,end])
        return res
    # 这是答案的方法，思路是一样的，但是效率比我的高很多，不知道为什么
    def merge_(self, intervals):
        result = []
        if len(intervals) == 0:
            return result  # 区间集合为空直接返回

        intervals.sort(key=lambda x: x[0])  # 按照区间的左边界进行排序
        result.append(intervals[0])  # 第一个区间可以直接放入结果集中
        for i in range(1, len(intervals)):
            if result[-1][1] >= intervals[i][0]:  # 发现重叠区间
                # 合并区间，只需要更新结果集最后一个区间的右边界，因为根据排序，左边界已经是最小的
                result[-1][1] = max(result[-1][1], intervals[i][1])
            else:
                result.append(intervals[i])  # 区间不重叠
        return result
                
    # 738. 单调递增的数字
    def monotoneIncreasingDigits(self, n):
        strNum = str(n)
        flag = len(strNum)

        for i in range(len(strNum)-1, 0, -1):
            if strNum[i - 1] > strNum[i]:
                flag = i
                strNum = strNum[:i-1] + str(int(strNum[i-1])-1) + strNum[i:]        
        strNum = strNum[:flag] + '9'*(len(strNum)-flag)
        return int(strNum)