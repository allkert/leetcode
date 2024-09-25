#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class SortAlgorithm{
public:
    // 1. 冒泡排序
    /*  最好的情况：原数组本来就是有序的，时间复杂度为O(n)
        最坏的情况：原数组是逆序的，时间复杂度为O(n^2)
    */
    void bubbleSort(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(nums[j] > nums[j + 1]){
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    // 2. 快速排序
    // 选取一个基准值，将小于基准值的放在左边，大于基准值的放在右边
    // 最好的情况：每次选取的基准值都是中位数，时间复杂度为O(nlogn)
    // 最坏的情况：每次选取的基准值都是最大值或最小值，时间复杂度为O(n^2)
    void quickSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int i = left, j = right;
        int pivot = nums[left];
        while(i < j){
            while(i < j && nums[j] >= pivot){
                j--;
            }
            while(i < j && nums[i] <= pivot){
                i++;
            }
            if(i < j){
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[i]);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }  

    // 3. 简单插入排序
    // 从第二个元素开始，将当前元素插入到前面已经排好序的序列中
    // 最好的情况：原数组本来就是有序的，时间复杂度为O(n)
    // 最坏的情况：原数组是逆序的，时间复杂度为O(n^2)
    void insertSort(vector<int>& nums){
        int n = nums.size();
        for(int i = 1; i < n; i++){
            int j = i - 1;
            int temp = nums[i];
            while(j >= 0 && nums[j] > temp){
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }
    }

    // 4. 希尔排序: 插入排序的改进版
    // 选择一个增量序列，对每个增量进行插入排序, 相较于插入排序，这样做的好处是可以减少元素的移动次数
    // 最好的情况：时间复杂度为O(nlogn)
    // 最坏的情况：时间复杂度为O(n^2)
    void shellSort(vector<int>& nums){
        int n = nums.size();
        for(int gap = n / 2; gap > 0; gap /= 2){
            for(int i = gap; i < n; i++){
                int j = i - gap;
                int temp = nums[i];
                while(j >= 0 && nums[j] > temp){
                    nums[j + gap] = nums[j];
                    j -= gap;
                }
                nums[j + gap] = temp;
            }
        }
    }  

    // 5. 选择排序
    // 每次选择最小的元素放在前面
    // 最好的情况：时间复杂度为O(n^2)
    // 最坏的情况：时间复杂度为O(n^2)
    // 不稳定排序
    void selectSort(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int minIndex = i;
            for(int j = i + 1; j < n; j++){
                if(nums[j] < nums[minIndex]){
                    minIndex = j;
                }
            }
            swap(nums[i], nums[minIndex]);
        }
    }

    // 6. 归并排序
    // 将数组分成两部分，分别排序，然后合并
    // 最好的情况：时间复杂度为O(nlogn)
    // 最坏的情况：时间复杂度为O(nlogn)
    // 稳定排序
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }else{
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid){
            temp[k++] = nums[i++];
        }
        while(j <= right){
            temp[k++] = nums[j++];
        }
        for(int i = 0; i < temp.size(); i++){
            nums[left + i] = temp[i];
        }
    }
};  

int main(){
    vector<int> nums = {3, 2, 1, 5, 4};
    SortAlgorithm sa;
    // sa.bubbleSort(nums);
    sa.mergeSort(nums, 0, nums.size() - 1);
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}