# class Solution(object):
#     def twoSum(self, nums, target):
#         indcies = []
#         nums_length = len(nums)
#         for i in range(nums_length-1):
#                 for j in range(nums_length-1,i,-1):
#                     if nums[i]+nums[j] == target:
#                         indcies.append(i)
#                         indcies.append(j)
#                         break
#         return indcies
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
print(Solution().twoSum(nums=[1,2,7,8,11,15],target=9))
    