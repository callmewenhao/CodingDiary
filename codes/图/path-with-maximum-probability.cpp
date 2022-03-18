// https://leetcode-cn.com/problems/path-with-maximum-probability/
struct State { 
public:
    int id;
    double probFromStart;
    State(int id, double probFromStart) {
        this->id = id;  // 我感觉最好不要重名
        this->probFromStart = probFromStart;
    }
};
bool operator<(State a, State b) {
    return a.probFromStart < b.probFromStart;  // 降序
}
class Solution {
private:
vector<double> dijkstra(int start, vector<vector<pair<int, double>>>& graph) {
    // 目标距离数组
    vector<double> probTo(graph.size(), 0.0);
    // 初始结点
    probTo[start] = 1;  // 起始概率为1
    // 关键数据结构，降序优先队列
    priority_queue<State> pq;
    // 从起点 start 开始进行 BFS
    pq.push(State(start, 1.0));
    // 开始遍历
    while(!pq.empty()) {
        // 当前结点
        State curNode = pq.top();
        pq.pop();
        int curNodeID = curNode.id;
        double curProbFromStart = curNode.probFromStart;
        // 提前进入下次循环
        if(curProbFromStart < probTo[curNodeID]) continue;  // 
        // 子结点
        for(pair<int, double>& neighborNode : graph[curNodeID]) {
            int nextNodeID = neighborNode.first;
            double probToNextNode = probTo[curNodeID] * neighborNode.second;
            if(probToNextNode > probTo[nextNodeID]) {
                probTo[nextNodeID] = probToNextNode;
                pq.push(State(nextNodeID, probToNextNode));
            }
        }
    }
    return probTo;
}

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // 建图
        vector<vector<pair<int, double>>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double p = succProb[i];
            // 双向图
            graph[from].push_back(pair<int, double>{to, p});
            graph[to].push_back(pair<int, double>{from, p});
        }
        // Dijkstra
        vector<double> probTo = dijkstra(start, graph);
        // 返回结果 
        // if(probTo[end] == 0.0) return 0.0;
        return probTo[end];

    }
};
