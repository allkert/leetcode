class solution_2608{
// public:
//     int findShortestCycle(int n, vector<vector<int>>& edges){
//         vector<vector<int>> g(n, vector<int>());
//         for(auto &e : edges){
//             g[e[0]].push_back(e[1]);
//             g[e[1]].push_back(e[0]);
//         }

//         vector<int> dis(n, -1);
//         auto bfs = [&](int start) -> int{
//             int ans = INT_MAX;
//             dis[start] = 0;
//             queue<pair<int, int>> q;
//             q.emplace(pair<int, int>(start, -1));
//             return 1;
//         };
//         return 0;
//     }
// };