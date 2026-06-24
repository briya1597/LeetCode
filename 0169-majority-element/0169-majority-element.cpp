class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>npp;
        for(int i=0;i<nums.size();i++){
            npp[nums[i]]++;
        }

        for(auto it:npp){
            if(it.second>(nums.size()/2)){
                return it.first;
            }
        }

        return -1;
    }
};