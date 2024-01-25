from collections import deque
from math import floor, ceil
from collections import deque, Counter
import heapq

class MyQueue(object):
    def __init__(self):
        self.stackone = [] #下标0为队首，越大排越后面
        self.stacktwo = [] #下标
    
    def push(self,x):
        self.stackone.append(x)
    
    def pop(self):
        if len(self.stacktwo)==0:
            for i in range(len(self.stackone)):
                self.stacktwo.append(self.stackone.pop())
        
        return self.stacktwo.pop()

    def peek(self):
        if len(self.stacktwo)==0:
            for i in range(len(self.stackone)):
                self.stacktwo.append(self.stackone.pop())
        return self.stacktwo[-1]
    
    def empty(self):
        return True if len(self.stackone)+len(self.stacktwo) == 0 else False




class MyStack(object):

    def __init__(self):
        self.tag=0
        self.quene0 = deque()
        self.quene1 = deque()
        self.quenelist=[self.quene0,self.quene1]
        # 只允许在右侧添加元素和在左侧删除元素

    def push(self, x):
        self.quenelist[self.tag].append(x)

    def pop(self):
        another = (self.tag+1)%2
        for _ in range(len(self.quenelist[self.tag])-1):
            self.quenelist[another].append(self.quenelist[self.tag].popleft())
        self.tag = another
        return self.quenelist[(another+1)%2].popleft()

    def top(self):
        another = (self.tag+1)%2
        for _ in range(len(self.quenelist[self.tag])-1):
            self.quenelist[another].append(self.quenelist[self.tag].popleft())
        tmp = self.quenelist[self.tag].popleft()
        self.quenelist[another].append(tmp)
        self.tag = another
        return tmp


    def empty(self):
        return True if len(self.quene1)+len(self.quene0) == 0 else False

class Solution(object):
    # 20.有效的括号
    def isValid(self, s):
        stack = [-1]
        p = ["(","[","{"]
        n = [")","]","}"]
        for char in s:
            for i in range(3):
                if char == p[i]:stack.append(i)
                if char == n[i]:
                    if stack.pop()!=i: return False
        return True if len(stack)==1 else False
    # 注意最后不是直接返回True，而是还需要查看栈的长度，否则无法判断出现多余正括号的情况

    # 1047. 删除字符串中的所有相邻重复项
    def removeDuplicates(self, s):
        l=[0]
        for char in s:
            if  char == l[-1]:
                l.pop()
            else:l.append(char)
        return "".join(l[1:])
    
    # 150. 逆波兰表达式（后缀表达式）求值
    def evalRPN(self, tokens):
        x = ["+","-","*","/"]
        stack=[]
        for char in tokens:
            if char in x:
                a = stack.pop()
                b = stack.pop()
                if char=="+":
                    stack.append(a+b)
                elif char=="-":
                    stack.append(b-a)
                elif char=="*":
                    stack.append(a*b)
                elif char=="/":
                    stack.append(int(b/a))
            else:stack.append(int(char))
        return stack[0]
    
    # 239. 滑动窗口最大值
    def maxSlidingWindow(self, nums, k):
        """ 
        这里使用一个双向队列按序存储所有可能成为最大值的数 
        对于窗口中的某一个数，在其左侧并且比这个数小的数，一定不可能成为最大值
        因此可以构成一个从小到大排列的队列，队尾为最小值，队首为最大值，也即当前窗口中所有数的最大值
        nums[left]:即将从窗口中移除的数：
            如果这个数等于队首的数（最大值）,则移除队首
            如果这个数不等于队首的数，这个数本来就是窗口中最左侧的数，
                因此窗口中的最大值（队首的数）一定在其右侧且一定比这个数大，所以这个数本来就不是一个可能成为最大值的数
            
        """
        inmax=deque()
        out=[]
        for i in range(k):
            while inmax and nums[i]>=inmax[0]:
                inmax.popleft()
            inmax.appendleft(nums[i])
        
        out.append(inmax[-1])
        left,right=0,k
        while right<len(nums):
            while inmax and nums[right]>=inmax[0]:
                inmax.popleft()
            inmax.appendleft(nums[right])
            if nums[left]==inmax[-1]:inmax.pop()
            out.append(inmax[-1])
            left+=1
            right+=1
        return out
    
    # 前k个高频元素
    # 优先级队列
    def topKFrequent_1(self, nums, k):
        map_, pri_que = Counter(nums), []
        for (key, freq) in map_.items():
            heapq.heappush(pri_que,(freq,key))
            if len(pri_que)>k:heapq.heappop(pri_que)
        return [heapq.heappop(pri_que)[1] for _ in range(k)]
    

    
a = Solution()
print(a.topKFrequent(nums=[1,1,1,7,7,3],k=2))