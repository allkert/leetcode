#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<numeric>
#include<unordered_set>
#include<algorithm>
#include <stack>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target);
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    int longestConsecutive(vector<int>& nums);
    void moveZeroes(vector<int>& nums);
    int maxArea(vector<int>& height);
    vector<vector<int>> threeSum(vector<int>& nums);
    int trap(vector<int>& height);
    int lengthOfLongestSubstring(string s);
    vector<int> findAnagrams(string s, string p);
    int subarraySum(vector<int> &nums, int k);
    vector<int> maxSlidingWindow(vector<int> &nums, int k);
};

class MyPriorityQueue{
private:
    deque<int> dq;
    
public:
    int front(){
        return dq.front();
    }
    void popright(){
        dq.pop_front();
    }
    void push(int val){
        while(!dq.empty() && dq.back() < val) dq.pop_back();
        dq.push_back(val);
    }
    bool empty() {
        return dq.empty();
    }
};

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    // key: num  value:index
    unordered_map<int, int> hashmap;
    for(int i = 0; i < nums.size(); i++){
        if(hashmap.find(target - nums[i]) != hashmap.end()){
            return {hashmap[target - nums[i]], i};
        }
        hashmap.insert(pair<int, int>(nums[i], i));
    }
    return {};
}
vector<vector<string>> Solution::groupAnagrams(vector<string>& strs){
    // 自定义哈希函数
    auto fn = hash<int>{};
    auto arrayHash = [&fn](const array<int, 26>& arr) -> size_t{
        return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num){
            return (acc << 1) ^ fn(num);
        });
    };
    
    unordered_map<array<int, 26>, vector<string>,  decltype(arrayHash)> mp(0, arrayHash);
    for(string& str : strs){
        array<int, 26> counts{};
        for(int i = 0; i < str.size(); i++){
            counts[str[i] - 'a']++;
        }
        mp[counts].emplace_back(str);
    }

    vector<vector<string>> ans;
    for(auto it = mp.begin(); it != mp.end(); it++){
        ans.emplace_back(it->second);
    }
    return ans;
}  
int Solution::longestConsecutive(vector<int>& nums){
    unordered_set<int> uset;
    for(const int& num : nums) uset.insert(num);
    int ans = 0;
    for (const int& num : nums){
        if(uset.find(num-1) == uset.end()){
            int tmpNum = num;
            int tmpAns = 1;
            while(uset.count(tmpNum+1)){
                tmpAns++;
                tmpNum++;
            }
            ans = max(ans, tmpAns);
        }
    }
    return ans;
}
void Solution::moveZeroes(vector<int>& nums){
    int i = 0, j = 0;
    while(j < nums.size()){
        if(nums[j] != 0){
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    for(int k = i; k < nums.size(); k++){
        nums[k] = 0;
    }
}
int Solution::maxArea(vector<int>& height){
    int left = 0, right = height.size()-1;
    int ans = 0;
    while(left < right){
        ans = max(ans, (right - left) * min(height[left], height[right]));
        if(height[left] < height[right]) left++;
        else right--;
    }
    return ans;
}
vector<vector<int>> Solution::threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end(), less<int>{});
    vector<vector<int>> ans;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) return ans;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right] + nums[i];
            if(sum > 0) right--;
            else if(sum < 0) left++;
            else{
                ans.push_back({nums[i], nums[left], nums[right]});
                // 去重！！！
                do{right--;}while(left < right && nums[right] == nums[right+1]);
                do{left++;}while(left < right && nums[left] == nums[left-1]);
            }
        }
    }
    return ans;
}
int Solution::trap(vector<int>& height){
    stack<int> st;
    int ans = 0;
    for(int i = 0; i < height.size(); i++){
        while(!st.empty() && height[i] > height[st.top()]){
            int mid = st.top(); st.pop();
            if(!st.empty()) ans += (min(height[i], height[st.top()]) - height[mid])*(i - st.top() - 1);
        }
        st.push(i);
    }
    return ans;
}
int Solution::lengthOfLongestSubstring(string s){
    unordered_set<char> uset;
    int i = 0, j = 0;
    int ans = 0;
    while(j < s.size()){
        while(uset.find(s[j]) != uset.end()){
            uset.erase(s[i++]);
        }
        uset.insert(s[j++]);
        ans = max(ans, j-i);
    }
    return ans;
}
vector<int> Solution::findAnagrams(string s, string p){
    vector<int> count_p(26, 0);
    vector<int> count_s(26, 0);
    vector<int> ans;
    for(char ch : p){
        count_p[ch - 'a']++;
    }
    int left = 0;
    for(int right = 0; right < s.size(); right++){
        count_s[s[right] - 'a']++;
        if(right - left + 1 == p.size()){
            if(count_p == count_s) ans.push_back(left);
            count_s[s[left++] - 'a']--;
        }
    }
    return ans;
}
int Solution::subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    int pre = 0;
    umap[0]++;
    int ans = 0;
    for(int i = 0; i < nums.size(); i++){
        pre += nums[i];
        if(umap.find(pre - k) != umap.end()) ans += umap[pre - k];
        umap[pre]++;
    }
    return ans;
}
vector<int> Solution::maxSlidingWindow(vector<int>& nums, int k) {
    MyPriorityQueue dq;
    vector<int> ans;
    for(int i = 0; i < k; i++) dq.push(nums[i]);
    ans.push_back(dq.front());
    for(int i = k; i < nums.size(); i++){
        dq.push(nums[i]);
        if(!dq.empty() && dq.front() == nums[i - k]) dq.popright();
        ans.push_back(dq.front());
    }
    return ans;
}

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("ababcbb");
}
