// 一张考卷由n个选择题，m个填空题，k个简答题
// 选择题每题分值为a，填空题每题分值为b，简答题每题分值为c
// 请问是否存在三个正整数a,b,c使得a*n+b*m+c*k = 100
// 如果存在输出YES，然后输出一个满足条件的a,b,c
// 如果不存在输出NO
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n, m, k;
        cin >> n >> m >> k;
        int a = 0, b = 0, c = 0;
        for(int j = 1; j <= 100; j++){
            if(100 % j == 0){
                int temp = 100 / j;
                if(temp >= n && temp >= m && temp >= k){
                    a = j;
                    b = temp;
                    c = temp;
                    break;
                }
            }
        }
    }
}