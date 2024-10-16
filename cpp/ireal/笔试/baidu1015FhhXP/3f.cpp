#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    long res = 0;
    vector<int> tag(n, 0);
    if(n % 2 == 0){
        int left = 0, right = n - 2;
        int i = 1;
        while(left <= right){
            tag[left] = i;
            tag[right] = i;
            ++i;
            left += 2;
            right -= 2;
        }
        left = 1;
        right = n - 1;
        i = -1;
        while(left <= right){
            tag[left] = i;
            tag[right] = i;
            --i;
            left += 2;
            right -= 2;
        }
    }
    else{
        int left = 0, right = n - 1;
        int i = 1;
        while(left <= right){
            tag[left] = i;
            tag[right] = i;
            ++i;
            left += 2;
            right -= 2;
        }
        left = 1;
        right = n - 2;
        i = -1;
        while(left <= right){
            tag[left] = i;
            tag[right] = i;
            --i;
            left += 2;
            right -= 2;
        }
    }
    for(int i = 0; i < n; ++i){
        res += tag[i] * nums[i] % 1000000007;
    }
    while(res < 0){
        res += 1000000007;
    }
    cout << res % 1000000007 << endl;
}