/* 
判断string元素是否唯一 
*/
#include <iostream>
#include <string>
#include <bitset>
using namespace std;


bool isUnique(string input){
    bitset<256> hashMap;  // ASC2码表一共有256个字符
    for(int i = 0; i < input.length(); i++){
        if(hashMap[(int)input[i]])
            return false;
        hashMap[(int)input[i]] = 1;
    }
    return true;
}


int main(int argc, char *argv[]){
    string u_real = "12345";
    string u_fake = "11345";
    if(isUnique(u_fake))
        printf("this string is unique!");
    else 
        printf("this string is not unique!");
    return 0;
}







