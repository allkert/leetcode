class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();


        vector<int> mem(n, 0);
        function<int(int)> dfs = [&](int x){
            if(mem[x]) return mem[x];
            mem[x]++;
            for(int j = x - 1; j >= max(0, x - d); --j){
                if(arr[j] < arr[x]) mem[x] = max(1 + dfs(j), mem[x]);
                else break;
            }
            for(int j = x + 1; j <= min(n - 1, x + d); ++j){
                if(arr[j] < arr[x]) mem[x] = max(1 + dfs(j), mem[x]);
                else break;
            }
            return mem[x];
        };

        int res = 0;
        for(int i = 0; i < n; ++i){
            res = max(res, dfs(i));
        }
        return res;
    }
};