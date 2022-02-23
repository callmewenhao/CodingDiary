#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canCompose(string newspaper, string message){
    unordered_map<char, int> hashMap;
    int i;
    if(newspaper.length() < message.length())  // 特殊情况处理
        return false;
    for(i = 0; i < newspaper.length(); i++){  // 建立 hashMap
        hashMap[newspaper[i]]++;
    }
    for(i = 0; i < message.length(); i++){
        if(hashMap.count(message[i]) == 0){  // 如果 hashMap 中没有字符
            return false;
        }
        if(--hashMap[message[i]] < 0){  // 如果字符意境用完了
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    string raw = "123456789";
    string mes = "19";
    if(canCompose(raw, mes))
        printf("Can Compose!");
    else
        printf("Can't Compose!");
    return 0;
}