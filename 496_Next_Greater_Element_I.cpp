class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // create the next greater element for array 2 i.e nums2
        
        stack<int> st;
        vector<int> nextG(nums2.size());
        
        for(int i=nums2.size()-1; i>=0; i--){
            
            // check while stack has some element and current index element is greater then
            // top of stack because if curr elem is greater the top of stack then for all the 
            // element present in left of current all those stack element will become irrelevant
            // hence removing it.
            
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            
            // fill in the nextG array 
            // if stack is empty then add -1, i.e no element is greater the current element 
            nextG[i] = st.empty()?-1:st.top();
            // add current element to the stack
            st.push(nums2[i]);
        }
        
        // add the index of each element from nums2 in to the map
        unordered_map<int, int> hash;
        for(int i=0;i<nums2.size();i++){
            hash[nums2[i]] = i;
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            auto v=hash[nums1[i]];
            ans[i]=nextG[v];
            
        }
        return ans;
    }
};