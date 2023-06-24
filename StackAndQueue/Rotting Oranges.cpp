class Solution {
public:
    bool isvalid(int x,int y , int sx,int sy,vector<vector<int>>& grid){
        if(x < 0 or y < 0 or x >= sx or y >= sy or grid[x][y] == 2 or grid[x][y] == 0)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i< grid.size();i++){
            for(int j =0;j < grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int intsiz = q.size();
        int count = 0;
        while(!q.empty()){
            int sz = q.size();
            ++count;
            for(int i = 0 ; i< sz;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(isvalid(x+1,y,grid.size(),grid[0].size(),grid)){
                    q.push({x+1,y});
                    grid[x+1][y] = 2;
                }
                if(isvalid(x-1,y,grid.size(),grid[0].size(),grid)){
                    q.push({x-1,y});
                    grid[x-1][y] = 2;
                }
                if(isvalid(x,y-1,grid.size(),grid[0].size(),grid)){
                    q.push({x,y-1});
                    grid[x][y-1] = 2;
                }
                if(isvalid(x,y+1,grid.size(),grid[0].size(),grid)){
                    q.push({x,y+1});
                    grid[x][y+1] = 2;
                }
            }
        }
        for(int i = 0; i< grid.size();i++){
            for(int j =0;j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(intsiz == 0){
            return 0;
        }
        return count-1;
    }
};