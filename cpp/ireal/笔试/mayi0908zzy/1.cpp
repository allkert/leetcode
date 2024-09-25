#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<float> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    string discount;
    cin >> discount;
    for(int i = 0; i < n; i++){
        if(discount[i] == '1'){
            prices[i] = 0.95 * prices[i];
        }
    }
    sort(prices.begin(), prices.end());
    int res = 0;
    float money = (float)k;
    for(int i = 0; money >= prices[i] && i < n; i++){
        money -= prices[i];
        res++;
    }
    cout << res << endl;
}