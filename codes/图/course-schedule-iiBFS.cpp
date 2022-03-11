// https://leetcode-cn.com/problems/course-schedule-ii/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> inDegree;
public:
    // BFS方法
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;
        vector<int> res;
        queue<int> qNode;
        graph.resize(numCourses);
        inDegree.resize(numCourses);
        // 建图和入读表
        for(vector<int> side : prerequisites) {
            int from = side[1];
            int to = side[0];
            graph[from].push_back(to);
            inDegree[to]++;
        }
        // 起始：把入读为0的点放入队列
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                qNode.push(i);
            }
        }
        // BFS
        while(!qNode.empty()) {
            int curNode = qNode.front();
            qNode.pop();
            count++;
            res.push_back(curNode);
            for(int sonNode : graph[curNode]) {
                inDegree[sonNode]--;
                if(inDegree[sonNode] == 0) {
                    qNode.push(sonNode);
                }  
            }
        }
        if(count != numCourses) return vector<int>();  // 有环：vector<int>()是空vector
        else return res; // 无环
    }
};





