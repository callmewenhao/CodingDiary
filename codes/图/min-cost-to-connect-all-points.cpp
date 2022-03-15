// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
// 并查集模板代码
class UF {
private:
    // 连通分量个数
    int nums = 0;
    // 存放根结点的数组
    vector<int> parent;
    // 找根结点函数
    int find(int x) {
        while(parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    // 构造函数
    UF(int n) {
        nums = n;
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    // 返回连通分量个数
    int count() {
        return nums;
    }
    // 返回是否连通
    bool isConnected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }
    // 两个连通分量合并成一个连通分量
    void unionRoot(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) return;
        parent[rootP] = rootQ;
        nums--;
    }
};

class Solution {
public:
    // 学习这种建立路径数组的方法 
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> sides;
        int numsPoints = points.size();
        int mst = 0;
        UF myUF(numsPoints);
        // 建立路径
        for(int i = 0; i < numsPoints - 1; i++) {
            for(int j = i + 1; j <numsPoints; j++) {
                int ix = points[i][0], iy = points[i][1];
                int jx = points[j][0], jy = points[j][1];
                int d = (int)(abs(ix - jx) + abs(iy - jy));
                sides.push_back(vector<int> {i, j, d});
            }
        }
        // 为贪心排序
        sort(sides.begin(), sides.end(), [](auto& a, auto& b) -> bool{return a[2] < b[2];});
        // 遍历
        for(auto& side : sides) {
            int p = side[0];
            int q = side[1];
            if(!myUF.isConnected(p, q)) {
                myUF.unionRoot(p, q);
                mst += side[2];
            }
        }
        return mst;
    }
};





