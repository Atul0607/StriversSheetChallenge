class MinStack {
public:
    stack<int> s;
    priority_queue<int,vector<int>,greater<int>> pq;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        pq.push(val);
    }
    
    void pop() {
        priority_queue<int,vector<int>,greater<int>> pq_new;
        int delete_me = s.top();
        s.pop();
        int check = 0;
        while (!pq.empty()) {
            if(pq.top() == delete_me && check == 0){
                pq.pop();
                check = 1;
            }else{
                pq_new.push(pq.top());
                pq.pop();
            }
        }
        pq = pq_new;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return pq.top();
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