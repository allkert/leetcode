#include<iostream>
#include <vector>


using namespace std;

// int main() {
//     // int n;
//     // cin >> n;
//     // for(int i = 0; i < n; i++){
//     //     int zoneNum, leastCover;
//     //     cin >> zoneNum >> leastCover;
//     //     vector<int> zone(zoneNum, 0);
//     //     for(int j = 0; j < zoneNum; j++){
//     //         cin >> zone[j];
//     //     }
//     int zoneNum = 8, leastCover = 3;
//     vector<int> zone = {4, 5, 6, 7, 9, 9, 6, 8};
//     int left = 0, right = 0;
//     int sum = 0;
//     double res = 0;
//     while(right < zoneNum){
//         if(right - left < leastCover){
//             sum += zone[right];
//             right++; 
//         }
//         else{
//             double average = sum * 1.0 / (right - left);
//             if(zone[right] > average){
//                 sum += zone[right];
//                 right++;
//             }
//             while(right - left >= leastCover){
//                 res = max(res, sum * 1.0 / (right - left));
//                 sum -= zone[left];
//                 left++;
//             }
//         }
//     }
//     printf("%.3f\n", res);
// }
int count(string s){
    int f = 0;
    for(int i = 0; i < s.size() - 1; i++){
        f += 10*(s[i] - '0') + (s[i+1] - '0'); 
    }
    return f;
}
int main(){
    cout << count("10101") << endl;
}