// https://leetcode-cn.com/problems/course-schedule-ii/
class Solution {
private:
    vector<int> res;
    bool haveCycle = false;
    vector<bool> visited;
    vector<bool> onPath;
    // 建图
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);  // 不要忘记！
        for(vector<int> side : prerequisites) {
            int from = side[1];
            int to = side[0];
            graph[from].push_back(to);
        }
        return graph;
    }
    // DFS遍历
    void traverse(int node, vector<vector<int>>& graph) {
        // 判断是否已经在路径
        if(onPath[node]) {
            haveCycle = true;
        }
        // 返回条件
        if(haveCycle || visited[node]) {
            return;
        }
        // 遍历子结点
        visited[node] = true;
        onPath[node] = true;
        for(int sonNode : graph[node]) {
            traverse(sonNode, graph);
        }
        // 后序位置放入结点
        res.push_back(node);
        onPath[node] = false;
    }

public:
    // DFS方法 后序遍历
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        onPath.resize(numCourses);
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        for(int i = 0; i < numCourses; i++) {
            traverse(i, graph);
        }
        if(haveCycle) return vector<int>();  // 有环，返回空
        else {
            reverse(res.begin(), res.end());  // 最后反序输出
            return res;  // 无环，返回res
        }
    }
};