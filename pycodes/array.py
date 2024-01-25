from collections import Counter
from collections import defaultdict
import numpy

class Binarysearch(object):
    def _34(self, nums, target):
        left=mid=0
        right=len(nums)-1
        [first, last] = [-1,-1]
        while left<=right:
            mid = (left+right)//2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                first = mid
                right = mid -1
        left, right = 0, len(nums)-1
        while left<=right:
            mid = (left+right)//2
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            else:
                last = mid
                left = mid + 1
        return [first,last]


    
# 35 搜索插入位置
    #闭区间写法 
    def _35_1(self, nums, target):
        left, right =0, len(nums)-1
        while left<=right:
            mid = (right+left)//2
            if nums[mid] < target:
                left = mid+1
            elif nums[mid] > target: right = mid-1
            else: return mid
        return right+1
    # 开区间写法
    def _35_2(self, nums, target):
        left,mid,right = 0,0,len(nums)
        while left < right:
            mid=(left+right)//2
            if nums[mid]>target:
                right=mid
            elif nums[mid]<target:
                left=mid+1
            else:return mid
        return  left
    
# 704 二分查找
    # 闭区间写法
    def _704_1(self, nums, target):
        left, right =0, len(nums)-1
        mid = (right+left)//2
        while left<=right:
            if nums[mid] < target:
                left = mid+1
            elif nums[mid] > target: right = mid-1
            else: return mid
            mid = (right+left)//2
        return -1
    # 左闭右开区间写法
    def _704_2(self, nums, target):
        left, right = 0, len(nums)
        mid = (left+right)//2
        while(left<right):
            if nums[mid]<target:
                left = mid+1
            elif nums[mid]>target:
                right = mid
            else: return mid
            mid = (left+right)//2
        return -1
    
# 69. x 的平方根
    # 利用二分查找的思路
    def _69_1(self,x):
        left, right = 0,46340
        while left<=right:
            mid = (left+right)//2
            if mid**2<x:
                left=mid+1
            elif mid**2>x:
                right=mid-1
            else: return mid
        return left-1
    
    # 牛顿迭代法找零点
    def _69_2(self,x):
        if x==0: return 0
        C = x0 = float(x)
        while True:
            temp = 0.5 * (x0 + C / x0)
            if abs(temp-x0)<1e-7:break
            x0 = temp
        return int(x0)

class DoublePointer():
# 367. 有效的完全平方数
    def _367(self, num):
        left, right = 0,46340
        while left<=right:
            mid = (left+right)//2
            if mid**2<num:
                left=mid+1
            elif mid**2>num:
                right=mid-1
            else: return True
        return False

# 27. 移除元素
    # 技巧是利用双指针进行元素覆盖
    def _27(self, nums, val):
        j = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]
                j = j + 1
        return nums

# 26. 删除重复元素
    def _26(self,nums):
        i = 0
        for j in range(1,len(nums)):
            if nums[i] != nums[j]:
                nums[i+1] = nums[j]
                i+=1
        return i+1

# 283.移动零
    def _283(self,nums):
        i = 0
        j = 0
        while j<len(nums):
            if nums[j]:
                if i!=j:nums[i],nums[j]=nums[j],0
                i += 1
            j += 1
        return nums

# 844.比较含退格的字符串
    """ 
    这题能想到的思路是对的，但是实现过程出了问题，
    没有想到用while循环去找到待比较的字符的位置，导致用if语句用的特别复杂特别乱
    """
    def _844(self,s,t):
        ls,lt = len(s)-1,len(t)-1
        bs_num_s = bs_num_t = 0
        while ls >= 0 or lt >= 0:
            while ls >= 0:
                if s[ls] == "#":
                    bs_num_s += 1
                    ls -= 1
                elif bs_num_s: 
                    bs_num_s -= 1
                    ls -= 1
                else:break
            while lt >= 0:
                if t[lt] == "#":
                    bs_num_t += 1
                    lt -= 1
                elif bs_num_t:
                    bs_num_t -= 1
                    lt -= 1
                else:break
            S = "" if ls < 0 else s[ls]
            T = "" if lt < 0 else t[lt]
            if S != T:return False
            ls -= 1
            lt -= 1
        return True

# 977. 有序数组的平方
    # 复杂度为o(N),需要注意的是，这里不能使用原地操作，需要新建一个数组来储存排序之后的元素
    # 同时，python  a=b
    # 对于变量来说"="是赋值操作，此时改变a不会导致b发生改变
    # 但是对于代表列表等其他类型，改变a会导致b发生改变，如a[1]=3会导致b[1]发生改变，类似于指针的传递
    def _977(self, nums):
        left, right = 0, len(nums)-1
        pos = right
        temp = [0]*(pos+1)
        while left <= right:
            if abs(nums[left]) < abs(nums[right]):
                temp[pos] = nums[right]**2
                right -= 1
            else:
                temp[pos] = nums[left]**2
                left += 1
            pos -= 1
        nums = temp
        return temp

class SlideWindow():
# 209. 长度最小的子数组
    def _209(self, target, nums):
        left,right = 0,0
        length = len(nums)
        find = False
        sum = 0
        while right < len(nums):
            if length == 1 and find: return 1
            elif sum+nums[right] >= target:
                find = True
                length = min(right-left+1,length)
                sum -= nums[left]
                left += 1
            else:
                sum += nums[right]
                right += 1
        return length if find else 0

# 904. 水果成篮
    # 虽然用了滑动窗口，但是这是我的垃圾代码
    def _904_1(self, fruits):
        length = len(fruits)
        if length <= 2: return length
        pos1,pos2 = 0,1
        while pos2 < length:
            if fruits[pos2] == fruits[pos1]:
                pos1 = pos2
                pos2 += 1
            else: break
        i, j = 0, pos1
        kinds = 1
        sum = 0
        while j < len(fruits):
            while kinds <= 2 and j < len(fruits):            
                if fruits[j] == fruits[pos1]:
                    pos1 = j
                    j += 1
                elif fruits[j] == fruits[pos2]:
                    pos2 = j
                    j += 1
                else:
                    kinds += 1
            sum = max(sum,j-i)
            kinds -= 1
            if pos1 < pos2:
                i = pos1 + 1
                pos1 = j
            else:
                i = pos2 + 1
                pos2 = j
        return sum

    # 使用哈希表！！！！！！！官方题解
    # 但是这种方法的性能并不是很好，不如我的垃圾代码好，甚至差的有点远，猜测应该是Counter太消耗时间了，垃圾python
    def _904_2(self, fruits):
        cnt = Counter()
        left = sum = 0
        for right, fruit in enumerate(fruits):
            cnt[fruit] += 1
            while len(cnt) > 2:
                cnt[fruits[left]] -= 1
                if not cnt[fruits[left]]:
                    cnt.pop(fruits[left])
                left += 1
            sum = max(sum, right-left+1)
        return sum
    
    # 评论区看到的一种方法
    def _904_3(self, fruits):
        
        pass
# 76.  最小覆盖子串
    # 这是我的垃圾代码，滑动窗口思路
    def minWindow1(self, s, t):
        def check(a:dict)->bool:
            for key in a:
               if a[key] > 0:
                   return False
            return True 
        tt = {}
        # o(m)
        for char in t:
            if char in tt:
                tt[char]+=1
            else: tt[char]=1
        left, right = 0,0
        l,r = 0, len(s)
        find = False
        while right<len(s):
            while not check(tt) and right < len(s):
                if s[right] in tt:
                    tt[s[right]] -= 1
                right += 1
            if check(tt): find = True
            while check(tt):
                if s[left] in tt:
                    tt[s[left]] += 1
                left += 1
            
            if right-left < r - l:l,r = left, right
        return s[l-1:r] if find else ""
    
    # 网上代码，滑动窗口
    def minWindow2(self, s, t):
        need=defaultdict(int)
        for char in s:need[char]+=1
        needCnt = len(t)

        res = (0,float('inf'))
        i=0
        for j, c in enumerate(s):
            if need[c]>0:needCnt-=1
            need[c]-=1
            if needCnt==0:#找到一个窗口包含所有字符串
                while True:#滑动左指针找到最小窗口
                    c = s[i]
                    if need[c]==0:break#找到最小窗口
                    i+=1
                    need[c]+=1
                if j-i<res[1]-res[0]:#记录结果
                    res=(i,j)
                need[s[i]]+=1  #步骤三：i增加一个位置，寻找新的满足条件滑动窗口
                needCnt+=1
                i+=1
        return '' if res[1]>len(s) else s[res[0]:res[1]+1]
class SimulateBehavior():
    def _59_1(self,n):
        # 我的思路是根据方向进行判断，如果下一个位置已经被填充，则改变方向，或者超出矩阵范围改变方向
        total = n**2
        m = [[0]*n for i in range(n)]
        # right:0, down:1, left:2, up:3
        direction = 0
        k = 1
        i,j= 0,0
        while k<=total:
            direction = direction%4
            while True:
                nexti,nextj=i,j
                if m[i][j]==0:
                    m[i][j] =k
                    k += 1
                if direction==0: 
                    if j+1<n: 
                        nextj=j+1
                    else: break
                elif direction==1:
                    if i+1<n: nexti=i+1
                    else:break
                elif direction==2:
                    if j-1>=0:nextj=j-1
                    else: break
                elif direction==3:
                    if i-1>=0:nexti=i-1
                    else:break
                if m[nexti][nextj] == 0:
                    i,j = nexti, nextj
                else:break
            direction += 1
        return m

    def _59_2(self,n):
        # 另外一种思路是改变边界，在每次转向之后修改边界，这样就不需要判断是否超出边界
        if n == 1: return [1]
        i=1
        left,up,right,down=0,0,n-1,n-1
        direction = 0
        m = [[0]*n for k in range(n)]
        while i<=n**2:
            direction = direction%4
            if direction==0:
                for j in range(left,right+1):
                    m[up][j] = i
                    i += 1
                up += 1
            elif direction==1:
                for j in range(up,down+1):
                    m[j][right]=i
                    i+=1
                right-=1
            elif direction==2:
                for j in range(right,left-1,-1):
                    m[down][j]=i
                    i+=1
                down-=1
            elif direction==3:
                for j in range(down,up-1,-1):
                    m[j][left]=i
                    i+=1
                left+=1
            direction += 1
        return m 
        




