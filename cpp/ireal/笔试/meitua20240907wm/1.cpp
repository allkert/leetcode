#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> v = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    for(int i = 0; i < s.size(); i++) {
        int index = find(v.begin(), v.end(), s[i]) - v.begin();
        if(index <= 9) s[i] = v[9 - index];
        else if(index <= 18) s[i] = v[28 - index];
        else s[i] = v[44 - index];
    }
    cout << s << endl;
}