class CustomStack {
private:
    vector<int> s;
    int m;

public:
    CustomStack(int maxSize) {
        m = maxSize;
    }
    
    void push(int x) {
        if(s.size() < m)
            s.push_back(x);
    }
    
    int pop() {
        int num = -1;
        if(s.size() > 0){
            num = s.back();
            s.pop_back();
        }
        return num;
    }
    
    void increment(int k, int val) {
        int x = s.size();
        for(int i = 0; i < min(k, x); i++){
            s[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
