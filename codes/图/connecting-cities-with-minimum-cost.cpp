// https://leetcode-cn.com/problems/connecting-cities-with-minimum-cost/
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
private:
    static bool myComp(vector<int> a, vector<int> b) {return a[2] < b[2];}
public:
    // 这题比较坑的一点是：它们按以1到n的次序编号
    int minimumCost(int n, vector<vector<int>>& connections) {
        // 特殊情况处理
        if(n == 1) return 0;
        else if(n > 1 && connections.size() == 0) return -1;
        // 一般情况
        int mst = 0;
        UF myUF(n + 1);
        sort(connections.begin(), connections.end(), myComp);  // 按举距离排序
        // 使用贪心思想，遍历排序后的组数
        for(vector<int>& side : connections) {
            int p = side[0];
            int q = side[1];
            if(!myUF.isConnected(p, q)) {
                myUF.unionRoot(p, q);
                mst += side[2];
            }
        }
        return myUF.count() == 2 ? mst : -1;  // 注意这里是和2比较
    }
};

