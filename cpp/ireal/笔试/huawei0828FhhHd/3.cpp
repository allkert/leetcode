#include<iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> nums(n); 
    sort(nums.begin(), nums.end(), [](pair<int, int>& a, pair<int, int>& b){
        return a.first < b.first;
    });
}