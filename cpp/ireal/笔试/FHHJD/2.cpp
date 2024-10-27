#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>

using namespace std;


int main(){
    unordered_map<char, int> mp;
    string rank;
    cin >> rank;
    for(int i = 0; i < rank.size(); ++i){
        mp[rank[i]] = i;
    }
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; ++i){
        cin >> s[i];
    }
    sort(s.begin(), s.end(), [&](string a, string b){
        int n = a.size(), m = b.size();
        for(int i = 0; i < min(n, m); ++i){
            if(mp[a[i]] != mp[b[i]]){
                return mp[a[i]] < mp[b[i]];
            }
        }
        return n < m;
    });
    for(auto x: s){
        cout << x << endl;
    }
}