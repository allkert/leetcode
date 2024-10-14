#include<iostream>
#include<vector>
#include<map>

using namespace std;

int find(vector<int>& nums, int target){
    for(int i = 1; i <= nums.size(); ++i){
        if(nums[i] == target) return i;
    }
    return 0;
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> nums(n + 1);
    for(int i = 1; i <= n; ++i){
        nums[i] = i;
    }

    for(int i = 0; i < q; ++i){
        string a, b, op;
        cin >> a >> b >> op;
        int a1 = stoi(a), b1 = stoi(b), op1 = stoi(op);
        int index1 = find(nums, a1);
        int index2 = find(nums, b1);
        if(op1 == 0){
            if(index1 < index2){
                for(int i = index1; i < index2 - 1; ++i){
                    nums[i] = nums[i+1];
                }
                nums[index2-1] = a1;
            }
            else{
                for(int i = index1 - 1; i >= index2; --i){
                    nums[i+1] = nums[i];
                }
                nums[index2] = a1;
            }
        }
        else{
            if(index1 < index2){
                for(int i = index1; i < index2; ++i){
                    nums[i] = nums[i+1];
                }
                nums[index2] = a1;
            }
            else{
                for(int i = index1 - 1; i >= index2; --i){
                    nums[i+1] = nums[i];
                }
                nums[index2] = a1;
            }
        }
    }
    for(int i = 1; i < n; ++i){
        cout << nums[i] << ' ';
    }
    cout << nums[n] << endl;
}