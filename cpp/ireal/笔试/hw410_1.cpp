#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

vector<string> spilt(string s, char key){
    int start = 0;
    vector<string> res;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == key){
            res.push_back(s.substr(start, i - start));
            start = i + 1;
        }
    }
    res.push_back(s.substr(start, s.size() - start));
    return res;
}

int main(){
    int n, m;
    cin >> n;
    map<string, int> res;
    map<vector<string>, int> _info;
    // 获取所有有效的词条
    for(int i = 0; i < n; i++){
        string lineIn;
        cin >> lineIn;
        // 获取分割好的信息
        vector<string> spiltinfo = spilt(lineIn, ',');
        vector<string> key(spiltinfo.begin(), spiltinfo.begin()+3);
        int value = stoi(spiltinfo[3]);
        // 确认没有重复的词条
        if(_info.find(key) == _info.end()) _info.insert(pair<vector<string>, int>(key, value));
    }

    // 获取计费因子单价
    map<string, int> price;
    cin >> m;
    for(int i = 0; i < m; i++){
        string lineIn;
        cin >> lineIn;
        // 获取分割好的信息, _size = 2
        vector<string> spiltinfo = spilt(lineIn, ',');
        price.insert(pair<string, int>(spiltinfo[0], stoi(spiltinfo[1])));        
    }
    
    // 逐条读取词条
    for(map<vector<string>, int>::iterator it = _info.begin(); it != _info.end(); it++){
        string factor = (it->first)[2];
        string cilent = (it->first)[1];
        int time = it->second;
        if(time >= 1 && time <= 100){
            res[cilent] += price[factor] * time;
        }
    }

    // 输出
    for(map<string, int>::iterator it = res.begin(); it != res.end(); it++){
        cout << it->first << ',' << it->second << endl;
    }

}