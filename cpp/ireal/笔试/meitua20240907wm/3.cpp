#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std; 

void countChildNum(vector<vector<int>> &nums, int index, unordered_map<int, int> &childNums){
    childNums[index] = nums[index].size();
    for(auto num : nums[index]){
        countChildNum(nums, num, childNums);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int numNum;
        cin >> numNum;
        vector<vector<int>> nums(numNum + 1);  // 1-indexed
        // n-1条边
        int x, y;
        for(int j = 0; j < numNum - 1; j++){
            cin >> x >> y;
            nums[x].push_back(y);
        }
        // 计算每个节点的子节点数
        unordered_map<int, int> childNums;
        countChildNum(nums, 1, childNums);
        //  有n个子节点的节点数量
        int count = 0;
        unordered_map<int, int> countMap;
        for(auto childNum : childNums){
            countMap[childNum.second]++;
        }
        for(auto c : countMap){
            if(c.second != 0){
                count += c.second * (c.second - 1) / 2;
            }
        }
        cout << count << endl;
    }
}