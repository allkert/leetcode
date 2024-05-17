# include<iostream>
# include<vector>
# include<algorithm>
# include<math.h>
# include<limits>
# include<string>
# include <map>
# include <unordered_map>
# include<numeric>

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

    // 151. 反转字符串中的单词
    // 我的思路，首先实现根据key来分割字符串存入字符串容器中，然后反向遍历重新组合字符串。
    // 记得看一下标答，而且我使用了额外的空间
    vector<string> spiltString(string s, char key){
        vector<string> res;
        int left = 0, right = 0;
        while(s[left] == key){
            left++;
            right++;
        }
        while(right < s.length()){
            while(s[left] == key && left < s.length()){
                left++;
            }
            right = left;
            while(s[right] != key && right < s.length()){
                right++;
            }
            if(right > left){
                res.push_back(s.substr(left, right-left));
            }
            left = right;
        }
        return res;
    }
    string reverseWords(string s) {
        vector<string> spiltword = spiltString(s, ' ');
        string t;
        for(auto it = spiltword.rbegin(); it != spiltword.rend(); it++){
            t = t + *it + " ";
        }
        return t.substr(0,t.length()-1);
    }

    // 参考答案
    // 翻转字符串
    void reverse_(string& s, int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != ' '){
                if(slow != 0) s[slow++] = ' ';
                while(i < s.length() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords_ref(string s){
        removeExtraSpaces(s);
        reverse_(s, 0, s.size()-1);
        int start = 0;
        for(int i = 0; i <= s.length(); ++i){
            if(i == s.size() || s[i] == ' '){
                reverse_(s, start, i-1);
                start = i + 1;
            }
        }
        return s;
    }

    // 28. 找出字符串中第一个匹配项的下标
    int strStr(string haystack, string needle) {
        int len_s = haystack.length();
        int len_t = needle.length();
        int next[len_t];
        getnext(needle, next);
        int i = 0, j = 0;
        while(i < len_s and j < len_t){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            else if(j != 0){
                j = next[j-1];
            }
            else{
                i++;
            }
        }
        return j == len_t? i-len_t:-1;
    }

    void getnext(string s, int* nxt){
        int length = s.length();
        nxt[0] = 0;
        int i = 0, j = 1;
        while(j < length){
            if(s[i] == s[j]){
                nxt[j++] = i+1;
                i++;
            }
            else if (i != 0){
                i = nxt[i-1];
            }
            else{
                nxt[j++]=0;
            }
        }
    }

    // 459. 重复的子字符串
    bool repeatedSubstringPattern (string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getnext(s, next);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }


    // 49. 字母异位词分组
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> map;
        vector<vector<string>> res;
        for(string str:strs){
            vector<int> count(26);
            for(char ch: str){
                count[ch-'a']++;
            }
            map[count].push_back(str);
        }
        for(auto a: map){
            res.push_back(a.second);
        }
        return res;
    }
};

int main(){
    Solution sol;
    string s = "aabaabaafa";
    string t = "aabaaf";
    cout << sol.strStr(s,t);
}