class Solution {
public:
    
    bool dp(vector<int> & nums, int sum, int i,  map<pair<int,int>, bool> &table){
        //cout<<" i : "<<i<<" , sum : "<<sum<<endl;
        if(sum<0 || i>=nums.size()) return false;
        if(sum==0) return true;

        pair<int,int> p(sum, i);
        if(table.find(p)!=table.end()) return table[p];
        
        // include current index ( decrease the remaining sum )
        // dont include the index ( pass the sum as it is in next call)
        table[p] =  dp(nums, sum-nums[i], i+1, table) || dp(nums, sum, i+1, table);
        return table[p];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto val:nums)
            sum += val;
        
        if(sum%2!=0) return false;
        
        //sum = sum;
        map<pair<int,int> ,bool> table;
        return dp(nums, sum/2, 0, table);
    }
};