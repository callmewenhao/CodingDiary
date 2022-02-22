/* 
Get the length of the longest consecutive elements sequence in an arrayFor example, 
given [31,6,32,1,3,2],the longest consecutive elements sequence is [1,2,3]. 
Return its length: 3.
模式识别：
判断array[i]-1，array[i]+1是否存在于数组中。
如何保存之前的处理结果?
可以使用hash table。由于序列是一系列连续整数，所以只要序列的最小值以及最大值，就能唯一确定序列。
而所谓的“作为后继加入序列”，“作为前驱加入序列”，就是更新最大最小值。
hash table的value可以是一个记录最大/最小值的structure，用以描述当前节点参与构成的最长序列。
时间复杂度O(n)
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Bound {
    int high;
    int low;
    Bound(int h = 0, int l = 0): high(h), low(l) {}  // 默认构造函数
};


int longestConsecutive(vector<int> &num){
    unordered_map<int, Bound> table;

    int local;
    int maxLen = 0;

    for(int i = 0; i < num.size(); i++){
        if(table.count(num[i]))  // 重复处理
            continue;
        local = num[i];
        int high = local, low = local;
        /* 寻找边界 */
        if(table.count(local - 1)){
            low = table[local - 1].low;
        }
        if(table.count(local + 1)){
            high = table[local + 1].high;
        }
        /* 更新边界 */
        table[local].high = table[low].high = high;
        table[local].low = table[high].low = low;
        /* 最大长度实时更新 */
        if(high - low + 1 > maxLen){
            maxLen = high - low + 1;
        }
    }
    return maxLen;
}

int main(int argc, char *argv[]){
    vector<int> raw = {31, 4, 32, 1, 3, 2};
    int maxLen = longestConsecutive(raw);
    printf("%d\n", maxLen);
    return 0;
}











