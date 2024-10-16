/* 
李华有一块很大的画布， */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int count(vector<int> &canvas){
    set<int> s;
    for(auto c : canvas){
        s.insert(c);
    }
    return s.size();
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> canvas(n + 1, 0);
    for(int i = 1; i <= m; ++i){
        int x;
        cin >> x;
        for(int j = 1; j <= x; ++j){
            if(canvas[j] < i) canvas[j] = i;
        }
        if(i == m){
            cout << count(canvas) << endl;
        }
        else{
            cout << count(canvas) << " ";
        }
    }

}