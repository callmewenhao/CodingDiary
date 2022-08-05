# KMP

**核心思想：**当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。

next 数组是一个前缀表（prefix table），**记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。**

**前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串**。

**后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串**。

next 数组中存放的就是：**最长公共前后缀的长度**，也即，**前缀表**

## KMP 字符串比较步骤

- 文本串当前位置 i 的字符 == 模式串当前位置 j 的字符

    i++，j++

- 文本串当前位置 i 的字符 != 模式串当前位置 j 的字符

    j  = next[j-1] 直到 == 成立，i++

- 匹配成功的条件：j == 模式串的长度

## 如何构造 next 数组（前缀表）

> 构造 next 数组的过程是模式串 s 自我匹配的过程，也是一个递推的过程！

- 对于任何一个字符串s，他对应 next 数组的第一个值（`next[0] = 0`）必为0（由第一个元素组成的子串，没有前缀和后缀，故为0）

- 使用两个指针 i（初始化为1），j（初始化为0） 分别代表：next[i] 的后缀尾指针，next[i-1] 的前缀尾指针

    构造 next 数组的过程是计算后缀尾指针 i 处的 next[i] 的值

- 计算 next[i] 的值：借助递推的思想

    已经知道了 next[i-1] 的值，对应尾指针 j

    - 如果 s[j] == s[i]，则 next[i] = next[i-1]  + 1 = j + 1;

    - 如果 s[j] != s[i]，则要找寻 next[j] 对应的字串，并上述两步，知道 s[j] == s[i] 或者 j == 0 

**代码如下：**

```c++
void getNext(int* next, const string& s) {
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        while(j > 0 && s[i] != s[j]) {
            j = next[j -1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}
```

## KMP 模板代码

```C++
int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++) {
        while(j > 0 && haystack[i] != needle[j]) { // 不相等
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) { // 相等
            j++;
        }
        if (j == needle.size() ) { // 匹配完成！
            return (i - needle.size() + 1);
        }
    }
    return -1;
}
```

