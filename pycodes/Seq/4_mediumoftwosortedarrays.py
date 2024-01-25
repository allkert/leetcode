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