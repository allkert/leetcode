# include<iostream>
# include<vector>
# include<limits>
# include<algorithm>
# include<numeric>
# include<list>
# include<unordered_map>

using namespace std;

class Solution {
public:

    // 455. 分发饼干
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        for(int i = g.size()-1, index = s.size()-1; i >= 0 && index >= 0; i--){
            if(s[index] >= g[i]){
                res++;
                index--;
            }
        }
        return res;
    }

    // 376 摆动序列
    int wiggleMaxLength_dp(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int dp[2] = {1, 1};
        int res = 2;
        if(nums[1] > nums[0]) dp[0] = 2;
        else if(nums[1] < nums[0]) dp[1] = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                dp[0] = max(dp[0], dp[1] + 1);
            }
            else if(nums[i] < nums[i-1]){
                dp[1] = max(dp[1],dp[0] + 1);
            }
        }
        return (dp[0] > dp [1])? dp[0]:dp[1];
    }

    int wiggleMaxLength_greedy(vector<int>& nums){
        if(nums.size() == 1) return 1;
        int preDif = 0;
        int curDif = 0;
        int res = 1;
        for(int i = 0; i < nums.size()-1; i++){
            curDif = nums[i+1]-nums[i];
            if((preDif <= 0 && curDif > 0) || (preDif >= 0 && curDif < 0)){
                preDif = curDif;
                res++;
            }
        }
        return res;
    }

    // 53 最大子数组和
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > res) res = count;
            if(count < 0) count = 0;
        }
        return res;
    }

    // 122. 买卖股票的最佳时机 II
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i+1]-prices[i] > 0) res += prices[i+1]-prices[i];
        }
        return res;
    }

    int maxProfit_dp(vector<int>& prices){
        int dp[2] = {0, -prices[0]};
        for(int i = 1; i < prices.size(); i++){
            int tmp0 = dp[0];
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], tmp0 - prices[i]);    
        }
        return dp[0];
    }


    // 55. 跳跃游戏
    bool canJump(vector<int>& nums) {
        int maxJumpIndex = 0;
        int length = nums.size();
        for(int i = 0; i < maxJumpIndex; i++){
            maxJumpIndex = max(maxJumpIndex, i + nums[i]);
            if(maxJumpIndex >= length) return true;
        }
        return false;
    }

    // 45跳跃游戏Ⅱ
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int i = 0;
        int cover = nums[i];
        int step = 1;
        while(cover < nums.size()){
            int nextPlace = i;
            int nextCover = cover;
            for(int j = i; j <= cover; j++){
                if(j + nums[j] > nextCover){
                    nextPlace = j;
                    nextCover = j + nums[j];
                }
            }
            if(cover >= nums.size()-1) break;
            step++;
            cover = nextCover;
            i = nextPlace;
        }
        return step;
    }

    int jump1(vector<int>& nums){
        if(nums.size() == 1) return 0;
        int nextCover = 0;
        int curCover = 0;
        int step = 0;
        for(int i = 0; i < nums.size(); i++){
            nextCover = max(nextCover, i + nums[i]);
            if(i == curCover){
                step++;
                curCover = nextCover;
                if(curCover >= nums.size()-1) break;
            }
        }
        return step;
    }


    // 1005. K 次取反后最大化的数组和
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        quickSortAbs(nums, 0, nums.size()-1);
        int sumResult = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
            sumResult += nums[i];
        }
        if(k % 2 == 0) return sumResult + nums[nums.size()-1];
        else return sumResult - nums[nums.size()-1];
    }
    void quickSortAbs(vector<int>& nums, int beginIndex, int endIndex){
        if(beginIndex >= endIndex) return;
        int left = beginIndex, right = endIndex;
        int tag = left;
        while(left < right){
            while(abs(nums[right]) <= abs(nums[tag]) && left < right) right--;
            if(left < right){
                swap(nums[right], nums[tag]);
                tag = right;
            }
            while(abs(nums[left]) >= abs(nums[tag]) && left < right) left++;
            if(left < right){
                swap(nums[left], nums[tag]);
                tag = left;
            }
        }
        quickSortAbs(nums, beginIndex, tag-1);
        quickSortAbs(nums, tag + 1, endIndex);
    }

    // 134. 加油站
    // 暴力搜索的方法，复杂度是o(n^2)会超时
    int canCompleteCircuit_1(vector<int>& gas, vector<int>& cost) {
       if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
       int V = 0;
       for(int i = 0; i < gas.size(); i++){
            if(gas[i] < cost[i]) continue;
            if(checkGas(gas, cost, i)) return i;
       }
       return -1;
    }

    bool checkGas(vector<int>& gas, vector<int>& cost, int begin){
        int V = 0;
        for(int i = begin; i < gas.size(); i++){
            V += gas[i]-cost[i];
            if(V < 0) return false;
        }
        for(int j = 0; j < begin; j++){
            V += gas[j]-cost[j];
            if(V < 0) return false;
        }
        return true;
    }

    // 贪心算法
    int canCompleteCircuit_greedy(vector<int>& gas, vector<int>& cost){
        int totalGas = 0;
        int curGas = 0;
        int res = 0;
        for(int i = 0; i < cost.size(); i++){
            curGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            if(curGas < 0){
                res = i + 1;
                curGas = 0;
            }
        }
        if(totalGas < 0) return -1;
        return res;
    }

    //135 分发糖果
    int candy(vector<int>& ratings) {
        vector<int> candyVec(ratings.size(),1);
        for(int i = 1; i < ratings.size(); i++){
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] ) {
                candyVec[i] = max(candyVec[i], candyVec[i + 1] + 1);
            }
        }
        return accumulate(candyVec.begin(), candyVec.end(), 0);
    }

    //860 柠檬水找零
    bool lemonadeChange(vector<int>& bills) {
        int changeFive = 0;
        int changeTen = 0;
        for(int bill: bills){
            if(bill == 5) changeFive++;
            else if(bill == 10){
                changeFive--;
                changeTen++;
            }
            else{
                if(changeTen <= 0) changeFive -= 3;
                else{
                    changeFive -= 1; 
                    changeTen -= 1;
                }
            }
            cout << changeFive << changeTen << endl;
            if(changeTen < 0 || changeFive < 0) return false;
        }
        return true;
    }

    // 406 根据身高重新构建队列
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res(people.size(), {-1, -1});
        for(vector<int> p: people){
            int i = 0, pos = -1;
            for(; i < res.size() && pos < p[1]; i++){
                if(res[i][1] == -1 || res[i][0] >= p[0] ){
                    pos++;
                }
            }
            res[i - 1] = p;
        }
        return res;
    }

    vector<vector<int>> reconstructQueue_Ref(vector<vector<int>>& people){
        sort(people.begin(), people.end(), cmpref);
        list<vector<int>> que;
        for(int i = 0; i < people.size(); i++){
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }

    // 452 用最少数量的箭引爆气球
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare452);
        int res = 1;
        int left = points[0][0], right = points[0][1];
        for(int i = 1, left = points[0][0], right = points[0][1]; i < points.size(); i++){
            if(points[i][0] >= left && points[i][0] <= right){
                left = max(left, points[i][0]);
                right = min(right, points[i][1]);
            }
            else{
                left = points[i][0];
                right = points[i][1];
                res++;
            }
        }
        return res;
        
    }

    // 435. 无重叠区间
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare452);
        int res = 0;
        cout<<"!!!";
        for(int i = 1, right = intervals[0][1]; i < intervals.size(); i++){
            if(intervals[i][0] >= right){
                right = intervals[i][1];
            }
            else{
                res++;
                if(intervals[i][1] <= right){
                    right = intervals[i][1];
                }
            }
        }
        return res;
    }

    // 763. 划分字母区间
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastAppear;
        vector<int> res;
        // 找到每个字母最后出现的位置
        for(int i = 0; i < s.length(); i++){
            lastAppear[s[i]] = i;
        }
        int last = -1;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            last = max(last, lastAppear[s[i]]);
            count++;
            if(i == last){
                last = -1;
                res.push_back(count);
                count = 0;
            }
        }
        return res;
    } 

    // 56 合并区间
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare452);
        int left = intervals[0][0], right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > right){
                res.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else{
                right = max(right, intervals[i][1]);
            }
        }
        res.push_back({left, right});
        return res;
    }

    // 738. 单调递增的数字
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = s.length();
        for(int i = s.length()-1; i >= 1; i--){
            if(s[i-1] > s[i]){
                s[i-1]--;
                flag = i;
            }
        }
        for(int i = flag; i < s.length(); i++){
            s[i] = '9';
        }
        return stoi(s);
    }

private:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return (a[1] <= b[1]);
        else return(a[0] < b[0]);
    }

    static bool cmpref(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    static bool compare452(vector<int>& a, vector<int>& b){
        return (a[0] < b[0]);
    }

};

int main(){
    Solution s;
    cout<<s.monotoneIncreasingDigits(187)<<endl;
}
