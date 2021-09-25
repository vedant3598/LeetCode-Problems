class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        q1 = {};
        q2 = {};
    }
    
    void push(int x) {
        q1.push(x);  
        q2.push(x);
    }
    
    int pop() {
        int ret = 0;
        while(!q2.empty()){
            ret = q2.front();
            q2.pop();
        }
        int i = 0;
        int max = q1.size() - 1;
        while(i < max){
            q2.push(q1.front());
            q1.pop();
            i++;
        }
        q1 = q2;
        return ret;
    }
    
    int top() {
        int ret = 0;
        while(!q2.empty()){
            ret = q2.front();
            q2.pop();
        }
        q2 = q1;
        return ret;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
