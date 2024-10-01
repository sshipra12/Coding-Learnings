class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        // TODO: This solution gives TLE, resolve this
        int i,j,n=nums.size(),lMax=0,lMin=INT_MAX; // lMax and lMin to store the left min and max while iterating with index 'i'
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);

        for(i=0;i<=n-1;i++){
            if(i==0||(nums[i]<lMin||nums[i]>lMax)){    // NOTE: some pruning of operations is being done which is important to learn and can be applied other places
                for(j=i+indexDifference;j<=n-1;j++){
                    if(abs(nums[i]-nums[j])>=valueDifference){
                        ans[0]=i;
                        ans[1]=j;
                        break;
                    }
                }
            }
            if(ans[0]!=-1)
                break;

            lMax=max(nums[i],lMax);
            lMin=min(nums[i],lMin);
        }
        return ans;
    }
};
