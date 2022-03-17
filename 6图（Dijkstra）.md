# Dijkstra 算法

## 图的抽象

**「图」**这种数据结构的基本实现：图中的节点一般就抽象成一个数字（索引），图的具体实现一般是「邻接矩阵」或者「邻接表」。

<img src = "images\g0.jpg" height=200>

比如上图这幅图用邻接表和邻接矩阵的存储方式如下：

<img src = "images\g1.jpeg" height=200>

我们用**邻接表**表示图的场景更多，结合上图，一幅图可以用如下 Java 代码表示：

```java
// graph[s] 存储节点 s 指向的节点（出度）
List<Integer>[] graph;
```

**如果你想把一个问题抽象成「图」的问题，那么首先要实现一个 API `adj`**：

```Java
// 输入节点 s 返回 s 的相邻节点
List<Integer> adj(int s);
```

类似多叉树节点中的 `children` 字段记录当前节点的所有子节点，`adj(s)` 就是计算一个节点 `s` 的相邻节点。

比如上面说的用邻接表表示「图」的方式，`adj` 函数就可以这样表示：

```Java
List<Integer>[] graph;
// 输入节点 s，返回 s 的相邻节点
List<Integer> adj(int s) {
    return graph[s];
}
```

当然，对于「加权图」，我们需要知道两个节点之间的边权重是多少，所以还可以抽象出一个 `weight` 方法：

```Java
// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to);
```

这个 `weight` 方法可以根据实际情况而定，因为不同的算法题，题目给的「权重」含义可能不一样，我们存储权重的方式也不一样。

有了上述基础知识，就可以搞定 Dijkstra 算法了，下面我给你从二叉树的层序遍历开始推演出 Dijkstra 算法的实现。

## 二叉树层级遍历和 BFS 算法

二叉树的层级遍历框架：

```java
// 输入一棵二叉树的根节点，层序遍历这棵二叉树
void levelTraverse(TreeNode root) {
    if (root == null) return 0;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    int depth = 1;
    // 从上到下遍历二叉树的每一层
    while (!q.isEmpty()) {
        int sz = q.size();
        // 从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            printf("节点 %s 在第 %s 层", cur, depth);
            // 将下一层节点放入队列
            if (cur.left != null) {
                q.offer(cur.left);
            }
            if (cur.right != null) {
                q.offer(cur.right);
            }
        }
        depth++;
    }
}
```

我们先来思考一个问题，注意二叉树的层级遍历 `while` 循环里面还套了个 `for` 循环，为什么要这样？

`while` 循环和 `for` 循环的配合正是这个遍历框架设计的巧妙之处：

<img src="images\Djikstra.jpeg" height=300>

**`while` 循环控制一层一层往下走，`for` 循环利用 `sz` 变量控制从左到右遍历每一层二叉树节点**。

注意我们代码框架中的 `depth` 变量，其实就记录了当前遍历到的层数。换句话说，每当我们遍历到一个节点 `cur`，都知道这个节点属于第几层。

算法题经常会问二叉树的最大深度呀，最小深度呀，层序遍历结果呀，等等问题，所以记录下来这个深度 `depth` 是有必要的。

基于二叉树的遍历框架，我们又可以扩展出多叉树的层序遍历框架：

```java
// 输入一棵多叉树的根节点，层序遍历这棵多叉树
void levelTraverse(TreeNode root) {
    if (root == null) return;
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);
    
    int depth = 1;
    // 从上到下遍历多叉树的每一层
    while (!q.isEmpty()) {
        int sz = q.size();
        // 从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode cur = q.poll();
            printf("节点 %s 在第 %s 层", cur, depth);
            // 将下一层节点放入队列
            for (TreeNode child : cur.children) {
                q.offer(child);
            }
        }
        depth++;
    }
}
```

基于多叉树的遍历框架，我们又可以扩展出 BFS（广度优先搜索）的算法框架：

```java
// 输入起点，进行 BFS 搜索
int BFS(Node start) {
    Queue<Node> q; // 核心数据结构
    Set<Node> visited; // 避免走回头路
    q.offer(start); // 将起点加入队列
    visited.add(start);
    int step = 0; // 记录搜索的步数
    while (q not empty) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散一步 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.poll();
            printf("从 %s 到 %s 的最短距离是 %s", start, cur, step);
            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj()) {
                if (x not in visited) {
                    q.offer(x);
                    visited.add(x);
                }
            }
        }
        step++;
    }
}
```

如果对 BFS 算法不熟悉，可以看前文 BFS 算法框架，这里只是为了让你做个对比，所谓 BFS 算法，就是把算法问题抽象成一幅「无权图」，然后继续玩二叉树层级遍历那一套罢了。

**注意，我们的 BFS 算法框架也是 `while` 循环嵌套 `for` 循环的形式，也用了一个 `step` 变量记录 `for` 循环执行的次数，无非就是多用了一个 `visited` 集合记录走过的节点，防止走回头路罢了**。

为什么这样呢？

所谓「无权图」，与其说每条「边」没有权重，不如说每条「边」的权重都是 1，从起点 `start` 到任意一个节点之间的路径权重就是它们之间「边」的条数，那可不就是 `step` 变量记录的值么？

再加上 BFS 算法利用 `for` 循环一层一层向外扩散的逻辑和 `visited` 集合防止走回头路的逻辑，当你每次从队列中拿出节点 `cur` 的时候，从 `start` 到 `cur` 的最短权重就是 `step` 记录的步数。

但是，到了「加权图」的场景，事情就没有这么简单了，因为你不能默认每条边的「权重」都是 1 了，这个权重可以是任意正数（Dijkstra 算法要求不能存在负权重边），比如下图的例子：

<img src="images\Djikstra1.jpeg" height=300>

如果沿用 BFS 算法中的 `step` 变量记录「步数」，显然红色路径一步就可以走到终点，但是这一步的权重很大；正确的最小权重路径应该是绿色的路径，虽然需要走很多步，但是路径权重依然很小。

其实 Dijkstra 和 BFS 算法差不多，不过在讲解 Dijkstra 算法框架之前，我们首先需要对之前的框架进行如下改造：

