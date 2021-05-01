class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int current = 0;
        int* p1 = &height[0];
        int p1_counter = 0;
        int* p2 = &height[height.size() - 1];
        int p2_counter = height.size() - 1;
        
        while(p1 < p2){
            int length = min(*p1, *p2);
            int width = p2_counter - p1_counter;
            current = length * width;
            if(current > max)
                max = current;
            
            if(*p1 <= *p2){
                p1++;
                p1_counter++;
            }
            else{
                p2--;
                p2_counter--;
            }
            
        }
        return max;
    }
};
