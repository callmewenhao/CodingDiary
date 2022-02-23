/* 
Rotate String
Given a string and an offset, rotate string by offset. (rotate from left toright)
Example
Given "abcdefg"
for offset=0, return "abcdefg"
for offset=1, return "gabcdef"
for offset=2, return "fgabcde"

思路：先以offset为分界线，左边逆序和右边逆序，之后整体逆序！
*/
#include <iostream>
#include <string>
using namespace std;

void reverse(string &str, int start, int end){
    while(start < end){
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

string rotateString(string A, int offset){
    if(A.empty())
        return A;
    
    int len = A.size();
    offset %= len;
    reverse(A, 0, len - offset - 1);
    reverse(A, len - offset, len - 1);
    reverse(A, 0, len - 1);
    return A;
}

int main(int argc, char *argv[]){
    string raw = "abcdefg";
    string r = rotateString(raw, 3);
    cout<<r<<endl;
    return 0;
}






