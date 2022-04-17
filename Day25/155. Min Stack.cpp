class MinStack {
public:
    stack<int>st;
    stack<int>min_store;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_store.empty() || val<=min_store.top())
        {
            min_store.push(val);
        }
        st.push(val);
    }
    
    void pop() {
         if(st.top()==min_store.top())
         {
            min_store.pop();
         }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_store.top();
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