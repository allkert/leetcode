#include<iostream>
#include<vector>

using namespace std;

int quickMulti(int a, int b, int p){
    if(a > b) swap(a, b);
    int base = b, res = 0;
    while(a > 0){
        if(a % 2) res = (res + base) % p;
        base *= 2;
        base = base % p;
        a /= 2;
    }
    return res;
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int a, b, p;
        cin >> a >> b >> p;
        cout << quickMulti(a, b, p) << endl;
    }
}