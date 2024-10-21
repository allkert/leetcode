#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while(q--){
        int a, b, p;
        cin >> a >> b >> p;
        long long  base = a;
        long long res = 1;
        while(b > 0){
            if(b % 2) res = (res * base) % p;
            base *= base;
            base %= p;
            b /= 2;
        }
        cout << res << endl;
    }
}
// 64 位输出请用 printf("%lld")