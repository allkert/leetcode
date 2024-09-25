#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> stack;
    int index = -1;
    int i = 0;
    while(i < s.length()){
        if(index == -1){
            stack.push_back(s[i++]);
            index++;
        }
        else{
            while(index >= 0 && i < s.length() && stack[index] == s[i]){
                i++;
                stack.pop_back();
                index--;
            }
            if(i < s.length()){
                stack.push_back(s[i++]);
                index++;
            }
        }
    }
    if(index == -1) cout << 0 << endl;
    else{
        for(auto ss : stack){
        cout << ss;
        }
        cout << endl;
    }
}
// 64 位输出请用 printf("%lld")