/* 
全排列——递归思路 
*/
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;


void Permutation(char* pStr, char* pBegin){
    assert(pStr && pBegin);  // 判断指针是否为空
    if(*pBegin == '\0'){
        printf("%s\n", pStr);
    } else {
        for (char* pCh = pBegin; *pCh != '\0'; pCh++)
        {
            swap(*pBegin, *pCh);
            Permutation(pStr, pBegin+1);
            swap(*pBegin, *pCh);
        } 
    }
}


int main(int argc,char* argv[]){
    char myStr[] = "123";  // C风格的字符串
    Permutation(myStr, myStr);
    return 0;
}


/* 
code output: 
123
132
213
231
321
312
*/
