class Solution {
private:
    #define LIVE 2
    #define DEAD 3
    vector<int> X{-1,-1,0,1,1,1,0,-1};
    vector<int> Y{0,1,1,1,0,-1,-1,-1};
    // This function return the live and dead count present in the neighbor cell
    pair<int,int> & getNeighbourCount(vector<vector<int>>& board, int row, int col, int cr, int cc){
        pair<int,int> ans;
        int live, dead;
        live = dead = 0;
        for(int i=0; i<8; i++){
            //checking valid boundary
            if(X[i]+cr>=0 && X[i]+cr<=row && Y[i]+cc>=0 && Y[i]+cc<=col){
                // if cell is 0 or LIVE (2)this is because this will become live
                if(board[X[i]+cr][Y[i]+cc] == 0 || board[X[i]+cr][Y[i]+cc]==LIVE){
                    dead++;
                }
                // if cell is 1 or DEAD (3)this is because this will become dead
                else if(board[X[i]+cr][Y[i]+cc] == 1 || board[X[i]+cr][Y[i]+cc]==DEAD){
                    live++;
                }
            }
        }
        ans = {live,dead};
        return ans;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {

        
        int r,c;
        r = board.size()-1;
        c = board[0].size()-1;
        // traverse the board
        for(int i=0; i<=r; i++){
            for(int j=0; j<=c; j++){
                auto [l,d] = getNeighbourCount(board, r, c, i, j);
                //current cell is dead
                if(board[i][j] == 0){
                    // make dead to live ( as per rule)
                    if (3==l){
                        board[i][j] = LIVE;
                    }
                }else{
                    // make live to dead as per rule
                    if(!(l==2 || l==3)){
                        board[i][j] = DEAD;
                    }
                }
            }
        }
        for(int i=0; i<=r; i++){
            for(int j=0; j<=c; j++){
                if(board[i][j]==LIVE)
                    board[i][j] = 1;
                if(board[i][j]==DEAD)
                    board[i][j] = 0;
            }
        }
    }
};
