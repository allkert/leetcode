#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int front = 0, back = 0;
    bool isEmpty = true;
    vector<int> que(n, 0);
    string cmd;
    while(cin >> cmd){
        if(cmd == "push"){
            if(!isEmpty && back == front) cout << "full" << endl;
            else{
                int num;
                cin >> num;
                que[back++] = num;
                isEmpty = false;
            }
        }
        else if(cmd == "pop"){
            if(isEmpty) cout << "empty" << endl;
            else cout << que[front++] << endl;
            isEmpty = (back%n == front%n);
        }
        else if(cmd == "front"){
            if(isEmpty) cout << "empty" << endl;
            else cout << que[front] << endl;            
        }
        back %= n;
        front %= n;
    }
}
// 64 位输出请用 printf("%lld")