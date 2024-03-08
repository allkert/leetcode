#include<vector>
#include<iostream>
#include<unordered_set>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.length()==0) return 0;
    unordered_set<char> uset;
    int res = 0;
    int left = 0, right = 0;
    while(right < s.length()){
        unordered_set<char>:: iterator it = uset.find(s[right]);
        if(it != uset.end()){
            while(s[left] != s[right]){
                uset.erase(s[left]);
                left++;
            }
            left++;
        }
        else{
            res = res < right - left + 1? right-left+1:res;
            uset.insert(s[right]);
        }
        right++;
    }
    return  res;
}

int main() {
    set<int> s{1,2,3,4};
    s.insert(1);
    s.insert(2);
    s.insert(3);

}