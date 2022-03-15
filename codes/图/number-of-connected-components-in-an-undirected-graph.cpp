// https://leetcode-cn.com/problems/number-of-connected-components-in-an-undirected-graph/
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
    // 借助UF类来解决
    int countComponents(int n, vector<vector<int>>& edges) {
        UF myUF(n);
        for(vector<int>& side : edges) {
            int p = side[0];
            int q = side[1];
            myUF.unionRoot(p, q);
        }
        return myUF.count();
    }
};





