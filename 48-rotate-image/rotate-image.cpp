class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
         //TRANSPOSE OF THE MATRIX
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
         }


        //REVERSE EACH ROW
         for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
         }
    }
};