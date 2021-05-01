class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        map<int, int> m;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()){
            while(m.find(nums[i]) != m.end()){
                i++;
                if(i == nums.size() - 2)
                    break;
            }
            if(i == nums.size() - 2)
                break;
            
            int num1 = nums[i];
            m[num1] = num1;
            int* num2 = &nums[i + 1];
            int* num3 = &nums[nums.size() - 1];
            
            while(num2 < num3){      
                vector<int> triplet;
                if(num1 + *num2 + *num3 == 0){   
                    triplet.push_back(num1);
                    triplet.push_back(*num2);
                    triplet.push_back(*num3);
                    ret.push_back(triplet);
                    int* temp1 = num2 + 1;
                    int* temp2 = num3 - 1;
                    
                }
                else if(num1 + *num2 + *num3 > 0){
                    num3--;
                }
                else{
                    num2++;
                }
            }
            i++;
        }
        return ret;
    }
};
