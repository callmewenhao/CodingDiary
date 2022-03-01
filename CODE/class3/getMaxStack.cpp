/* 
https://leetcode-cn.com/problems/max-stack/
Using two stacks. 
The first one is the regular stack. 
The second one only store maximum numbers if a larger number comes.

复杂度分析:时间复杂度符合题目要求为O(1)。
空间复杂度最坏情况附加的stack中需要储存每个元素,故额外使用O(n)空间。 
*/
class MaxStack {
private:
    stack<int> realStack;
    stack<int> maxStack;

public:
    MaxStack() {

    }
    
    void push(int x) {
        realStack.push(x);
        if(maxStack.empty()){  // 判断栈是否为空
            maxStack.push(x);
        } else {
            int m = x > maxStack.top() ? x : maxStack.top();
            maxStack.push(m);
        } 
    }
    
    int pop() {
        int r = realStack.top();
        realStack.pop();
        maxStack.pop();
        return r;
    }
    
    int top() {
        return realStack.top();
    }
    
    int peekMax() {
        return maxStack.top();
    }
    
    int popMax() {
        stack<int> tempStack;
        int m = maxStack.top();
        while(realStack.top() != m){
            tempStack.push(realStack.top());
            this->pop();  // 使用this指针
        }
        this->pop();
        while(!tempStack.empty()){
            this->push(tempStack.top());
            tempStack.pop();
        }
        return m;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */



