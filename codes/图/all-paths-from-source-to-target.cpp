// https://leetcode-cn.com/problems/all-paths-from-source-to-target/
// 注意总结图遍历的套路
class Solution {
private:
    vector<vector<int>> allPaths;
    void findAllPaths(vector<vector<int>>& graph, int node, vector<int>& path){
        path.push_back(node);
        // 找到了该结点
        if(node == graph.size() - 1) {
            allPaths.push_back(vector<int> (path));
            path.pop_back();
            return;
        }
        // 处理graph[node]不为空的情况
        for(int n : graph[node]) {
            findAllPaths(graph, n, path);
        }
        // 处理graph[node]为空的情况，把该结点pop出来，返回后继续外层循环
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        findAllPaths(graph, 0, path);
        return allPaths;
    }
};

