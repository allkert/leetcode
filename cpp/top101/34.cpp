class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */
    int jumpFloor(int number) {
        int dp1 = 1, dp2 = 2, dp3 = 3;
        if(number <= 3) return number;
        for(int i = 0; i < number - 3; ++i){
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp1 + dp2;
        }
        return dp3;
    }
};