#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

// 自定义哈希函数，用于unordered_set
struct PointHash {
    size_t operator()(const Point& p) const {
        return hash<int>()(p.x) ^ hash<int>()(p.y);
    }
};

// 检查点是否在网格内且不是障碍点
bool isValid(const Point& p, const unordered_set<Point, PointHash>& obstacles) {
    return obstacles.find(p) == obstacles.end();
}

// 广度优先搜索
int bfs(Point start, Point end, const unordered_set<Point, PointHash>& obstacles) {
    queue<pair<Point, int>> q;  // 队列存储点及其路径长度
    unordered_set<Point, PointHash> visited;  // 记录已访问的点

    q.push({start, 0});
    visited.insert(start);

    vector<Point> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 四个方向

    while (!q.empty()) {
        auto [current, dist] = q.front();
        q.pop();

        // 如果当前点是终点，返回路径长度
        if (current == end) {
            return dist;
        }

        // 遍历四个方向
        for (const auto& dir : directions) {
            Point next(current.x + dir.x, current.y + dir.y);

            // 检查下一个点是否有效且未访问过
            if (isValid(next, obstacles) && visited.find(next) == visited.end()) {
                q.push({next, dist + 1});
                visited.insert(next);
            }
        }
    }

    // 如果无法到达终点，返回-1
    return -1;
}

int main() {
    Point A(0, 0);
    Point B(3, 3);
    Point F(1, 1);

    unordered_set<Point, PointHash> obstacles = {F};

    int shortestPath = bfs(A, B, obstacles);

    if (shortestPath != -1) {
        cout << "Shortest path from A to B: " << shortestPath << endl;
    } else {
        cout << "No path from A to B." << endl;
    }

    return 0;
}