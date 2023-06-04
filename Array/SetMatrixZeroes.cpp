class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> rset;
        set<int> cset;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    rset.insert(i);
                    cset.insert(j);
                }
            }
        }
        for(auto it: rset){
            for(int i=0;i<m;i++){
                matrix[it][i] = 0;
            }
        }
        for(auto it: cset){
            for(int i=0;i<n;i++){
                matrix[i][it] = 0;
            }
        }
    }
};