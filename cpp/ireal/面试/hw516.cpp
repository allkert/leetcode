#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<iostream>
#include<math.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    int len = s.size();
    int n = pow(len, 0.5);
    string res = "";
    if(n * n != len){
        cout << "error" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res += s[i + n * j];
            }
        }
        cout << res << endl;
    }
}