struct State { 
public:
    int id;
    int distFromStart;
    State(int id, int distFromStart) {
        this->id = id;  // 我感觉最好不要重名
        this->distFromStart = distFromStart;
    }
};

bool operator<(State a, State b) {
    return a.distFromStart > b.distFromStart;  // 升序
}

class Solution {
private:
    vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {
        // 目标距离数组
        vector<int> distTo = vector<int>(graph.size(), INT_MAX);
        // 初始结点
        distTo[start] = 0;
        // 关键数据结构，升序优先队列
        priority_queue<State> pq;
        // 从起点 start 开始进行 BFS
        pq.push(State(start, 0));
        // 开始遍历
        while(!pq.empty()) {
            // 当前结点
            State curNode = pq.top();
            pq.pop();
            int curNodeID = curNode.id;
            int curDistFromStart = curNode.distFromStart;
            // 提前进入下次循环
            if(curDistFromStart > distTo[curNodeID]) continue;  // 
            // 子结点
            for(pair<int, int>& neighborNode : graph[curNodeID]) {
                int nextNodeID = neighborNode.first;
                int distToNextNode = distTo[curNodeID] + neighborNode.second;
                if(distToNextNode < distTo[nextNodeID]) {
                    distTo[nextNodeID] = distToNextNode;
                    pq.push(State(nextNodeID, distToNextNode));
                }
            }
        }
        return distTo;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 建图
        vector<vector<pair<int, int>>> graph(n + 1);
        for(vector<int>& edge : times) {
            int from = edge[0];
            int to = edge[1];
            int time = edge[2];
            // 
            graph[from].push_back(pair<int, int>{to, time});

        }
        // 使用Djikstra
        vector<int> distTo = dijkstra(k, graph);
        // 找到最长的那一条最短路径
        int res = 0;
        for (int i = 1; i < distTo.size(); i++) {
            if (distTo[i] == INT_MAX) {
                // 有节点不可达，返回 -1
                return -1;
            }
            res = max(res, distTo[i]);
        }
        return res;
    }
};


