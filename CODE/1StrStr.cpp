/* 
字符串匹配
返回开始的位置
时间复杂度:n*m
*/
#include <iostream>
using namespace std;

/* 暴力法 */
char* StrStr(const char *str, const char *target){
    if(!*target)  // 异常处理
        return (char*)str;
    // 开始匹配
    char *p1 = (char*)str;
    while(*p1){
        char *pBegin = p1, *p2 = (char*)target;
        while(*p1 && *p2 && *p1 == *p2){
            p1++;
            p2++;
        }
        // 完成匹配
        if(!*p2)
            return pBegin;
        // 未完成
        p1 = pBegin + 1;
    }
    return NULL;
}


int main(int argc, char* argv[]){
    char str[] = "12345";
    char target[] = "34";
    char *res = StrStr(str, target);
    printf("%d\n", res-str);
    return 0;
}








