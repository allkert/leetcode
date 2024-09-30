#include <iostream>
#include <vector>
using namespace std;  

class MaxHeap{
private:
    vector<int> data;
    void shiftup(int k){
        while(k > 0 && data[(k-1)/2] < data[k]){
            swap(data[(k-1)/2], data[k]);
            k = (k - 1)/2;
        }
    }
    void shiftdown(int k){
        while( 2 * k + 1 < data.size()){
            int left = 2 * k + 1, right = 2 * k + 2;
            int mmax = k;
            if(data[left] > data[mmax]) mmax = left;
            if(right < data.size() && data[right] > data[mmax]) mmax = right;
            if(mmax == k) break;
            swap(data[k], data[mmax]);
            k = mmax;
        }
    }

public:
    void push(int x){
        data.push_back(x);
        shiftup(data.size() - 1);
    }
    void top(){
        if(data.size() == 0) cout << "empty" << endl;
        else cout << data[0] << endl;
    }
    void pop(){
        if(data.size() == 0){
            cout << "empty" << endl;
            return;
        }
        cout << data[0] << endl;
        swap(data[0], data[data.size() - 1]);
        data.pop_back();
        shiftdown(0);
    }
};

int main() {
    int n;
    cin >> n;
    MaxHeap mheap;
    string op;
    for(int i = 0; i < n; i++){
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            mheap.push(x);
        }
        else if(op == "top"){
            mheap.top();
        }
        else{
            mheap.pop();
        }
    }  
}
// 64 位输出请用 printf("%lld")