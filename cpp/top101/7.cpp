#include <array>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    array<int, 100001> que;
    int front = 0, back = 0;
    string cmd;
    while (cin >> cmd){
        if(cmd == "push"){
            int num;
            cin >> num;
            que[back++] = num;
        }
        else if(cmd == "pop"){
            if(back <= front) cout << "error" << endl;
            else{
                cout << que[front++] << endl;
            }
        }
        else{
            if(back <= front) cout << "error" << endl;
            else cout << que[front] << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")