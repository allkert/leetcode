#include<iostream>
#include<vector>
#include <string>

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
    int removeDuplicates(vector<int>& nums) {
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
    void moveZeroes(vector<int>& nums) {
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

    // 844. 比较含退格的字符串
    // 方法一： 使用栈
    string build(string str){
        string ret;
        for(char ch : str){
            if(ch != '#'){
                ret.push_back(ch);
            }
            else if (!ret.empty()){
                ret.pop_back();
            }
        }
        return ret;
    }
    bool backspaceCompare1(string s, string t) {
        return build(s) == build(t);
    }

    // 方法二：双指针
    // 注意cpp不像python一样使用缩进来标明代码块！！！最好加上大括号。
    bool backspaceCompare2(string s, string t) {
        int ls = s.size()-1, lt = t.size()-1;
        int skips = 0, skipt =0;
        while(ls >= 0 || lt >=0){
            while(ls >= 0){
                if (s[ls] == '#')
                    skips++,ls--;
                else if(skips > 0)
                    skips--,ls--;
                else break;
            }
            while(lt >= 0){
                if (t[lt] == '#')
                    skipt++,lt--;
                else if(skipt > 0)
                    skipt--,lt--;
                else break;
            }
            if(ls >= 0 && lt>=0){
                if(s[ls] != t[lt]) return false;
            }
            else{
                if(ls >= 0 || lt >=0) return false;
            }
            ls--,lt--;
        }
        return true;
    }
};
    

int main(){
    Solution a = Solution();
    a.backspaceCompare2("ab#c","ad#c");
}