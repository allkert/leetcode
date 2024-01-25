## 二分查找
### 704 二分查找
二分查找使用的条件：
1. 有序排列 2. 无重复元素，否则返回下标不唯一
ps: 应该注意的是二分查找的两种写法，一种是闭区间写法，一种是左闭右开的写法，两种写法的right的赋值不一样。
`````python
class Solution(object):
    # 闭区间写法
    def search(self, nums, target):
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
    def search2(self, nums, target):
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
`````

### 35 搜索插入位置
利用二分查找改写，但是效率很差，占用内存很高(其实还可以)
```python
class Solution(object):
    def searchInsert(self, nums, target):
        left, right =0, len(nums)-1
        mid = 0
        while left<=right:
            mid = (right+left)//2
            if nums[mid] < target:
                left = mid+1
            elif nums[mid] > target: right = mid-1
            else: return mid
        return left
```

### 34 在排序数组中查找元素的第一个和最后一个位置
注意要用两次二分查找，以及在等于情况下的处理方式。
```python
    def searchRange(self, nums, target):
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
```

### 69. x 的平方根
```python
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
```

### 367. 有效的完全平方数
`````python
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
`````
## 双指针
### 27. 移除元素
```python
    def _27(self, nums, val):
        j = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]
                j = j + 1
        return nums
```