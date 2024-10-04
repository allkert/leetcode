#include <iostream>
using namespace std;

int quickmulti(int a, int b, int p){
    int res = 0;
    int base = a;
    while(b > 0){
        if(b % 2 == 1){
            res += base;
        }
        base *= 2;
        base %= p;
        b /= 2;
    }
    return res % p;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, p;
        cin >> a >> b >> p;
        cout << quickmulti(a, b, p) << endl;
    }
}
// 64 位输出请用 printf("%lld")