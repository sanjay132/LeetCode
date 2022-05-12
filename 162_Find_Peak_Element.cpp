class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l,r,mid;
        
        l = 0;
        r = nums.size()-1;
        
        while(l<r){
            mid = l + (r-l)/2;
            
            
            if(nums[mid]<nums[mid+1]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};