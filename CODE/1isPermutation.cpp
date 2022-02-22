/* 
判断两个字符串是否属于同一个排列组合
如：abcd、abdc和acdb
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


bool isPermutation(string strA, string strB){
    if(strA.length() != strB.length())
        return false;
    unordered_map<char, int> hashMapA;
    unordered_map<char, int> hashMapB;
    for(int i = 0; i < strA.length(); i++){
        hashMapA[strA[i]]++;
        hashMapB[strB[i]]++;
    }
    if(hashMapA.size() != hashMapB.size())
        return false;
    unordered_map<char, int>::iterator it;
    for(it = hashMapA.begin(); it != hashMapA.end(); it++){
        if(it->second != hashMapB[it->first])
            return false;
    }
    return true;
}

int main(int argc, char *argv[]){
    string s1 = "abc";
    string s2 = "bcb";
    if(isPermutation(s1, s2))
        printf("s1 & s2 is permutation!");
    else
        printf("s1 & s2 is not permutation!");
    return 0;
}


