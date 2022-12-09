# Some Tricks

#### Debug

```C++
#include <initializer_list>
template<class T>
void Debug(initializer_list<T> infos) {
    std::cout << "\nnew debug line:\n";
    for (auto& it: infos) {
        std::cout << it << " ";
    }
    std::cout << "\nend\n";
}
```

#### C++ lambda 中进行递归

C++ 无法像 python 一样在函数中定义普通函数，但可以使用 lambda 实现。有一个场景是在这个内部匿名函数中进行递归，但一般定义的 lambda 函数无法递归（即使你的捕获列表是`[&]`），如下：

```C++
auto dfs = [&](){ // intuition!
	dfs(); // error: use of 'dfs' before deduction of 'auto'
};
```

这是因为 `匿名`函数的匿名特性🤣，这个函数是没有名字的，无法捕获

两种解决方案：

1. `std::function`，这个写法比较 ugly，代码冗余！还有其他缺点😂以后再说

```C++
#include <functional>
int main() {
    std::function<void()> dfs = [&](){
        dfs(); //OK
    };
    
    std::function<int(int)> fibonacci = [&](int n) -> int {
        if (n == 1 || n == 2) return 1;
        return fibonacci(n - 1) + fibonacci(n  -2);
    };

    std::cout << fibonacci(10) << std::endl;
}
```

2. Fixed-point combinator，力扣上给了一个解决方案：https://leetcode.cn/circle/discuss/nkNj76/，不太好懂🤣

#### 遍历一棵树（双向、无环、连通）

```C++
// 用一个返回树枝节点个数的代码举例
LL dfs(int node, int fa) { // node：要遍历的节点 fa：父节点
    int size = 1;
    for (auto sub_node: graph[node]) {
        if (sub_node != fa) { // 这样就省去了 visited 数组
            size += dfs(sub_city, city, seats);
        }
    }
    return size;
}
```

#### 反转数字

```c++
int reverseNum(int n) {
    int rev = 0;
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

// string版本
int reverseNum(int n) {
    std::string s = std::to_string(n);
    std::reverse(s.begin(), s.end());
    return std::stoi(s);
}
```

#### 去重容器 unordered_set

```c++
std::unordered_set<int> memo;
memo.insert(1);
memo.insert(1);
memo.insert(1);
std::cout << memo.size() << std::endl; // 输出：1
```

#### `lowbit`

`lowbit`：将一个数拆成最小个数的 `2^i` 和的形式，其中的最小的那个，比如：二进制数 0010,0100 中的 0000,0100，而且 `lowbit = n & -n;`

> 灵神：`CSAPP` 中有讲到

一个把数拆成最小个数的 `2^i` 和的形式的函数

```c++
std::vector<int> lowbitFn(int n) {
    std::vector<int> ans;
    while (n) {
        int lowbit = n & -n;
        ans.push_back(lowbit);
        n ^= lowbit;
    }
    return ans;
}
```

#### 最小化最大值 => 二分答案

最小化最大值又叫二分答案

#### 向上取整

```
res = (a + b - 1) / b // 使用默认的向下取整
```

#### 连续子区间=>滑动窗口

#### 经典循环遍历=>循环数组「拉直」

就是说，把前n-1（我用了n个）个元素拼到数组后面

但是，我们可以用%运算模拟这个过程，不必真的拼接

#### 下一个最大数字=>单调栈

#### 关于 0x3f

```c++
int a[10];
memset(a, 0x3f, sizeof a);

for (int i = 0; i < 10; ++i) {
    cout << a[i] << endl;
}
```

输出全部是：106110956， 是`10^9`级别的，满足算法题目中数据量的范围

#### GCD & LCM

C++ `<numeric>` 中有 `std::gcd()` 函数用于计算**最大公约数**，`std::lcm()` 计算**最小公倍数**；Python3 `math` 中也有 `gcd` 、`lcm` 函数

计算 GCD 一种常见方法是欧几里得算法，即辗转相除法， 代码如下：

> https://zhuanlan.zhihu.com/p/171623230
>
> 主要思想：gcd(a, b) = gcd(b, a mod b) (不妨设a>b 且r=a mod b ,r不为0)

```c++
// note: input parameters must be positive integer!
long long findGCD(long long a, long long b) {
    long long small_num = min(a, b);
    long long big_num = max(a, b);
    long long mod = big_num % small_num;
    if (mod == 0) return small_num;
    return findGCD(small_num, mod); 
    // there is a recursive method, 'while' loop is another way!
}
```

计算 LCM 可以使用两数乘积除以 GCD 进行计算，代码略

#### 序列有序的最少交换次数——任意交换元素位置

最少交换次数 = 元素个数 - 环的个数，下面代码出自：https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

```C++
ans += n;
std::vector<int> sort_plane{plane};
// record the final idx for num
std::unordered_map<int, int> map;
// 灵神没有使用 map 而是对 sort_plane 使用二分搜索找新坐标
sort(sort_plane.begin(), sort_plane.end());
for (int i = 0; i < sort_plane.size(); ++i) 
    map[sort_plane[i]] = i;
// build a visited arr
std::vector<bool> vis(n, false);
for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    int j = i;
    while (!vis[j]) {
        vis[j] = true;
        j = map[plane[j]];
    }
    ans -= 1;
}
```

#### 排列与组合

全排列：n 个元素的全排列为 $n!$ 的阶乘

排列公式如下：
$$
C_{n}^{m}=\frac{P_{n}^{m}}{P_{m}}=\frac{n !}{m !(n-m) !}, C_{n}^{0}=1
$$
或者：
$$
C_{n}^{m}=\frac{n(n-1)(n-2) \cdots(n-m+1)}{m!}
$$
组合总数计算代码，在《算法/组合数中》有使用 dp 计算组合数的代码
