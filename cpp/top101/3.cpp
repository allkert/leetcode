#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> st;
        for(auto bracket : s){
            if(bracket == '}' || bracket == ']' || bracket == ')'){
                if(st.empty()) return  false;
                char temp = st.top(); st.pop();
                if(bracket == '}' && temp != '{') return false;
                if(bracket == ']' && temp != '[') return false;
                if(bracket == ')' && temp != '(') return false;
            }
            else{
                st.push(bracket);
            }
        }
        return st.empty();
    }
};