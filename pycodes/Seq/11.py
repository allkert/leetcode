def maxArea(self, height):
    V = 0
    left = 0
    right = len(height)-1
    while(left<right):
        if height[left]<height[right]:
            V = max(V,height[left]*(right-left))
            left = left+1
        else:
            V = max(V,height[right]*(right-left))
            right = right-1