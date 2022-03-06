/* 使用两个stack，相互倾倒，均摊复杂度 */
/* https://leetcode-cn.com/problems/implement-queue-using-stacks/ */
class MyQueue {
private:
    int front;
    stack<int> s1;  // 存放元素
    stack<int> s2;  // 出队列使用
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            front = x;
        }
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int r = s2.top();
        s2.pop();
        return r;
    }
    
    int peek() {
        if(!s2.empty()){
            return s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty()  && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */














