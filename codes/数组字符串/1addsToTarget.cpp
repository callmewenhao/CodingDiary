/* 
Find a pair of two elements in an array, 
whose sum is a given targetnumber.
暴力搜索的时间复杂度是O(n^2)
借助hashTable
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* hashMap O(n)*/
vector<int> addsToTarget(vector<int> &numbers, int target){
    vector<int> pairs(2);
    unordered_map<int, int> hashMap;
    vector<int>::iterator it;
    for(it = numbers.begin(); it != numbers.end(); it++){
        if(hashMap.count(target - *it) != 0){  // 找到了
            pairs[0] = hashMap[target - *it]+1;
            pairs[1] = (int)(it - numbers.begin())+1;
            return pairs;
        }
        // 没找到
        hashMap[*it] = (int)(it - numbers.begin());
    }
    return pairs;
}

int main(int argc, char *argv[]){
    vector<int> raw = {1, 2, 9, 4, 5, 6, 7, 8, 3, 10};
    int target = 9;
    vector<int> res = addsToTarget(raw, target);
    for(auto i : res){
        printf("%d\n", raw[i-1]);
    }
    return 0;
}




