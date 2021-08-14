class Solution {
public:
    void reverseString(vector<char>& s) {
        char* first = &s[0];
        char* last = &s[s.size() - 1];
       
        while(first <= last){
            char temp = *first;
            *first = *last;
            *last = temp;
            first++;
            last--;
        }
    }
};
