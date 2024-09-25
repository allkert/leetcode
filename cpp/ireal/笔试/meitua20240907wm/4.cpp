#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<map>


using namespace std;

int main(){
    // 询问次数
    int q;
    cin >> q;
    map<int, int> mp;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if(mp.find(x) == mp.end()){
            mp[x] = y;
            cout << x + y - 1 << endl;
        }
        else{
            cout << x + y - 1 + mp[x] << endl;
        }
        // 更新map
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->first > x){
                it->second += y;
            }
        }
    }
}