#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> path;
    void backtracking(vector<vector<string>> tickets, vector<bool> used) {
        if(path.size() == tickets.size() + 1){
            if(result.empty()){
                result = path;
                return;
            }
            else{
                result = isSmall(result, path) ? result : path;
                return;
            }
        }
        for(int i = 0; i < tickets.size(); i++){
            if(used[i] == true) continue;
            if(path.size() == 1 && tickets[i][0] != "JFK") continue;
            if(path.size() > 1 && (path.back() != tickets[i][0])) continue;
            used[i] = true;
            path.push_back(tickets[i][1]);
            backtracking(tickets, used);
            used[i] = false;
            path.pop_back();
        }
    }
    bool isSmall(vector<string> vec1, vector<string> vec2) {
        for(int i = 0; i < vec1.size(); i++){
            for(int j = 0; j < 3; j++){
                if(vec1[i][j] < vec2[i][j]) return true;
                if(vec1[i][j] > vec2[i][j]) return false; 
            }
        }
        return true;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<bool> used(tickets.size(), false);
        path.push_back("JFK");
        backtracking(tickets, used);
        return result;
    }
};


// void test(int &a){
//     a = 1;
// }
int main() {
    vector<vector<string>> s = {{"AXA","EZE"},{"EZE","AUA"},{"ADL","JFK"},{"ADL","TIA"},{"AUA","AXA"},{"EZE","TIA"},{"EZE","TIA"},{"AXA","EZE"},{"EZE","ADL"},{"ANU","EZE"},{"TIA","EZE"},{"JFK","ADL"},{"AUA","JFK"},{"JFK","EZE"},{"EZE","ANU"},{"ADL","AUA"},{"ANU","AXA"},{"AXA","ADL"},{"AUA","JFK"},{"EZE","ADL"},{"ANU","TIA"},{"AUA","JFK"},{"TIA","JFK"},{"EZE","AUA"},{"AXA","EZE"},{"AUA","ANU"},{"ADL","AXA"},{"EZE","ADL"},{"AUA","ANU"},{"AXA","EZE"},{"TIA","AUA"},{"AXA","EZE"},{"AUA","SYD"},{"ADL","JFK"},{"EZE","AUA"},{"ADL","ANU"},{"AUA","TIA"},{"ADL","EZE"},{"TIA","JFK"},{"AXA","ANU"},{"JFK","AXA"},{"JFK","ADL"},{"ADL","EZE"},{"AXA","TIA"},{"JFK","AUA"},{"ADL","EZE"},{"JFK","ADL"},{"ADL","AXA"},{"TIA","AUA"},{"AXA","JFK"},{"ADL","AUA"},{"TIA","JFK"},{"JFK","ADL"},{"JFK","ADL"},{"ANU","AXA"},{"TIA","AXA"},{"EZE","JFK"},{"EZE","AXA"},{"ADL","TIA"},{"JFK","AUA"},{"TIA","EZE"},{"EZE","ADL"},{"JFK","ANU"},{"TIA","AUA"},{"EZE","ADL"},{"ADL","JFK"},{"ANU","AXA"},{"AUA","AXA"},{"ANU","EZE"},{"ADL","AXA"},{"ANU","AXA"},{"TIA","ADL"},{"JFK","ADL"},{"JFK","TIA"},{"AUA","ADL"},{"AUA","TIA"},{"TIA","JFK"},{"EZE","JFK"},{"AUA","ADL"},{"ADL","AUA"},{"EZE","ANU"},{"ADL","ANU"},{"AUA","AXA"},{"AXA","TIA"},{"AXA","TIA"},{"ADL","AXA"},{"EZE","AXA"},{"AXA","JFK"},{"JFK","AUA"},{"ANU","ADL"},{"AXA","TIA"},{"ANU","AUA"},{"JFK","EZE"},{"AXA","ADL"},{"TIA","EZE"},{"JFK","AXA"},{"AXA","ADL"},{"EZE","AUA"},{"AXA","ANU"},{"ADL","EZE"},{"AUA","EZE"}};
    Solution t;
    t.findItinerary(s);
}