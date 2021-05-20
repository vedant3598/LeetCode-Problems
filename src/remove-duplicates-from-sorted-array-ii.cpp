class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        int ret = 0;
        const int next = 2;
        
        while(p1 < nums.size()){
            cout << p1 << " " << p2 << endl;
            int counter = 0;
            while(p2 < nums.size() && nums[p1] == nums[p2]){
                counter++;
                p2++;
            }
            if(counter <= 2){
                p1 += counter;
                ret += counter;
            }
            else{
                nums[p1+next] = nums[p2];
                ret += 2;
                p1 += 2;
                if(p2 + 1 < nums.size() && nums[p2+1] == nums[p2]){
                    nums[p1+1] = nums[p2];
                    p1 += 1;
                }
                //cout << nums[4] << endl;
            }
        }
        
        return ret;
    }
};
