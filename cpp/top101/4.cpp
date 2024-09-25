#include <stack>
#include <unordered_set>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param tokens string字符串vector 
     * @return int整型
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> uset = {"+", "-", "*", "/"};
        for(auto item : tokens){
            if(uset.find(item) != uset.end()){
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                if(item == "+") st.push(left + right);
                else if(item == "-") st.push(left - right);
                else if(item == "*") st.push(left * right);
                else st.push(left / right);
            }
            else st.push(stof(item));
        }
        return st.top();
    }
};