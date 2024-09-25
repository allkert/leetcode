#include <array>
#include <iostream>
using namespace std;

class myStack{
private:
    int length = 0;
    array<int, 100001> arr;
public:
    void push(int x){
        arr[length] = x;
        length++;
    }
    void top(){
        if(length == 0) cout << "error" << endl;
        else cout << arr[length - 1] << endl;
    }
    void pop(){
        if(length == 0) cout << "error" << endl;
        else{
            cout << arr[length - 1] << endl;
            length--;
        }
    }
};

int main() {
    int n;
    cin >> n;
    string cmd;
    myStack stack;
    for(int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            stack.push(num);
        }
        else if(cmd == "top"){
            stack.top();
        }
        else if(cmd == "pop"){
            stack.pop();
        }
    }
}
// 64 位输出请用 printf("%lld")