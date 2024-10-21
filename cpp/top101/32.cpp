#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct HFNode{
    long long weight;
    int depth;
    HFNode *lchild, *rchild;
    HFNode(long long x): weight(x), lchild(nullptr), rchild(nullptr), depth(0){};
}; 


int main(){
    int n;
    cin >> n;
    auto cmp = [](const HFNode* a, const HFNode* b){
        return a->weight > b->weight;
    };
    priority_queue<HFNode*, vector<HFNode*>, decltype(cmp)> q(cmp);
    for(int i = 0; i < n; ++i){
        long long x;
        cin >> x;
        q.push(new HFNode(x));
    }
    for(int i = 0; i < n - 1; ++i){
        auto l = q.top(); q.pop();
        auto r = q.top(); q.pop();
        auto p = new HFNode(l->weight + r->weight);
        p->lchild = l;
        p->rchild = r;
        q.push(p);
    }
    queue<HFNode*> bfs;
    bfs.push(q.top());
    long long res = 0;
    while(!bfs.empty()){
        auto cur = bfs.front(); bfs.pop();
        if(!cur->lchild && !cur->rchild){
            res += cur->depth * cur->weight;
        }
        if(cur->lchild){
            cur->lchild->depth = cur->depth + 1;
            bfs.push(cur->lchild);
        }
        if(cur->rchild){
            cur->rchild->depth = cur->depth + 1;
            bfs.push(cur->rchild);
        }
    }
    cout << res << endl;
}