#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> candies(5, 0);
    for(int i = 0; i < 5; i++){
        cin >> candies[i];
    }
    for(int i = 0; i < 5; i++){
        int q = candies[i] / 3;
        candies[i] = q;
        candies[(i - 1 + 5) % 5] += q;
        candies[(i + 1) % 5] += q;
    }
    for(int i = 0; i < 4; i++){
        cout << candies[i] << " ";
    }
    cout << candies[4] << endl;
}
