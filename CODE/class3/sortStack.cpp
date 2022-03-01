/* 
https://leetcode-cn.com/problems/sort-of-stacks-lcci/
对栈进行排序
*/
class SortedStack {
private:
    stack<int> sortStack;
    stack<int> tempStack;

public:
    SortedStack() {
        /*  
        在入栈的时候维护一个顺序栈！
        */
    }
    
    void push(int val) {
        if(sortStack.empty()) sortStack.push(val);  // 如果栈为空，直接入栈！
        else {  // 排序栈不空，将其中大于val的元素放到临时栈中，之后push(val)，然后将临时栈的元素放回到排序栈！
            while(!sortStack.empty() && sortStack.top() < val) {
                tempStack.push(sortStack.top());
                sortStack.pop();
            }
            sortStack.push(val);
            while(!tempStack.empty()) {
                sortStack.push(tempStack.top());
                tempStack.pop();
            }
        }
    }
    
    void pop() {
        if(sortStack.empty()) return;
        else sortStack.pop();
    }
    
    int peek() {
        if (sortStack.empty()) return -1;
        return sortStack.top();
    }
    
    bool isEmpty() {
        return sortStack.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */