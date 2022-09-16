class MaxStack {
    stack<int> s;
public:
    MaxStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        s.push(number);
    }

    /*
     * @return: An integer
     */
    int pop() {
        int sol = s.top();
        s.pop();
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
        vector<int> temp;
        int sol = INT_MIN;
        while(s.size()){
            temp.push_back(s.top());
            sol = max(sol, s.top());
            s.pop();
        }

        for(int i = temp.size() - 1; i != -1; i--){
            s.push(temp[i]);
        }
        return sol;
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        vector<int> temp;
        int sol = INT_MIN;
        while(s.size()){
            temp.push_back(s.top());
            sol = max(sol, s.top());
            s.pop();
        }

        for(int i = temp.size() - 1; i != -1; i--){
            s.push(temp[i]);
        }

        temp.clear();
        while(s.top() != sol){
            temp.push_back(s.top());
            s.pop();
        }
        s.pop();
        for(int i = temp.size() - 1; i != -1; i--){
            s.push(temp[i]);
        }
        return sol;
    }
};
