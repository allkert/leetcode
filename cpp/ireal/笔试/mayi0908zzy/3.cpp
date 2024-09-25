#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
//     小苯有一个长度为 n 的数组 a，他定义一个区间是好的，当
// 且仅当此区间中的数组值从小到大排序后能形成一个等比数列。
// 现在他希望将 a恰好分割成若干个好区间，请你帮他算算最
// 少可以分割成多少个吧。
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; j++) cin >> a[j];
        int res = 1;
        if(n == 1 || n == 2){
            cout << res << endl;
            continue;
        }
        else{
            // 排序
            sort(a.begin(), a.end());
            
        }     
    }
}