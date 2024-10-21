#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */

    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            bool tag = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    tag = true;
                }
            }
            if (!tag) break;
        }
    }
    void quickSort1(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int l = left, r = right, provit = nums[left];
        while (l < r) {
            while (nums[r] > provit && l < r) r--;
            while (nums[l] < provit && l < r) l++;
            if (r > l) swap(nums[l], nums[r]);
        }
        quickSort1(nums, left, l - 1);
        quickSort1(nums, r + 1, right);
    }
    void quickSort2(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int l = left, r = right, provit = nums[left];
        while (l < r) {
            while (nums[r] >= provit && l < r) r--;
            nums[l] = nums[r];
            while (nums[l] <= provit && l < r) l++;
            nums[r] = nums[l];
        }
        nums[l] = provit;
        quickSort2(nums, left, l - 1);
        quickSort2(nums, r + 1, right);
    }

    void selectSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            if (i != minIndex) swap(nums[i], nums[minIndex]);
        }
    }

    void insertSort(vector<int>& nums) {
        int n = nums.size();
        int j;
        for (int i = 1; i < n; ++i) {
            int temp = nums[i];
            for (j = i - 1; j >= 0 && nums[j] > temp; --j) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = temp;
            // nuns
        }
    }

    void shellSort(vector<int>& nums){
        int n = nums.size();
        int i, j, tmp, increment;
        for(increment = n / 2; increment > 0; increment /= 2){
            for(i = increment; i < n; ++i){
                tmp = nums[i];
                for(j = i - increment; j >= 0 && nums[j] > tmp; j -= increment) nums[j + increment] = nums[j];
                nums[j+increment] = tmp;
            }            
        }
    } 

    void merge(vector<int>& nums, int L, int M, int R){
        int lSize = M - L + 1, rSize = R - M;
        vector<int> l(lSize), r(rSize);
        int i, j, k;
        for(i = L; i <= M; ++i) l[i-L] = nums[i];
        for(i = M + 1; i <= R; ++i) r[i - M - 1] = nums[i];
        i = 0, j = 0, k = L;
        while(i < lSize && j < rSize) nums[k++] = l[i] < r[j] ? l[i++] : r[j++];
        while(i < lSize) nums[k++] = l[i++];
        while(j < rSize) nums[k++] = r[j++]; 
    }

    void mergeSort(vector<int>& nums, int L, int R){
        if(L == R) return;
        int M = (L + R) / 2;
        mergeSort(nums, L, M);
        mergeSort(nums, M+1, R);
        merge(nums, L, M, R);
    }

    void countSort(vector<int>& nums){
        if(nums.size() <= 1) return;
        int max_ = -INT_MAX, min_ = INT_MAX;
        for(auto num : nums){
            max_ = max(max_, num);
            min_ = min(min_, num);
        }
        int r = max_ - min_ + 1;
        vector<int> count(r);
        vector<int> tempNums(nums.size());
        for(int num : nums) count[num - min_]++;
        for(int i = 1; i < r; ++i) count[i] += count[i-1];
        for(int i = nums.size() - 1; i >= 0; --i){
            tempNums[--count[nums[i] - min_]] = nums[i];
        } 
        for(int i = 0; i < nums.size(); i++) nums[i] = tempNums[i];
    } 

    void bucketSort(vector<int>& arr){
        int n = arr.size();
        if(n <= 1) return;
        int max_val = *max_element(arr.begin(), arr.end());
        int min_val = *min_element(arr.begin(), arr.end());
        int bucketSize = max_val - min_val + 1;
        int bucketCount = 10;
        vector<vector<int>> bucket(bucketCount);
        for(auto num : arr){
            int index = (num - min_val) / bucketSize * bucketCount;
            bucket[index].push_back(num);
        }
        for(auto& b : bucket) sort(b.begin(), b.end());
        int index = 0;
        for(auto& b : bucket){
            for(auto num : b){
                arr[index++] = num;
            }
        }
    }


    vector<int> MySort(vector<int>& arr) {
        // write code here
        bucketSort(arr);
        return arr;
    }
};