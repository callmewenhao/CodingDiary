# Some Tricks

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

#### 去重容器 unordered_map

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

