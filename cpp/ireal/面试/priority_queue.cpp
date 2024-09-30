#include<vector>

using namespace std;
// 小根堆的底层实现
class MinHeap {
  private:
    vector<int> data;
    // siftUp: 从下往上调整, 保证堆的性质
    // 将子节点不停的和父节点比较, 如果子节点小于父节点, 则交换
    // 这个并不会破坏父节点的另外一个子树的堆性质
    void siftUp(int k) {
        while (k > 0 && data[(k - 1) / 2] > data[k]) {
            // (k-1)/2 是父节点的下标, 注意从0开始
            swap(data[(k - 1) / 2], data[k]);
            k = (k - 1) / 2;
        }
    }

    // siftDown: 从上往下调整, 保证堆的性质
    void siftDown(int k) {
        // 判断条件确保有孩子节点存在
        while (2 * k + 1 < data.size()) {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            // 找到当前节点和左右孩子节点中最小的那个
            int smallest = k;
            if (data[left] < data[smallest]) smallest = left;
            if (right < data.size() && data[right] < data[smallest]) smallest = right;
            // 最小的是当前节点, 说明已经满足堆性质
            if (smallest == k) break;
            swap(data[k], data[smallest]);
            // 被交换的子节点的堆性质可能被破坏，因此需要继续向下检查
            k = smallest;
        }
    }
  public:
    // 作为数据结构应该提供的操作接口
    void push(int val) {
        data.push_back(val);
        // 向上调整
        siftUp(data.size() - 1);
    }
    void pop() {
        // 把第一个元素放到最后去
        swap(data[0], data[data.size() - 1]);
        // 向下调整第一个元素
        data.pop_back();
        siftDown(0);
    }
    int top() {
        return data[0];
    }
    bool empty() {
        return data.empty();
    }
    int size() {
        return data.size();
    }
};


class MaxHeap{
private:
    vector<int> data;
    void shiftup(int k){
        while(k > 0 && data[(k-1)/2] < data[k]){
            swap(data[(k-1)/2], data[k]);
            k = (k - 1)/2;
        }
    }
    void shiftdown(int k){
        while( 2 * k + 1 < data.size()){
            int left = 2 * k + 1, right = 2 * k + 2;
            int mmax = k;
            if(data[left] > data[mmax]) mmax = left;
            if(right < data.size() && data[right] > data[mmax]) mmax = right;
            if(mmax == k) break;
            swap(data[k], data[mmax]);
            k = mmax;
        }
    }

public:
    void push(int x){
        data.push_back(x);
        shiftup(data.size() - 1);
    }
    void top(){
        if(data.size() == 0) cout << "empty" << endl;
        else cout << data[0] << endl;
    }
    void pop(){
        if(data.size() == 0){
            cout << "empty" << endl;
            return;
        }
        cout << data[0] << endl;
        swap(data[0], data[data.size() - 1]);
        data.pop_back();
        shiftdown(0);
    }
};

int main() {
    int n;
    cin >> n;
    MaxHeap mheap;
    string op;
    for(int i = 0; i < n; i++){
        int x;
        cin >> op;
        if(op == "push"){
            cin >> x;
            mheap.push(x);
        }
        else if(op == "top"){
            mheap.top();
        }
        else{
            mheap.pop();
        }
    }  
}
// 64 位输出请用 printf("%lld")