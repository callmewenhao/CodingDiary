// https://leetcode-cn.com/problems/is-graph-bipartite/
class Solution {
private:
    bool isBi = true;
    vector<bool> visited;
    vector<bool> color;
    
public:
    // BFS方法
    // 要注意本题针对无向无环图！
    bool isBipartite(vector<vector<int>>& graph) {
        int numNode = graph.size();
        queue<int> qNode;
        visited.resize(numNode);
        color.resize(numNode);
        for(int node = 0; node < numNode; node++) {
            // 剪枝
            if(visited[node]) continue;
            // 访问
            visited[node] = true;
            qNode.push(node);
            while(!qNode.empty() && isBi) {
                // 取出本结点
                int curNode = qNode.front();
                qNode.pop();
                // 访问子结点
                for(int sonNode : graph[curNode]) {
                    if(!visited[sonNode]) {
                        visited[sonNode] = true;
                        color[sonNode] = !color[curNode];
                        qNode.push(sonNode);
                    } else {
                        if(color[sonNode] == color[curNode])
                            isBi = false;
                    }
                }
            }
        }
        return isBi;
    }
};


