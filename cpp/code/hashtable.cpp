#include<iostream>
#include<limits>
#include<math.h>
#include<vector>
#include<unordered_set>

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
};