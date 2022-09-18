class MaxStack {
    stack<int> s;
    int m;

    void getNewMax(){
        m = INT_MIN;
        vector<int> temp;
        while(s.size()){
            m = max(m, s.top());
            temp.push_back(s.top());
            s.pop();
        }

        for(int i = temp.size() - 1; i != -1; i--){
            s.push(temp[i]);
        }
    }
public:
    MaxStack() {
        m = INT_MIN;
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
        m = max(m, number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int sol = s.top();
        s.pop();
        if(sol == m){
            getNewMax();
        }
        return sol;
    }

    /*
     * @return: An integer
     */
    int top() {
        return s.top();
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        return m;
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        int sol = m;

        vector<int> temp;
        while(s.size()){
            if(s.top() == sol){
                s.pop();
                break;
            }
            temp.push_back(s.top());
            s.pop();
        }

        for(int i = temp.size() - 1; i != -1; i--){
            s.push(temp[i]);
        }
        getNewMax();
        return sol;
    }
};
