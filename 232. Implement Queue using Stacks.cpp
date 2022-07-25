class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    int first = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
        if(first==-1)
            first = x;
    }
    
    int pop() {
        if(st1.size()==0){
            first = -1;
            return -1;
        }
        while(st1.size()>1){
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st1.top();
        st1.pop();
        
        if(st2.size()==0)
            first = -1;
        else
            first = st2.top();
        
        while(st2.size()>0){
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }
    
    int peek() {
        return first;
    }
    
    bool empty() {
        return st1.empty();
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
