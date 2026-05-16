class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=0;
        if(nums[0] < nums[nums.size()-1]){
            return nums[0];
        }
        else{
            min=nums[0];
            for(int i =0;i<nums.size();i++){
                if (min>nums[i]){
                    min=nums[i];
                }
            }
            return min;
        }
    }
};