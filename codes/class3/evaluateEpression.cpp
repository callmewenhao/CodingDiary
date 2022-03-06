/*  
https://leetcode-cn.com/problems/8Zf90G/
使用栈完成计算！
*/
class Solution {
private:
    int p; 
    stack<int> nums;
    bool isOperation(string s){
        if(s == "+" || s == "-" || s == "*" || s == "/")
            return true;
        else return false;
    }
    int operateNums(char s) {
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        int c = 0;
        switch(s){
            case '+': return c = b + a; break;
            case '-': return c = b - a; break;
            case '*': return c = b * a; break;
            case '/': return c = b / a; break;
            default: break;
        }
        return c;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        for(string s : tokens) {
            if(!isOperation(s)) { 
                int v = atoi(s.c_str());
                nums.push(v);
            } else {
                int r = operateNums(s[0]);
                nums.push(r);
            }
        }
        return nums.top();
    }
};