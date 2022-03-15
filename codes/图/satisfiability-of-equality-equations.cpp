// https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
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
    bool equationsPossible(vector<string>& equations) {
        UF myUF(26);
        // 先将"=="的字母之间连通
        for(string s : equations) {
            if(s[1] == '=') {
                int p = s[0] - 'a';
                int q = s[3] - 'a';
                myUF.unionRoot(p, q);
            }
        }
        // 遍历"!="的关系，如果打破"=="，则返回false
        for(string s : equations) {
            if(s[1] == '!') {
                int p = s[0] - 'a';
                int q = s[3] - 'a';
                if(myUF.isConnected(p, q)) {
                    return false;
                }
            }
        }
        return true;
    }
};




