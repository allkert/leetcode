#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

float caluculate_time(int dis, int crowd, int light){
    float dis_f = dis;
    float crowd_f = crowd;
    float light_f = light;
    return 0.1*(dis_f - crowd_f) + 0.2 * crowd_f + 7.5 * light_f;
}

int main(){
    vector<int> dis;
    vector<int> crowd;
    vector<int> light;
    vector<int> level;
    // 读取一行
    string s;
    getline(cin, s);
    // 将这一行作为一个字符串流
    stringstream ss(s);
    // 读取字符串，直到遇到逗号
    string temp;
    while(getline(ss, temp, ',')){
        dis.push_back(stoi(temp));
    }
    getline(cin, s);
    stringstream ss2(s);
    while(getline(ss2, temp, ',')){
        crowd.push_back(stoi(temp));
    }
    getline(cin, s);
    stringstream ss3(s);
    while(getline(ss3, temp, ',')){
        light.push_back(stoi(temp));
    }
    getline(cin, s);
    stringstream ss4(s);
    while(getline(ss4, temp, ',')){
        level.push_back(stoi(temp));
    }
    vector<int> time(dis.size(), 0);
    // float的最大值是F
    float minT = __FLT_MAX__;
    int Le;
    int minIndex;
    for(int i = 0; i < dis.size(); i++){
        time[i] = caluculate_time(dis[i], crowd[i], light[i]);
        if(time[i] < minT){
            minT = time[i];
            Le = level[i];
            minIndex = i;
        }
    }
    // float curtime = __FLT_MAX__;
    // int curLe = Le;
    // for(int i = 0; i < dis.size(); i++) cout << time[i] << endl;
    // for(int i = 0; i < dis.size(); i++) cout << level[i] << endl;
    // for(int i = 0; i < dis.size(); i++){
    //     if(time[i] < minT + 60){
    //         if(level[i] > curLe){
    //             curLe = level[i];
    //             minIndex = i;
    //             curtime = time[i];
    //         }
    //         else if(level[i] == curLe){
    //             if(time[i] < curtime){
    //                 curtime = time[i];
    //                 minIndex = i;
    //             }
    //         }
    //     }
    // }
    int curLe = Le;
    for(int i = 0; i < dis.size(); i++){
        if(time[i] < minT + 60){
            if(level[i] >= curLe){
                curLe = level[i];
                minIndex = i;
            }    
        }
    }
    cout << minIndex + 1 << "," << time[minIndex] << endl;
}