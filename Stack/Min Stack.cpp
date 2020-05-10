class MinStack {
public:
    /** initialize your data structure here. */
    pair<int, int> key;
    stack<pair<int, int> > st;
    
    MinStack() {

    }
    
    void push(int x) {
        if (st.empty()) {
            st.push(make_pair(x, x));
            return;
        }
        
        if (st.top().first > x)
            st.push(make_pair(x, x));
        else 
            st.push(make_pair(st.top().first, x));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().second;
    }
    
    int getMin() {
        return st.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */