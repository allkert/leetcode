#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

// 原地删除出现次数超过三次的元素
int removenums(vector<int> &nums){
    if(nums.size() == 0) return 0;
    int i = 0, j = 0;
    unordered_map<int, int> count;
    while(j < nums.size()){
        cout << "i: " << i << " j: " << j << endl;
        if(count[nums[j]] < 2){
            count[nums[j]]++;
            nums[i++] = nums[j++];
        }
        else{
            j++;
        }    
    }
    nums.resize(i);
    return i;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 2, 3};
    removenums(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}