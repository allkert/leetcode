#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include<numeric>

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
                int next = (current + k) % n;
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
    int firstMissingPositive(vector<int>& nums) {
        
    }
};