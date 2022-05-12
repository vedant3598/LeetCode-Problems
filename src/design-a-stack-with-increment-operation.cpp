class CustomStack {
private:
    vector<int> s;
    in tmaxSize;

public:
    CustomStack(int maxSize) {
        maxSize = maxSize;
    }
    
    void push(int x) {
        if(s.size() < m){
            s.push_back(x);
        }
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
        int i = 0; 
        while(i < k && i < maxSize){
            s[i] += val;
            i++;
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
