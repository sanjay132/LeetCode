class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();

        stack<int> st;
        vector<int> ans(nums.size());

        for(int i=2*size-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums[i%size]){
                st.pop();
            }
            ans[i%size] = st.empty()?-1:st.top();
            st.push(nums[i%size]);
        }
        return ans;
    }
};