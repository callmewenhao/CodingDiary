/* 将字符串映射为hash值 */
#include <iostream>
#include <string>
#include <functional>
using namespace std;


int RabinKrap(string s, string pattern){
    int sLen = s.length(), pLen = pattern.length();
    hash<string> myHash;  // 建立hash map
    unsigned int hpattern = myHash(pattern), hs = myHash(s);  // 对string进行map
    for(int i = 0; i < sLen - pLen; i++){
        if(hpattern == hs){  // 如果map的值一样，在精确判断
            if(pattern == s.substr(i, pLen))  // 使用substr寻找字串
                return i;
        }
        hs = myHash(s.substr(i+1, pLen));  // 移位继续判断
    }
    return -1;
}


int main(int argc, char *argv[]){
    string raw = "1234";
    string match = "23";
    int pos = RabinKrap(raw, match);
    printf("%d\n", pos);
    return 0;
}




