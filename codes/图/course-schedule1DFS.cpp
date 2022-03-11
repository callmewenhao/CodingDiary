// https://leetcode-cn.com/problems/course-schedule/
class Solution {
private:
    vector<bool> visited;
    vector<bool> onPath;
    bool haveCycle = false;
    
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(vector<int> side : prerequisites) {
            int from = side[1];
            int to = side[0];
            graph[from].push_back(to);
        }
        return graph;
    }
    // DFS方法
    void traverse(int curNode, vector<vector<int>>& graph) {
        if(onPath[curNode]) haveCycle = true;
        if(haveCycle || visited[curNode]) return;
        visited[curNode] = true;  // 这是前序的位置
        onPath[curNode] = true;  // 当前结点加入路径
        for(int node : graph[curNode]) {
            traverse(node, graph);
        }
        onPath[curNode] = false;  // 当前结点移除路径
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        onPath.resize(numCourses);
        // 建图
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        for(int i = 0; i < numCourses; i++) {
            traverse(i, graph);
        }
        return !haveCycle;
    }
};

