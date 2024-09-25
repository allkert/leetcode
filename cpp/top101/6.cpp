#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution{
public:
    int calculate(string s){
        unordered_map<char, int> op_pri = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 3}};
        stack<char> ops;
        stack<long long> nums;
        nums.push(0);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' ') continue;
            else if(s[i] == '('){
                ops.push(s[i]);
                if(s[i+1] == '-'){
                    nums.push(0);
                    i++;
                    ops.push('-');
                }
            }
            else if(s[i] == ')'){
                while(ops.top() != '('){
                    cal(nums, ops);
                }
                ops.pop();
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                int j = i;
                long long cur_num = 0;
                while(j < s.length() && s[j] >= '0' && s[j] <= '9'){
                    cur_num = 10 * cur_num + (s[j++] - '0');
                }
                i = j - 1;
                nums.push(cur_num);
            }
            else{
                while(!ops.empty() && ops.top() != '(' && op_pri[ops.top()] >= op_pri[s[i]]){
                    cal(nums, ops);
                }
                ops.push(s[i]);
            }
        }
        while(!ops.empty() && ops.top()!='('){
            cal(nums, ops);
        }
        return nums.top();
    }

    void cal(stack<long long>& nums, stack<char>& ops){
        long long b = nums.top(); nums.pop();
        long long a = nums.top(); nums.pop();
        char oper = ops.top(); ops.pop();
        long long res;
        switch(oper){
            case '+' : res = a + b; break;
            case '-' : res = a - b; break;
            case '*' : res = a * b; break;
            case '/' : res = a / b; break;
        }
        nums.push(res);
    }
};

int main(){
    // 如果找不到，返回的是什么
    string s = "We are happy.";
    unsigned long long a = ULONG_LONG_MAX;
    int b = -1;
    unsigned long long c = 18446744073709551615ull;
    cout << (a == b) << endl;
    cout << a << endl;
}