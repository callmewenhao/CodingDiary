// https://leetcode-cn.com/problems/surrounded-regions/
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
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        // 给 dummy 留一个额外位置
        UF myUF(n * m + 1);
        int dummy = n * m;
        // 首列与末列的 O 与 dummy 连通
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O')
                myUF.unionRoot(i * n + 0, dummy);
            if(board[i][n - 1] == 'O')
                myUF.unionRoot(i * n + n - 1, dummy);
        }
        // 首行与末行的 O 与 dummy 连通
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                myUF.unionRoot(j, dummy);
            if(board[m - 1][j] == 'O')
                myUF.unionRoot((m - 1) * n + j, dummy);
        }
        // 方向数组 offset 是上下左右搜索的常用手法
        int offset[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // 注意去掉了四周
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(board[i][j] == 'O') {
                    // 将此 O 与上下左右的 O 连通
                    for(int k = 0; k < 4; k++) {
                        int x = i + offset[k][0];
                        int y = j + offset[k][1];
                        if(board[x][y] == 'O') 
                            myUF.unionRoot(i * n + j, x * n + y);
                    }
                }
            }
        }
        // 所有不和 dummy 连通的 O，都要被替换
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(!myUF.isConnected(dummy, i * n + j)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};




