# include<iostream>
# include<vector>
# include<algorithm>
# include<math.h>
# include<limits>

using namespace std;

class Solution{
public:
    //  344 反转字符串
    void reverseString(vector<char>& s) {
        int n = s.size()-1;
        int i = 0;
        while(i < n){
            char tmp = s[i];
            s[i] = s[n];
            s[n] = tmp;
            i++;
            n--;
        }
    }

    // 541 反转字符串Ⅱ
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }

};

int main(){
    string a = "abcdefg";
    int k = 2;
    Solution sol;
    cout <<sol.reverseStr(a,k);
}