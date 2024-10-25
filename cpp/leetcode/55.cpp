class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > mx) { // 无法到达 i
                return false;
            }
            mx = max(mx, i + nums[i]); // 从 i 最右可以跳到 i + nums[i]
        }
        return true;
    }
};