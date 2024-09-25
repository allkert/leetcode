#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    int n, k;
    int ans = 0;
    cin >> n >> k;
    unordered_map<int, int> mp;
    vector<int> pos;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pos.push_back(a);
        mp[a]++;
    }
    int tree = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > 0){
            tree++;
        }
    }
    int t = 0;
    while(t < n){
        int tree = 0;
        for(int i = 0; i < n; i++){
            ans++;
            mp[pos[i] + ans]++;
        }
        t = 0;
         for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > 0){
                t++;
             }
    }

    }
    cout << (n / k) + 1 << endl;
    
}