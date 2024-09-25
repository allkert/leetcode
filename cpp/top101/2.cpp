#include<iostream>
#include<vector>
#include<stack>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pushV int整型vector 
     * @param popV int整型vector 
     * @return bool布尔型
     */
    // 辅助栈的方法
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        stack<int> st;
        int index = 0;
        for(int i = 0; i < popV.size(); i++){
            while(st.empty() || (index < pushV.size() && st.top() != popV[i])){
                st.push(pushV[index++]);
            }
            if(st.top() != popV[i]) return false;
            else st.pop();
        }
        return true;
    }
    // 不使用辅助栈的方法
    bool IsPopOrder_2(vector<int>& pushV, vector<int>& popV) {
        int n = 0, j = 0;
        for(int num : pushV){
            pushV[n] = num;
            while(n >= 0 && pushV[n] == popV[j]){
                n--;
                j++;
            }
            n++;
        }
        return n == 0;
    }    
};