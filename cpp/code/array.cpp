#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    // 704. 二分查找，闭区间
    int search_closed(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        int mid=0;
        while (i<=j)
        {
            mid = (i+j)/2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                i = mid + 1;
            }
            else{
                j = mid - 1;
            }
        }
        return -1;
    }

    // 704. 二分查找，闭区间
    int search_open(vector<int>& nums, int target){
        int left = 0, right = nums.size();
        int mid;
        while(left<right){
            mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>target)
                right = mid;
            else
                left = mid + 1;
        }
        return -1;
    }

    // 27. 移除元素
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int i = 0, j = 0;
        while ( j < nums.size()){
            if (nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
    int removeElement1(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if (nums[j] != val){
                nums[i] = nums[j];
                i++;
            }    
        }
        return i;
    }

    // 26 删除有序数组中的重复项
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }

    // 283.移动零
    void moveZeroes(std::vector<int>& nums) {
        int i = 0;
        for(int j = 0; j<nums.size(); j++){
            if(nums[j]){
                if(i!=j){
                    nums[i] = nums[j];
                    nums[j] = 0;
                }
                i++;
            }
        }
    }   
};
    

int main(){
    Solution a = Solution();
    std::vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    int target = 100;
    std::cout << a.search_open(nums, target) << std::endl;
    return 0;
}