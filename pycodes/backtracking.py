import copy
class Solution(object):
    # 77. 组合
    # 我的，写的有点乱八七糟，答案也是这样，剪枝过，我真厉害
    def combine(self, n, k):
        res = []
        def func(low, n, k ,choice,res):
            if k == 0:
                res.append(choice)
                return
            for i in range(low,n-k+2):
                choice.append(i)
                func(i+1,n,k-1,choice[:],res)
                choice.pop()
        func(1,n,k,[],res)
        return res

    # 216. 组合总和 III
    def combinationSum3(self, k, n):
        res = []
        def func(k,n,low,path,res):
            total = sum(path)
            if k == 0 and total == n:
                res.append(path)
            elif k > 0 and total < n:
                for i in range(low, 11-k):
                    path.append(i)
                    func(k-1,n,i+1,path[:],res)
                    path.pop()
            else:return
        func(k, n, 1, [], res)
        return res
    
    # 17. 电话号码的字母组合
        def letterCombinations(self, digits):
            if len(digits) == 0: return []
            res = []
            dic = {"2":["a", "b", "c"], "3":["d","e","f"], "4":["g", "h", "i"],
                   "5":["j","k","l"], "6":["m","n","o"], "7":["p","q","r","s"], 
                   "8":["t","u","v"], "9":["w","x","y","z"]}
            def func(digits, combine, res, d):
                if len(digits)==0: 
                    res.append(combine)
                    return
                else:
                    for char in d[digits[0]]:
                        func(digits[1:], combine+char, res, d)
            func(digits, "", res, dic)
            return res

    # 39. 组合总和
    def combinationSum(self, candidates, target):
        res = []
        def func(cand, pos, tar, path, cursum, res):
            if cursum == tar: 
                res.append(path)
                return
            elif cursum > tar: return
            else:
                for i in range(pos,len(cand)):
                    if cand[i] + cursum <= tar:
                        func(cand, i, tar, path+[cand[i]], cursum + cand[i], res)
                    else: break
        func(candidates.sort(), 0, target, [], 0, res)
        return res
    
    # 40.组合总和II    
    def combinationSum2(self, candidates, target):
        candidates.sort()
        res = []
        def func(cand, pos, tar, path, cursum, res):
            if cursum == tar:
                res.append(path)
                return
            elif cursum > tar: return
            else:
                i = pos
                while i < len(cand):
                    if cand[i] + cursum <= tar:
                        func(cand, i+1, tar, path+[cand[i]], cursum+cand[i], res)
                        newi = i + 1
                        while newi < len(cand):
                            if cand[i] == cand[newi]: newi+=1
                            else:break
                        i = newi
                    else:break
        func(candidates, 0, target, [], 0, res)
        return res

    # 131. 分割回文串
    # 偶写的基础班，妹有剪枝
    def partition(self, s):
        res = []
        def ispalindrome(s):
            left, right = 0, len(s)-1
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True
        def backtracking(s,path,res):
            if s == "":res.append(path)
            else:
                for i in range(1, len(s)+1):
                    if ispalindrome(s[0:i]):
                        backtracking(s[i:], path[:]+[s[0:i]], res)
        backtracking(s,[],res)
        return res
    
    # 93. 复原 IP 地址
    def restoreIpAddresses(self, s):
        res = []
        def backtracking(address, path, n, res):
            if n == 0:
                if address == "":
                    res.append(".".join(path))
                return 
            if len(address) > 3*n or len(address) < n:
                return
            else:
                if address[0] == "0":
                    backtracking(address[1:], path+[address[0]], n-1, res)
                else:
                    for i in range(1,min(len(address)+1,4)):
                        if int(address[:i]) <= 255:
                            backtracking(address[i:], path+[address[:i]], n-1, res)
        backtracking(s,[],4,res)
        return res
         
    # 78. 子集
    def subsets(self, nums):
        res = []
        def backtracking(nums, res, path):
            if len(nums) == 0:
                res.append(path)
                return
            else:
                backtracking(nums[1:], res, path[:])
                backtracking(nums[1:], res, path[:]+nums[:1])
        backtracking(nums, res, [])
        return res

    def subsets1(self, nums):
        res = []
        def backtracking(nums, res, path):
            res.append(path)
            for i in range(len(nums)):
                backtracking(nums[i+1:], res, path+[nums[i]])
        backtracking(nums, res, [])
        return res
    
    # 79. 子集二    
    def subsetsWithDup(self, nums):
        nums.sort()
        res = []
        def backtracking(nums, res, path, startindex):
            res.append(path)
            cur = None
            for i in range(startindex, len(nums)):
                if nums[i] != cur:
                    backtracking(nums, res, path+[nums[i]], i+1)
                    cur = nums[i]
        backtracking(nums, res, [], 0)
        return res 
    
    # 491. 递增子序列
    # 注意这一道题和上一道题的去重方法不一样，上一道题的nums是进行排序了的，所以for循环的时候如果num[i]使用了一次之后，只需要用cur记录下来，
    # 后面比它大的数是一定没有使用的，从而达到去重目的。
    # 但是这题的nums是不能进行排序的，所以后面遇到的元素可能为for循环之前使用过的任一元素，因此要用集合把使用过的元素保存下来。
    def findSubsequences(self, nums):
        res = []
        def backtracking(nums, res, path, pre):
            if len(path) >= 2:
                res.append(path)
            used = set()
            for i in range(len(nums)):
                if nums[i] not in used and nums[i] >= pre:
                    backtracking(nums[i+1:], res, path+[nums[i]], nums[i])
                    used.add(nums[i])

        backtracking(nums, res, [], float('-inf'))
        return res
    
    # 46. 全排列
    def permute(self, nums):
        res = []
        path = [None]*len(nums)
        def backtracking(nums, path, res):
            if len(nums) == 0:
                res.append(path)
                return
            for pos in range(len(path)):
                if path[pos] == None:
                    path[pos] = nums[0]
                    backtracking(nums[1:], path[:], res)
                    path[pos] = None
        backtracking(nums, path[:], res)
        return res
    # 47. 全排列2
    def permuteUnique(self, nums):
        nums.sort()
        res = []
        def backtracking(nums, used, path, res):
            if len(path) == len(nums):
                res.append(path)
                return
            cur = None
            for i in range(len(nums)):
                if not used[i] and nums[i] != cur:
                    used[i] = True
                    backtracking(nums, used, path[:]+[nums[i]], res)
                    used[i] = False
                    cur = nums[i]
        backtracking(nums, [False]*len(nums), [], res)
        return res
    
    # 332. 重新安排行程
    # 注意这样写找了所有可以使用的行程，但是题目只需要一个就可以了
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        res = []
        def backtracking(tickets, used, cur_pos, res, path):
            if len(path) == len(tickets) + 1:
                res.append(path)
                return True
            for i in range(len(tickets)):
                if not used[i] and tickets[i][0] == cur_pos:
                    used[i] = True
                    find = backtracking(tickets, used[:], tickets[i][1], res, path+[tickets[i][1]])
                    used[i] = False
                    if find: return True
            return res
        tickets.sort()
        backtracking(tickets, [False]*len(tickets), "JFK", res, ["JFK"])
        return res[0]

    # 51. N 皇后
    # chessboard = [["."]*n]*n
    def solveNQueens(self, n):
        if n == 1: return [["Q"]]
        if n <= 3: return []
        res = []
        chessboard = [["." for i in range(n)] for j in range(n)]
        def check(pos, chessboard, n):
            x,y = pos
            for i in range(n):
                if chessboard[x][i] == "Q" or chessboard[i][y] == "Q":
                    return False
            a, b = (x-y, 0) if x > y else (0, y-x)
            while a < n and b < n:
                if chessboard[a][b] == "Q":
                    return False
                a += 1
                b += 1
            if x + y < n:
                a, b = (x+y, 0)
            else:
                a, b = (n-1,x+y+1-n)
            while a >= 0 and b < n:
                if chessboard[a][b] == "Q":
                     return False
                a -= 1
                b += 1
            return True
        def backtracking(n, res, chessboard, line):
            if line >= n:
                res.append(["".join(copy.deepcopy(chessboard)[i]) for i in range(n)])
                return
            else:
                for i in range(n):
                    if check((line, i), chessboard, n):
                        chessboard[line][i] = "Q"
                        backtracking(n, res, chessboard, line+1)
                        chessboard[line][i] = "."
        
        backtracking(n, res, chessboard, 0)
        return res


    # 37. 解数独
    def solveSudoku(self, board):
        def check(x, y, board, num):
            for i in range(9):
                if board[x][i] == num or board[i][y] == num:
                    return False
            x = x - x%3
            y = y - y%3
            for i in range(3):
                for j in range(3):
                    if board[x+i][y+j] == num:
                        return False
            return True
        def backtracking(x,y,board):
            if x == 9: return True
            if y == 8:
                nextx, nexty = x+1, 0
            else:
                nextx, nexty = x, y+1
            if board[x][y] == ".":
                for num in range(1,10):
                    if check(x,y,board,str(num)):
                        board[x][y] = str(num)
                        if backtracking(nextx, nexty, board): return True
                        board[x][y] = "."
            else:
                if backtracking(nextx, nexty, board): return True
        backtracking(0,0,board)                    