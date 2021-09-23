class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares;
        int smallest = INT_MAX;
        int index = 0;
        
        for(int i = 0; i < nums.size(); i++){
            int num = abs(nums[i]);
            if(num < smallest){
                smallest = num;
                index = i;
            }
        }
        if(index == 0){
            for(int i = 0; i < nums.size(); i++){
                squares.push_back(abs(pow(nums[i], 2)));
            }
        }
        else if(index == nums.size() - 1){
            for(int i = nums.size() - 1; i >= 0; i--){
                squares.push_back(abs(pow(nums[i], 2)));
            }
        }
        else{
            int* p1 = &nums[index-1];
            int* p2 = &nums[index+1]; 
            int* left = &nums[0];
            int* right = &nums[nums.size() - 1];
            squares.push_back(abs(pow(smallest, 2)));

            while(p1 >= left && p2 <= right){
                if(abs(*p1) < abs(*p2)){
                    squares.push_back(abs(pow(*p1, 2)));
                    p1--;
                }
                else if(abs(*p1) > abs(*p2)){
                    squares.push_back(abs(pow(*p2, 2)));
                    p2++;
                }
                else{
                    squares.push_back(abs(pow(*p1, 2)));
                    p1--;
                    squares.push_back(abs(pow(*p2, 2)));
                    p2++;
                }
            }
            if(p1 >= left){
                while(p1 >= left){
                    squares.push_back(abs(pow(*p1, 2)));
                    p1--;
                }
            }
            if(p2 <= right){
                while(p2 <= right){
                    squares.push_back(abs(pow(*p2, 2)));
                    p2++;
                }
            }
        }
        return squares;
    }
};
