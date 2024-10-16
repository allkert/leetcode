#include<iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        s += s[j+i];
        s[j+i] = ' ';
        j++;
    }
    for(auto ss : s){
        if(ss != ' ')
            cout << ss;
    }
    cout << endl;
}