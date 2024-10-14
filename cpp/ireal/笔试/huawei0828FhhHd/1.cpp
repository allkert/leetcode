#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int interval;
    cin >> interval;
    // key: 元素  value: 能消除的元素个数
    // 从这开始改
    // 先排序
    sort(nums.begin(), nums.end());

    // 然后主要是减少便利的次数
    //
    vector<bool> vis = vector<bool>(n, false);
    int visNum = 0;
    int res = INT_MAX, eleNum = -1;


    

    for(int i = 0; i < n && visNum < n; i++){
        if(vis[i]) continue;
        vis[i] = true;
        visNum++;
        int element = 1;
        for(int j = i + 1; j < n; j++){
            if((nums[j] - nums[i]) % interval == 0){
                element++;
                if(!vis[j]) visNum++;
                vis[j] = true;
            }
        }
        if(element > eleNum){
            res = nums[i];
            eleNum = element;
        }
        else if(element == eleNum){
            res = min(res, nums[i]);
        }
    }

    cout << res << endl;

    // int res = 0;
    // int element = -1;

    // for(auto item : mp){
    //     if(item.second > element){
    //         res = item.first;
    //         element = item.second;
    //     }
    //     else if(item.second == element){
    //         res = min(res, item.first);
    //     }
    // }

    // cout << res << endl;
    // 以上算法是错的，部分用例不通过，比如： 5 1 2 3 4 5 1
    // 期望输出：1
    // 实际输出：
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        map[nums[i]]++;
    }
    int interval;
    cin >> interval;
    int result = 0;
    int maxCount = 0;
    sort(nums.begin(), nums.end());
    for(int m : nums){
        int count = 0;
        if(map[m] == 0) continue;
        int t = m;
        while(t <= nums[nums.size() - 1]){
            count += map[t];
            map[t] = 0;
            t += interval;
        }
        if(count > maxCount){
            maxCount = count;
            result = m;
        }
    }
    cout << result << endl;
}