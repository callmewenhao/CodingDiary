/*
https://leetcode-cn.com/problems/valid-parentheses/
Validate Parenthesis 有效括号
Given a string containing just the characters '(', )'.'T, ?'.'[ and '7,
determine if the input string is a valid parentheses string. For example,“((7))" is valid, but “(" or"“((”is not.
*/
class Solution {
private:
    stack<char> myStack;
    bool validParentheses(char c1, char c2) {
        if(c1 == '(' && c2 == ')') return true;
        else if(c1 == '[' && c2 == ']') return true;
        else if(c1 == '{' && c2 == '}') return true;
        else return false;
    }
public:
    bool isValid(string s) {
        for(char c : s) {
            if(myStack.empty()) {
                myStack.push(c);
            } else {
                if(validParentheses(myStack.top(), c)) {
                    myStack.pop();
                } else {
                    myStack.push(c);
                }
            }
        }
        if(myStack.empty()) return true;
        else return false;
    }
};







