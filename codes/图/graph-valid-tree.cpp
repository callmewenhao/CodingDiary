// https://leetcode-cn.com/problems/graph-valid-tree/
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
    bool validTree(int n, vector<vector<int>>& edges) {
        // 特殊情况
        if(n == 1) return true;
        else if(n > 1 && edges.size() == 0) return false;
        // 使用UF判断
        UF myUF(n);
        for(vector<int> side : edges) {
            int p = side[0];
            int q = side[1];
            if(myUF.isConnected(p, q)) return false;  // 如果要连通已经连通的结点，返回false
            else myUF.unionRoot(p, q);  // 连通未连通的结点
        }
        return myUF.count() == 1;  // 最后连通分量的个数应该是1
    }
};
