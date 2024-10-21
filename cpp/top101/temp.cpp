#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    // auto cmp = [&](const int a, const int b){
    //     return a > b;
    // };
    // priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end(), [](const int a, const int b){
        return a > b;
    });
    cout << __cplusplus << endl;
}