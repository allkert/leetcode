from collections import Counter
from collections import defaultdict
import math

class sloution():
    def _242(self, s, t):
        return Counter(s)==Counter(t)

    def _349(self, nums1, nums2):
        return [x for x in set(nums1) if x in set(nums2)]
    
    def _202(self, n):
    # 快乐数
        num_set=[n]
        while True:
            n = sum([j**2 for j in [n//10**(i)%10 for i in range(int(math.log(n,10))+1)]])
            if n == 1:return True
            elif n in num_set:return False
            num_set.append(n)
    
    # 四数相加
    def _454(self, nums1, nums2, nums3, nums4):
        dic1 = defaultdict(int)
        dic2 = defaultdict(int)
        N = 0
        for (i,j) in zip(nums1,nums2):
            for (m,n) in zip(nums3,nums4):
                dic1[i+m]+=1
                dic2[j+n]+=1
        for key in dic1.keys():
            N+=dic1[key]*dic2[-key]
        return N

    # 赎金信
    def _383(self, ransomNote, magazine):
        a, b = Counter(ransomNote),Counter(magazine)
        for key in a:
            if key not in b:return False
            elif a[key] > b[key]: return False
        return True

    # 三数之和
    """ 
        第一种方法：使用哈希表，注意关键点是去重，以及使用Counter的好处，但是实际上效果很差，其实这道题不适合使用哈希表
    """
    def _15_1(self, nums):
        nums.sort()
        length=len(nums)
        sum_0=[]
        nums_dict=Counter(nums)
        for i in range(length):
            if nums[i]>0:break
            j=i+1
            while j<length:
                if -(nums[i]+nums[j]) in nums_dict:
                    index = nums.index(-(nums[i]+nums[j]))
                    if index+nums_dict[-(nums[i]+nums[j])]-1>j:
                        if [nums[i],nums[j],nums[index]] not in sum_0:
                            sum_0.append([nums[i],nums[j],nums[index]])
                j+=nums_dict[nums[j]]
        return sum_0
    
    """ 第二种思路：使用双指针 """
    def _15_2(self, nums):
        nums.sort()
        print(nums)
        sum_0=[]
        for i in range(len(nums)-2):
            if nums[i]+nums[-1]+nums[-2]<0:continue
            if nums[i]>0:break
            if i>0 and nums[i]==nums[i-1]:continue
            left, right=i+1,len(nums)-1
            while left<right:
                s = nums[i] + nums[left] + nums[right]
                if s>0:
                    right-=1
                    while nums[right]==nums[right+1] and left<right:
                        right-=1
                elif s<0:
                    left+=1
                    while nums[left]==nums[left-1] and left<right:
                        left+=1
                else:
                    sum_0.append([nums[i],nums[left],nums[right]])
                    left+=1
                    right-=1
                    while nums[left]==nums[left-1] and left<right:
                        left+=1
                    while nums[right]==nums[right+1] and left<right:
                        right-=1
        return sum_0
    
    def _19(self, nums, target):
        nums.sort()
        n = len(nums)
        result = []
        for i in range(n):
            if nums[i] > target and nums[i] > 0 and target > 0:# 剪枝（可省）
                break
            if i > 0 and nums[i] == nums[i-1]:# 去重
                continue
            for j in range(i+1, n):
                if nums[i] + nums[j] > target and target > 0: #剪枝（可省）
                    break
                if j > i+1 and nums[j] == nums[j-1]: # 去重
                    continue
                left, right = j+1, n-1
                while left < right:
                    s = nums[i] + nums[j] + nums[left] + nums[right]
                    if s == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left+1]:
                            left += 1
                        while left < right and nums[right] == nums[right-1]:
                            right -= 1
                        left += 1
                        right -= 1
                    elif s < target:
                        left += 1
                    else:
                        right -= 1
        return result


            


s = sloution()        
print(s._15_2([-1,0,1,2,-1,-4,-2,-3,3,0,4]))
