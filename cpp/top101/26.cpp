#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    vector<string> pos = {"left", "mid", "right"};
    void moveH(int n, int S, int D, vector<string>& res){
        if(n == 0) return;
        moveH(n - 1, S, 3 - S - D, res);
        res.push_back("move from " + pos[S] + " to " + pos[D]);
        moveH(n - 1, 3 - S - D, D, res);
    }
    vector<string> getSolution(int n) {
        // write code here
        vector<string> res;
        moveH(n, 0, 2, res);
        return  res;
    }
};