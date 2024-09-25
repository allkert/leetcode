#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];  
    long long oddCost = 0, evenCost = 0;
    for(auto num : nums){
        if(num % 2 == 0) evenCost += num;
        else oddCost += num;
    }
}