#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
// 
int maxPrimePower(int n){
    unordered_map<int, int> res;
    int rtn = 0;
    int i = 2;
    while(n > 1){
        if(n % i == 0){
            res[i]++;
            n /= i;
        } else {
            i++;
        }
    }
    for (auto it = res.begin(); it != res.end(); it++){
        rtn = max(rtn, it->second);
    }
    return rtn;
} 

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int x, t;
        cin >> x >> t;
        int maxWeight = 0;
        vector<int> res;
        for(int j = max(1, x - t); j <= x + t; j++){
            int mw = maxPrimePower(j);//你可以随便写函数名字，自定义函数
            if(mw > maxWeight){
                maxWeight = mw;
                res.clear();
                res.push_back(j);
            } else if(mw == maxWeight){
                res.push_back(j);
            }
        }
        for(int j = 0; j < res.size() - 1; j++){
            cout << res[j] << " ";
        }
        cout << res[res.size() - 1] << endl;
    }
}