#include<iostream>
#include<limits>
#include<math.h>
#include<vector>
#include<unordered_set>
#include <map>
#include <unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:

    // 242. 有效的字母异位词
    bool isAnagram(string s, string t) {
        int table[26];
        for(char ch:s){
            table[ch - 'a']++;
        }
        for(char ch:s){
            table[ch - 'a']--;
        }
        for(int times: table){
            if(times) return false;
        }
        return true;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num: nums2){
            if(nums_set.find(num) != nums_set.end()){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }

    // 202 快乐数
    int getsum(int num){
        int sum = 0;
        while(num){
            sum += pow(num % 10, 2);
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> a;
        while (true){
            if(n == 1){
                return true;
            }
            else{
                if(a.find(n) != a.end()){
                    return false;
                }
                else{
                    a.insert(n);
                }
            }
            n = getsum(n);
        }    
    }


    // 1. 两数之和
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            auto iter = a.find(target - nums[i]);
            if(iter != a.end()){
                return {iter->second, i};
            }
            a.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }

    // 454 四数相加Ⅱ
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D ){
        unordered_map<int, int> umap;
        for(int a:A){
            for(int b: B){
                umap[a+b]++;
            }
        }
        int res = 0;
        for(int c: C){
            for(int d:D){
                if(umap.find(-(c+d)) != umap.end()){
                    res += umap[-(c+d)];
                }
            }
        }
        return res;
    }
    
    // 383 赎金信
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazine_counter;
        for(char s: magazine){
            magazine_counter[s]++;
        }
        for(char s: ransomNote){
            unordered_map<char, int>::iterator it = magazine_counter.find(s);
            if(it == magazine_counter.end()){
                return false;
            }
            else{
                if(it->second == 0){
                    return false;
                }
                else{
                    it->second--;
                }
            }
        }
        return true;
    }

    // 15 三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n && nums[i] <= 0; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1, right = n - 1;
            while(left < right){
                if(nums[i]+nums[left]+nums[right] > 0){
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right] < 0){
                    left++;
                }
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[right]==nums[right-1]){
                        right--;
                    }
                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};