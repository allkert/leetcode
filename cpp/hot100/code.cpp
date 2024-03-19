#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include <map>

using namespace std;

class Solution{
public:


    // 438 找到字符串中所有字母异位词
    /* 容器可以直接比较，不用自己写函数比较了！！！！！ */
    vector<int> findAnagrams(string s, string p) {
        vector<int> countp(26);
        for(char ch: p){
            countp[ch-'a']++;
        }
        vector<int> count(26);
        vector<int> res;
        for(int left = 0, right = 0; right < s.size(); right++){
            count[s[right] - 'a']++;
            if(count == countp){
                res.push_back(left);
            }
            if(right - left + 1 == p.size()){
                count[s[left] - 'a']--;
                left++;
            }
        }
        return res;
    }

    // 560. 和为 K 的子数组
    // 参考答案，使用前缀和加哈希表优化
    /* 
        map<int, int> mp; // 前缀和 -> 该前缀和出现的次数
    */
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int count = 0;
        int pre = 0;
        for(int i = 0; i < nums.size(); i++){
            pre += nums[i];
            if(mp.find(pre-k) != mp.end()) count += mp[pre-k];
            mp[pre]++;
        }
        return count;
    }

    // 189. 轮转数组
    // 这种方法不是原地操作！
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> tmp(nums.end()-k, nums.end());
        for(vector<int>::iterator it = nums.begin(); it != nums.end()-k; it++){
            tmp.push_back(*it);
        }
        nums = tmp;
    }

    void rotate_Ref(vector<int>& nums, int k){
        k = k % nums.size();
        int count = gcd(k, nums.size());
        for(int start = 0; start < count; start++){
            int current = start;
            int prev = nums[start];
            do{
                int next = (current + k) % nums.size();
                swap(nums[next], prev);
                current = next;
            }while(start != current);
        }
    }

    // 238. 除自身以外数组的乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int multiAcc = 1;
        for(int i = 1; i < nums.size(); i++){
            res[i] = res[i-1]*nums[i-1];
        }
        for(int i = nums.size()-2; i >= 0; i--){
            multiAcc = multiAcc * nums[i+1];
            res[i] = res[i] * multiAcc;
        }
        return res;
    }

    // 41. 缺失的第一个正数
    int firstMissingPositive_Ref(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] != i + 1){
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                    break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1) return i + 1;
        }
        return nums.size()+1;
    }

    // 73. 矩阵置零
    void setZeroes(vector<vector<int>>& matrix) {
        // 用于判断第一列是否存在0
        int colTag = 1;
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0) colTag = 0;
        }
        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0) matrix[0][0] = 0;
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < matrix.size(); i++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i = 1; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if(colTag == 0){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }

    void setZeroesRef(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int colTag = 1;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0) colTag = 0;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = 1; j < n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if(colTag == 0) matrix[i][0] = 0;
        }
    }

    // 54. 螺旋矩阵
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int left = 0, up = 0;
        int right = matrix[0].size()-1, down = matrix.size()-1;
        int tag = 0;
        while(left <= right && up <= down){
            tag = tag % 4;
            if(tag == 0){
                for(int i = left; i <= right; i++){
                    res.push_back(matrix[up][i]);
                }
                up++;
            }
            else if(tag == 1){
                for(int i = up; i <= down; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(tag == 2){
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            else{
                for(int i = down; i >= up; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            tag++;
        }
        return res;
    }


    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int iBegin = 0, jBegin = 0;
        int len = m;
        while(len > 0){
            int x = iBegin, y = jBegin;
            for(int i = 0; i < len - 1; i++){
                int prev = matrix[m-1-y][x+i];
                int tmpy;
                for(int j = 0; j < 4; j++){
                    swap(prev, matrix[x+i][y]);
                    tmpy = m - 1 - (x + i);
                    x = y - i;
                    y = tmpy;
                }
            }
            iBegin++; jBegin++; len -= 2;
        }
    }

private:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

};

int main(){
    Solution s;
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    s.rotate(matrix);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << matrix[i][j] << ' ';
        }
        cout <<"---------------";
    }
}