#include <iostream>
using namespace std;

//小欧有一个整数n，她每次可以进行下列操作之一
//  1. 将n减去1
//  2.将n除以k（当n能被k整除时）
// 小欧想知道，她至少需要多少次操作才能使n变成m
// 1 <= m <= n <= 10^9, 1 <= k <= 10^9

int main(){
    long long int n, m, k;
    // cin >> n >> m >> k;
    n = 10e9, m = 1, k = 1;
    long int res = 0;
    while(n != m){
        if(n % k != 0){//不能整除
            n--;//这里多了一行！！！删错了！！！！！不能整除只能减  
        }
        else{//能整除
            if(n / k < m) n--;//整除之后的数小于m,就不能整除
            else{//整除之后大于m
                // 看看那种情况下更接近m
                if(n/k -m < n - m - 1) n /= k;
                else n--;
            }
        }
        res++; 
    }
    cout << res << endl; 
}
// 第一个判断条件 只留下前三个试试不用 n > m 
