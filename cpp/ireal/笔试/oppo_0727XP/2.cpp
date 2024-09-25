#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main(){
    // string s, a, b;
    // cin >> s >> a >> b;
    // vector<int> counts(26);
    // vector<int> counta(26);
    // vector<int> countb(26);
    // for(char ss : s){
    //     counts[ss - 'a']++;
    // }
    // // a, b所有字符都改为小写
    // for(char aa : a){
    //     if(aa >= 'A' && aa <= 'Z'){
    //         aa = aa - 'A' + 'a';
    //     }
    //     counta[aa - 'a']++;
    // }
    // for(char bb : b){
    //     if(bb >= 'A' && bb <= 'Z'){
    //         bb = bb - 'A' + 'a';
    //     }
    //     countb[bb - 'a']++;
    // }
    string a = "ABCDEF";
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    cout << a << endl;
}
