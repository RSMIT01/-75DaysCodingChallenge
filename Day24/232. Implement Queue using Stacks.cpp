class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
      stack<int>temp;
     
      int ele=-1;
      while(!st.empty())
      {
          ele=st.top();
          temp.push(ele);
          st.pop();
      }
        temp.pop();
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return ele;
    }
    
    int peek() {
        stack<int>temp;
       
      int ele=-1;
      while(!st.empty())
      {
          ele=st.top();
          temp.push(ele);
          st.pop();
      }
       
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return ele;
    }
    
    bool empty() {
        return st.size()==0;
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