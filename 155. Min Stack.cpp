class MinStack {
public:
    deque<int>q1;
    deque<int>q2;
    
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(val<=q1.front())
            q1.push_front(val);
        else
            q1.push_back(val);
        q2.push_back(val);
    }
    
    void pop() {
        int t = q2.back();
        q2.pop_back();
        if(t==q1.front())
            q1.pop_front();
        else
            q1.pop_back();
    }
    
    int top() {
        return q2.back();
    }
    
    int getMin() {
        int t = q1.front();
        return t;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
