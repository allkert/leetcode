#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<queue>
#include<map>

using namespace std;

class soution_1311{
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int personNum = friends.size();
        queue<int> que;
        que.push(id);
        vector<bool> visited(personNum, false);
        map<string, int> count;
        vector<pair<string, int>> levelVideos;
        for(int i = 0; i < level; i++){
            count.clear();
            int length = que.size();
        }
    }
};

int main(){
    bool T = "ABCD" < "ABCE";
    cout << T;
}