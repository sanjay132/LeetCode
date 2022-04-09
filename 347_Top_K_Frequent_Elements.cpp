class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> h;
        
        for(auto val:nums){
            h[val]++;
        }
        vector<int> v;
        using p = pair<int,int>;
        // we are trying to make min Heap based on frequecy of element
        // Hence compairing p1.second.p2.second
        auto cmp = [](p p1, p p2){
            return p1.second > p2.second;
        };
        
        // priority queue of pari of integers
        priority_queue<p,vector<p>, decltype(cmp)> pq(cmp);
        
        // iterator over all the map data
        for(auto [f,s]:h){
            // if priority queue size is less then K then directly add current pair
            if(pq.size()<k){
                pq.push({f,s});
            }else{
            // size of PQ is already K check whether top element is needed to be removed or not
                if(pq.top().second<s){
                    pq.pop();
                    pq.push({f,s});
                }
            }
        }
        // pop all elements and add to answer vector
        while(pq.size()){
            v.push_back(pq.top().first);
            pq.pop();
        }
        return v;
    }
};
