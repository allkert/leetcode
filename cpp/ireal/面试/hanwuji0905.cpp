#include<iostream>
#include<vector>

using namespace std;
// 给定一个正整数n，统计从1到n中包含1的数字的个数
#include<stdio.h>  
  
long long int Count(long long int n){  
    //1的个数  
    long long int count = 0;  
    //当前位  
    long long int Factor = 1;  
    //低位数字  
    long long int LowerNum = 0;  
    //当前位数字  
    long long int CurrNum = 0;  
    //高位数字  
    long long int HigherNum = 0;  
    if(n <= 0){  
        return 0;  
    }  
    while(n / Factor != 0){  
        //低位数字  
        LowerNum = n - (n / Factor) * Factor;  
        //当前位数字  
        CurrNum = (n / Factor) % 10;  
        //高位数字  
        HigherNum = n / (Factor * 10);  
        //如果为0,出现1的次数由高位决定  
        if(CurrNum == 0){  
            //等于高位数字 * 当前位数  
            count += HigherNum * Factor;  
        }  
        //如果为1,出现1的次数由高位和低位决定  
        else if(CurrNum == 1){  
            //高位数字 * 当前位数 + 低位数字 + 1  
            count += HigherNum * Factor + LowerNum + 1;  
        }  
        //如果大于1,出现1的次数由高位决定  
        else{  
            //（高位数字+1）* 当前位数  
            count += (HigherNum + 1) * Factor;  
        }  
        //前移一位  
        Factor *= 10;  
    }  
    return count;  
}  

// 在包含字母的字符串中判断括号是否合法, 括号包含'('和')' '['和']'
bool isValid(string s){
    vector<char> stack;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '['){
            stack.push_back(s[i]);
        }else if(s[i] == ')'){
            if(stack.empty() || stack.back() != '('){
                return false;
            }
            stack.pop_back();
        }else if(s[i] == ']'){
            if(stack.empty() || stack.back() != '['){
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
    
}
int main(){
    string a = "()([safdaa])aslfkjasdlkfjalskdfjsalkdfjlsdjf()";
    if(isValid(a)){
        cout << "true" << endl;
    else cout << "false" << endl;
    }
}