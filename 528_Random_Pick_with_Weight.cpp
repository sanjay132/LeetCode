class Solution {
private:
    vector<int> local;
    int sum;
public:
    Solution(vector<int>& w) {
        sum=0;
        srand(time(NULL));
        for(int j=0;j<w.size();j++){
            int val = w[j];
            sum += val;
            local.push_back(sum);
        }
    }
    
    int pickIndex() {
        
        int randomIndex = rand()%sum+1;
        for(int i=0;i<local.size();i++){
            if(randomIndex<=local[i])
                return i;
        }
        return 0;
    }
};