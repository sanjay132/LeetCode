class Solution {

private:

    int find(vector<int> &root, int vertex){
        return root[vertex];
    }

    void Union(vector<int> &root, int v1, int v2){
        int r1 = find(root, v1);
        int r2 = find(root, v2);

        if(r1 != r2){
            for(int i=0; i<root.size(); i++){
                if(root[i]==r2){
                    // making r1 as parent
                    root[i] = r1;
                }
            }            
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int row = isConnected.size();
        int col = isConnected[0].size();
        vector<int> roots(row);

        // filling all the vertices with value as ith index 
        // as each element is root node of itself
        for(int i=0; i<row; i++){
            roots[i] = i;
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isConnected[i][j] && i!=j){
                    Union(roots, i, j);
                }
            }
        }
        int ans=0;
        unordered_map<int,bool> h;
        for(auto val:roots)
            h[val]=true;
        return h.size();
    }
};