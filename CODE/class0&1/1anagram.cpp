/* 
Anagram(变位词)
Write a method anagram(s,t) to decide if two strings are anagrams ornot.
Example
Given s="abcd", t="dcab", return true.
Challenge
o(n) time, O(1) extra space 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* hash map O(m+n)*/
bool anagramHashMap(string s, string t){
    if(s.empty() || t.empty())
        return false;
    if(s.size() != t.size())
        return false;
    int letterCount[256] = {0};
    for(int i = 0; i != s.size(); i++){
        ++letterCount[s[i]];
        --letterCount[t[i]];
    }
    for(int i = 0; i != t.size(); i++){
        if(letterCount[t[i]] < 0)
            return false;
    }
    return true;
}

/* sort */
bool anagramSort(string s, string t){
    if(s.empty() || t.empty())
        return false;
    if(s.size() != t.size())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t)
        return true;
    else
        return false;
}


int main(int argc, char *argv[]){
    string raw = "12345";
    string mes = "15342";
    if(anagramSort(raw, mes))
        printf("anagram!");
    else
        printf("Not anagram!");
    return 0;
}




