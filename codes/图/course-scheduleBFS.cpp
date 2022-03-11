// https://leetcode-cn.com/problems/course-schedule/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> inDegree;
public:
    // BFS方法
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;   // 记录BFS遍历的结点数
        queue<int> qNode;  // 放入度为零的子结点
        graph.resize(numCourses);
        inDegree.resize(numCourses);
        // 建图和入度数组
        for(vector<int> side : prerequisites) {
            int from = side[1];   // 想要to必须有from
            int to = side[0];
            graph[from].push_back(to);  // from->to
            inDegree[to]++;  // 入度增加
        }
        // 找起始结点放入队列
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0)
                qNode.push(i);
        }
        while(!qNode.empty()) {
            int curNode = qNode.front();
            qNode.pop();
            // 访问到的结点计数
            count++;
            // 访问子结点
            for(int node : graph[curNode]) {
                inDegree[node]--;  // 更新入度
                if(inDegree[node] == 0) {
                    qNode.push(node);  // 放入入度为零的子结点
                }
            }
        }
        return count == numCourses;  // 结果
    }
};

