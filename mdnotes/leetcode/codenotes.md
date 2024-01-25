## 2. addtwonumbers
### 递归方法
- python  

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1:ListNode, l2:ListNode):
        [Q,R] = divmod(l1.val+l2.val, 10)
        temp = ListNode()
        temp.val = R
        if(l1.next != None):
            l1.next.val = l1.next.val + Q
            if(l2.next != None):temp.next = self.addTwoNumbers(l1.next,l2.next)
            if(l2.next != None) else self.addTwoNumbers(l1.next,ListNode())
        else:
            if(l2.next != None):
                l2.next.val = l2.next.val + Q 
                temp.next = self.addTwoNumbers(ListNode(),l2.next)
            else:
                if(Q!=0):
                    temp.next = ListNode()
                    temp.next.val = Q
        return temp
```

### 使用hashmap
**hash表的搜索复杂度为1**
```python
    class Solution(object):
    def twoSum(self, nums, target):
        records = dict()
        # 用枚举更方便，就不需要通过索引再去取当前位置的值
        for idx, val in enumerate(nums):
            if target - val not in records:
                records[val] = idx
            else:
                return [records[target - val], idx] 
            # 如果存在就返回字典记录索引和当前索引
```

## 3. longestunrepeatedsubstr
* 思路：利用**滑动窗口**进行搜索
- 不用字典的解法
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s_len = len(s)
        if(s_len == 0):
            return 0
        else:
            max_length = 1
            i = 0
            j = 1
            while j < s_len:
                tag = 1  # 标记s[j]是否可以加入到无重复字串中
                temp_length = j - i
                for k in range(i, j):
                    if(s[k] == s[j]):
                        tag = 0
                        i = k + 1
                        break
                if(tag == 1):
                    temp_length = temp_length + 1
                max_length = max(max_length, temp_length)
                j = j + 1
        return max_length
```
有无改进？
- 加入字典dict
```python
    def lengthOfLongestSubstring(self, s: str) -> int:
        res, i, maxlen = {}, 0, 0
        for j in range(len(s)):
            if s[j] in res:
                if res[s[j]] >= i:
                    i = res[s[j]] + 1
            res[s[j]] = j
            maxlen = max(maxlen, j-i+1)
        return maxlen
```
## 4.寻找两个正序数组的中位数
```python
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        nums = nums1 + nums2
        m,n = len(nums1), len(nums2)
        for i in range(m,m+n):
            for j in range(i,0,-1):
                if(nums[j]<nums[j-1]):nums[j],nums[j-1]=nums[j-1],nums[j]
        print(nums)
        return 0.5*(nums[int((m+n)/2)]+nums[int((m+n)/2)-1]) if ((m+n)%2 == 0) else nums[int((m+n-1)/2)]
t = Solution()
a = [1,2,3]
b = [7,8,9]
print(t.findMedianSortedArrays(b,a))
```
## 5.最长回文子串
* 中心扩散法
````python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        out = ''
        length = len(s)
        for i in range(length):
            j = k = i
            while True:
                if(j>=0 and s[j]==s[i]):j=j-1
                else:break
            while True:
                if(k<length and s[k]==s[i]):k=k+1
                else:break
            while True:
                if(j>=0 and k<length):
                    if(s[j]==s[k]):
                        j=j-1
                        k=k+1
                    else:break
                else:break
            if(k-j-1>len(out)):out=s[j+1:k]
        return out
S = Solution()
print(S.longestPalindrome('cbbd'))
````
## 6.N字形变换
- 关键点在于发现规律，以numRows=4为例，依次遍历字符串所有元素，它们所属的行数的分别为1234321234321...
````python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2: return s
        res = ["" for _ in range(numRows)]
        i, flag = 0, -1
        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1: flag = -flag
            i += flag
        return "".join(res)
````

## 11.最大装水体积
* 关键点在于双指针思路的指针移动方式，这里作解释
设当前左右指针分别为left，right，不失一般性，可以假设右侧池壁更高，即 
$$height[left] < height[right]$$
设容积最大的容器的左右指针分别为：$left^*$和$right^*$，则必有如下关系：
$$left \leq left^*\le right^* \le right$$
如果一个i不可能成为池壁，则我们可以把这个位置从搜索去掉，再去寻找最大容积。
我们假设left为容积最大时候的左侧池壁，则有：
$$V^*=(right^*-left)\times min(height[left],height[right^*])$$ 
$$\le V = (right-left)*height[left]$$
而这个体积已经记录在V了，所以left指针对应的位置可以从池壁可能中去掉了。
综上，每次移动矮池壁对应的指针，一定可以找到最大容积。





