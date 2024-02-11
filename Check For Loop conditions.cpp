class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i,j,smaller;
        vector<int> ans;
        for(i=0;i<nums.size();i++){
            smaller=0;
            for(j=0;j<nums.size();j++){
                if(j!=i&&nums[j]<nums[i])
                    smaller++;
            }
            ans.push_back(smaller);
        }
        return ans;

        /*for(i=0;i<nums.size()&&j!=i;i++){     // Here condition (j!=i) is in loop conditions so the FIRST time condition fails WHOLE loop will exit
            smaller=0;
            for(j=0;j<nums.size();j++){
                if(nums[j]<nums[i])
                    smaller++;
            }
            ans.push_back(smaller);
        }*/
    }
};
