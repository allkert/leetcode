#include<iostream>
#include<vector>

using namespace std;

void merge1(vector<int>& numsA, vector<int>& numsB, int i, int j, vector<int>& res, int k){
    if(i == numsA.size() && j == numsB.size()){
        return;
    }
    if(i == numsA.size()){
        res[k] = numsB[j];
        merge1(numsA, numsB, i, j + 1, res, k + 1);
    }else if(j == numsB.size()){
        res[k] = numsA[i];
        merge1(numsA, numsB, i + 1, j, res, k + 1);
    }else{
        if(numsA[i] < numsB[j]){
            res[k] = numsA[i];
            merge1(numsA, numsB, i + 1, j, res, k + 1);
        }else{
            res[k] = numsB[j];
            merge1(numsA, numsB, i, j + 1, res, k + 1);
        }
    }
}

int main(){
    int m, n;
    cin >> m;
    vector<int> numsA(m);
    for(int i = 0; i < m; i++){
        cin >> numsA[i];
    }
    cin >> n;
    vector<int> numsB(n);
    for(int i = 0; i < n; i++){
        cin >> numsB[i];
    }
    vector<int> res(m + n);
    merge1(numsA, numsB, 0, 0, res, 0);
    for(int i = 0; i < m + n - 1; i++){
        cout << res[i] << " ";
    }
    cout << res[m + n - 1] << endl;
}
