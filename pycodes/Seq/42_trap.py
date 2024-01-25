class Solution(object):   
    def trap2(self,height):
        left,right = 0, len(height)-1
        newleft,newright = 0,len(height)-1
        V = 0
        while newleft<newright:
            if height[left]<height[right]:
                newleft+=1
            else:
                newright-=1
            if height[newleft]>height[left]:
                V += (newleft-left-1)*min(height[left],height[newleft])-sum(height[left+1:newleft])
                left = newleft
            if height[newright]>height[right]:
                V += (right-newright-1)*min(height[newright],height[right])-sum(height[newright+1:right])
                right = newright
        return V if left==right else V+min(height[left],height[right])*(right-left-1)-sum(height[left+1:right])
            


a = Solution()
print(a.trap2([2,0,2]))
