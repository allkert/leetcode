#include<iostream>
#include<vector>
#include <string>
#include<cmath>

using namespace std;

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

    // 977. 有序数组的平方
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 0, j = nums.size()-1;
        for(int pos = j; pos >= 0; pos--){
            if(abs(nums[i])>abs(nums[j])){
                res[pos] = pow(nums[i],2);
                i++;
            }
            else{
                res[pos] = pow(nums[j],2);
                j--;
            }
        }
        return res;
    }

    // 209 长度最小的子数组
    // 双指针
    int minSubArrayLen(int target, vector<int>& nums) {
        int windowsum = 0;
        int i = 0;
        int res = INT_MAX;
        int winlength = 0;
        for(int j = 0; j < nums.size(); j++){
            windowsum += nums[j];
            winlength++;
            while(windowsum >= target){
                res = res > winlength? winlength:res;
                windowsum -= nums[i++];
                winlength--;
            }
        }
        return res == INT_MAX? 0 : res;
    }

    // 59.螺旋矩阵Ⅱ
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i = 1;
        int left = 0, up = 0;
        int right = n - 1, down = n-1;
        int direction = 0;
        while( i <= pow(n, 2)){
            switch (direction%4)
            {
            case 0:
                for(int j = left; j <= right; j ++){
                    res[up][j] = i++;
                }
                up++;
                break;
            case 1:
                for(int j = up; j <= down; j++){
                    res[j][right] = i++;
                }
                right--;
                break;
            case 2:
                for(int j = right; j >= left; j--){
                    res[down][j] = i++;
                }
                down--;
                break;
            case 3:
                for(int j = down; j >= up; j--){
                    res[j][left] = i++;
                }
                left++;
                break;
            }
            direction++;
        }
        return res;
    }
};
    

int main(){
    Solution a = Solution();
    vector<vector<int>> out = a.generateMatrix(4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << out[i][j] << ' ';
        }
        cout  << endl;
    }

}