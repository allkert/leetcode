#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<numeric>
#include<unordered_set>
#include<algorithm>
#include <stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

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
    string minWindow(string s, string t);
    int maxSubArray(vector<int> &nums);
    void qucikSort_56(vector<vector<int>>& intervals, int beginIndex, int endIndex);
    vector<vector<int>> merge(vector<vector<int>> &intervals);
    void rotate(vector<int> &nums, int k);
    vector<int> productExceptSelf(vector<int> &nums);
    int firstMissingPositive(vector<int> &nums);
    void setZeroes(vector<vector<int>> &matrix);
    vector<int> spiralOrder(vector<vector<int>> &matrix);
    void rotate(vector<vector<int>> &matrix);
    bool searchMatrix(vector<vector<int>> &matrix, int target);
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
    ListNode *reverseList(ListNode* head);
    bool isPalindrome(ListNode *head);
    void reverseLength(ListNode* head, int size);
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
    bool hasCycle(ListNode *head);
    ListNode *detectCycle(ListNode *head);
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    ListNode* addTwoNumbersRecursion(ListNode* l1, ListNode* l2);
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
string Solution::minWindow(string s, string t){
    unordered_map<char, int> hs, ht;
    string ans = "";
    int cnt = 0;
    // 统计t中各个字符出现的次数
    for(char ch : t) ht[ch]++;

    // 滑动窗口
    for(int i = 0, j = 0; i < s.size(); i++){
        // 右边界向右滑动一位
        if(hs[s[i]] < ht[s[i]]) cnt++;
        hs[s[i]]++;
        // 去除左边所有没有用的字符，从而减少子串长度
        while(hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
        // 找到一个覆盖子串
        if(cnt == t.size()){
            if(ans.size() == 0 || ans.size() > i - j + 1){
                ans = s.substr(j, i - j + 1);
            }
        }
    }
    return ans;
}
int Solution::maxSubArray(vector<int>& nums){
    int ans = nums[0];
    int dp = nums[0];
    for(int i = 1; i < nums.size(); i++){
        dp = max(nums[i], dp + nums[i]);
        ans = max(dp, ans);
    }
    return ans;
}
void Solution::qucikSort_56(vector<vector<int>>& intervals, int beginIndex, int endIndex){
    if(beginIndex >= endIndex) return;
    int left = beginIndex, right = endIndex, provit = beginIndex;
    while(left < right){
        while(left < right && intervals[right][0] >= intervals[provit][0]) right--;
        while(left < right && intervals[left][0] <= intervals[provit][0]) left++;
        if(left < right) swap(intervals[left], intervals[right]);
    } 
    swap(intervals[left], intervals[provit]);
    qucikSort_56(intervals, beginIndex, left - 1);
    qucikSort_56(intervals, left + 1, endIndex);
}
vector<vector<int>> Solution:: merge(vector<vector<int>>& intervals) {
    qucikSort_56(intervals, 0, intervals.size() - 1);
    vector<int> zone = intervals[0];
    vector<vector<int>> res;
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= zone[1]) zone[1] = max(intervals[i][1], zone[1]);
        else{
            res.emplace_back(zone);
            zone = intervals[i];
        }
    }
    res.emplace_back(zone);
    return res;
}
void Solution::rotate(vector<int>& nums, int k){
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
vector<int> Solution::productExceptSelf(vector<int>& nums){
    vector<int> res(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++){
        res[i] = res[i-1] * nums[i-1]; 
    }
    int multiAcc = 1;
    for(int i = nums.size() - 2; i >= 0; i--){
        multiAcc *= nums[i+1];
        res[i] *= multiAcc;
    }
    return res;
}
int Solution::firstMissingPositive(vector<int>& nums){
    /* 思路：把所以的数字，调整到它应该出现的位置上
        然后再遍历一遍，找到缺失的数 */
    // index为i的位置应该放数字i+1
    for(int i = 0; i < nums.size(); i++){
        while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
}
void Solution::setZeroes(vector<vector<int>>& matrix){
    int colTag = 1;
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] == 0) colTag = 0;
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i = matrix.size() - 1; i >= 0; i--){
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
        if(colTag == 0) matrix[i][0] = 0;
    }
}
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix){
    int left = 0, right = matrix[0].size() - 1;
    int up = 0, down = matrix.size() - 1;
    int direction = 0;
    vector<int> ans;
    while(left <= right && up <= down){
        switch (direction % 4)
        {
        case 0:
            for(int i = left; i <= right; i++){
                ans.emplace_back(matrix[up][i]);
            }
            up++;
            break;
        case 1:
            for(int i = up; i <= down; i++){
                ans.emplace_back(matrix[i][right]);
            }
            right--;
            break;
        case 2:
            for(int i = right; i >= left; i--){
                ans.emplace_back(matrix[down][i]);
            }
            down--;
            break;
        case 3:
            for(int i = down; i >= up; i--){
                ans.emplace_back(matrix[i][left]);
            }
            left++;
            break;
        }
        direction++;
    }
    return ans;
}
void Solution::rotate(vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < (n+1)/2; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
        }
    }
}
bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
    int x = 0, y = matrix[0].size()-1;
    while(x < matrix.size() && y >= 0){
        if(matrix[x][y] < target)  x++;
        else if(matrix[x][y] > target) y--;
        else return true;
    }
    return false;
}
ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB){
    if(headA == nullptr || headB == nullptr) return NULL;
    int lenA = 0, lenB = 0;
    ListNode* curA = headA, *curB = headB;
    while(curA != NULL){
        lenA++;
        curA = curA->next;
    }
    while(curB != NULL){
        lenB++;
        curB = curB->next;
    }
    curA = headA; curB = headB;
    if(lenA < lenB){
        swap(curA, curB);
        swap(lenA, lenB);
    }
    int i = 0;
    while(i < lenA - lenB){
        curA = curA->next;
        i++;
    }
    while(curA != NULL && curB != NULL){
        if(curA == curB) return curA;
        curA = curA->next;
        curB = curB->next;
    }
    return NULL;
}
ListNode* Solution::reverseList(ListNode* head) {
    if(head == NULL) return head;
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* tmp;
    while(cur){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}
bool Solution::isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) return true;
    ListNode *slow = head, *fast = head->next;
    int tag = 1;
    while(fast->next && fast->next->next){
        tag++;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* left = slow;
    ListNode* right;
    ListNode* rightHead = slow->next;
    // 节点数是偶数
    if(fast->next == NULL) right = slow->next;
    else right = slow->next->next;
    reverseLength(head, tag);
    while(left != NULL && right != NULL){
        if(left->val != right->val) {
            reverseLength(slow, tag);
            slow->next = rightHead;
            return false;
        }
        left = left->next;
        right = right->next;
    }
    reverseLength(slow, tag);
    slow->next = rightHead;
    return true;
}
void Solution::reverseLength(ListNode *head, int size) {
    ListNode* pre = NULL;
    ListNode* cur = head;
    ListNode* tmp;
    for(int i = 0; i < size; i++){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }    
}
ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    if(list1->val >= list2->val){
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    else{
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
}
bool Solution::hasCycle(ListNode *head){
    if(head == NULL || head->next == NULL) return false;
    ListNode *slow = head, *fast = head->next;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return true;
    }
    return false;
}
ListNode* Solution::detectCycle(ListNode *head) {
    if(head == NULL) return NULL;
    ListNode *low = head, *fast = head;
    while(fast->next && fast->next->next){
        low = low->next;
        fast = fast->next->next;
        if(low == fast) break;
    }
    if(fast->next && fast->next->next){
        ListNode* ans = head; 
        while(ans != low){
            ans = ans->next;
            low = low->next;
        }
        return ans;
    }
    return NULL;
}
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
    ListNode* head = addTwoNumbersRecursion(l1, l2);
    int carry = 0;
    ListNode* cur = head;
    while(cur->next){
        int tmp = cur->val;
        cur->val = (cur->val + carry) % 10;
        carry = tmp / 10;
    }
    if(cur->val + carry >= 10){
        cur->next = new ListNode((cur->val + carry) / 10);
        cur->val = (cur->val + carry) % 10;
    }
    return head;
}
ListNode* Solution::addTwoNumbersRecursion(ListNode* l1, ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    l1->val = l1->val + l2->val;
    l1->next = addTwoNumbersRecursion(l1->next, l2->next);
    return l1;
}