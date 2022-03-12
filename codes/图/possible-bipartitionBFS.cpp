// https://leetcode-cn.com/problems/possible-bipartition/
class Solution {
private:
    bool isBi = true;
    vector<bool> visited;
    vector<bool> color;
    // 思路同二分图判断
    void BFS(int node, vector<vector<int>>& graph) {
        visited[node] = true;
        queue<int> qNode;
        qNode.push(node);
        while(!qNode.empty()) {
            int curNode = qNode.front();
            qNode.pop();
            for(int sonNode : graph[curNode]) {
                //
                if(!visited[sonNode]) {
                    visited[sonNode] = true;
                    color[sonNode] = !color[curNode];
                    qNode.push(sonNode);
                } else {
                    if(color[sonNode] == color[curNode]) {
                        isBi = false;
                        return;
                    }          
                }
            }
        }
    }

public:
    // 这里就使用BFS来写
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        visited.resize(n);
        color.resize(n);
        vector<vector<int>> graph(n);
        for(vector<int> side : dislikes) {
            int from = side[0] - 1;
            int to = side[1] - 1;
            // 建立无向图
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        // BFS
        for(int node = 0; node < n; node++) {
            // 使用isBi提前结束
            if(isBi) {
                if(!visited[node]) {
                    BFS(node, graph);
                }
            } else {
                break;
            } 
        }
        // 返回
        return isBi;
    }
};
