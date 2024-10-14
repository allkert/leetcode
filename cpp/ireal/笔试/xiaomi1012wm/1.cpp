#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    int absMin = INT_MAX;
    long sum = 0;
    int negNum = 0;
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        sum += abs(nums[i]);
        absMin = min(absMin, abs(nums[i]));
        if(nums[i] < 0) negNum++;
    }
    if(negNum % 2 == 0) cout << sum << endl;
    else{
        cout << sum - 2 * absMin << endl;
    }
}