class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int i,j,n=nums.size(),segMax,segMin;
        vector<int> ans(2,-1);
        map<int,vector<int>> segPositionsMap;

        // USING Power of hash maps, as we are storing an array as value in key-value pair in map
        // fill map first from indexDifference to n-1 segment storing each element's positions
        for(i=n-1;i>=indexDifference;i--)
            segPositionsMap[nums[i]].push_back(i);

        
        for(i=0;i<=n-1&&i+indexDifference<=n-1;i++){
            // adjust the valid segment stored in map accroding to ith element
            if(i!=0){
                segPositionsMap[nums[i+indexDifference-1]].pop_back();
                if(segPositionsMap[nums[i+indexDifference-1]].empty())
                    segPositionsMap.erase(nums[i+indexDifference-1]);
            }
            
            // valid segment for comparision is from i+indexDifference to n-1
            segMax=segPositionsMap.rbegin()->first;
            segMin=segPositionsMap.begin()->first;

            if(abs(nums[i]-segMax)>=valueDifference){
                ans[0]=i;
                ans[1]=segPositionsMap[segMax][0];
                break;
            }
            else if(abs(nums[i]-segMin)>=valueDifference){
                ans[0]=i;
                ans[1]=segPositionsMap[segMin][0];
                break;
            }

            if(ans[0]!=-1)
                break;
        }
        return ans;
    }
};
//OLD Solution
/*
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
*/
