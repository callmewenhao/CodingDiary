// https://leetcode-cn.com/problems/path-with-minimum-effort/
struct State {
    // 矩阵中的一个位置
    int x, y;
    // 从起点 (0, 0) 到当前位置的最小体力消耗（距离）
    int effortFromStart;

    State(int x, int y, int effortFromStart) {
        this->x = x;
        this->y = y;
        this->effortFromStart = effortFromStart;
    }
};

bool operator<(State a, State b) {
    return a.effortFromStart > b.effortFromStart;  // 升序
}

class Solution {
private:
    // 返回坐标 (x, y) 的上下左右相邻坐标
    vector<vector<int>> adj(vector<vector<int>>& matrix, int x, int y) {
        // 方向数组，上下左右的坐标偏移量
        int dirs[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int m = matrix.size(), n = matrix[0].size();
        // 存储相邻节点
        vector<vector<int>> neighbors;
        for (int* dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= m || nx < 0 || ny >= n || ny < 0) {
                // 索引越界
                continue;
            }
            neighbors.push_back(vector<int>{nx, ny});
        }
        return neighbors;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 行列数
        int row = heights.size();
        int colums = heights[0].size();
        vector<int> effort(row * colums, INT_MAX);  // 二维数组转成一维数组存储
        // 优先队列
        priority_queue<State> pq;
        // 起点
        effort[0] = 0;
        pq.push(State(0, 0, 0));
        // 遍历子结点
        while(!pq.empty()) {
            State curNode = pq.top();
            pq.pop();
            int curX = curNode.x;
            int curY = curNode.y;
            // 由于堆优化，第一次找到左下角的effort就是最小的
            if(curX == row - 1 && curY == colums - 1) {
                return effort[curX * colums + curY];
            }
            // 提前进入下轮循环
            if(curNode.effortFromStart > effort[curX * colums + curY]) continue;
            // 子结点
            for(vector<int>& neighbor : adj(heights, curX, curY)) {
                int neighborX = neighbor[0];
                int neighborY = neighbor[1];
                // 以当前结点为中间点，计算起点到下一结点的距离
                int effortFromStart = max(
                    effort[curX * colums + curY],
                    abs(heights[curX][curY] - heights[neighborX][neighborY])
                );
                // 更新
                if(effortFromStart < effort[neighborX * colums + neighborY]) {
                    effort[neighborX * colums + neighborY] = effortFromStart;
                    pq.push(State(neighborX, neighborY, effortFromStart));
                }
            }
        }
        return -1;
    }
};



