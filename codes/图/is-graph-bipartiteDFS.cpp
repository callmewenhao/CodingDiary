// https://leetcode-cn.com/problems/is-graph-bipartite/
class Solution {
private:
    vector<bool> visited;
    vector<bool> color;
    bool isBip = true;
    // DFS
    void traverse(int node, vector<vector<int>>& graph) {
        // 如果已经不是二分图，直接返回
        if(!isBip) return;
        // 访问本结点
        visited[node] = true;
        for(int sonNode : graph[node]) {
            // 访问子结点
            if(!visited[sonNode]) {
                // 赋予不同颜色
                color[sonNode] = !color[node];
                traverse(sonNode, graph);
            } else {
                // 判断颜色是否相同
                if(color[node] == color[sonNode])
                    isBip = false;
            }
        }
    }
public:
    // DFS方法
    bool isBipartite(vector<vector<int>>& graph) {
        // 结点个数
        int numNode = graph.size();
        visited.resize(numNode);
        color.resize(numNode);
        // 初始化第一个结点颜色
        for(int node = 0; node < numNode; node++) {
            traverse(node, graph);
        }
        // 返回
        return isBip;
    }
};
