// class Solution {
// public:
//     string convert(string s, int n) {
        
//         string str = "";

//         if(n == 1){
//             return s;
//         }
        
//         int len = s.length();
//         int m = (( len / n ) + (len / (n-2)));

//         vector<vector<char>>vec(n,vector<char>(m,'.'));

//         int i = 0;
//         int j = 0;
//         int k = 0;

//         while(k < len){
//             while(i < n && k < n){
//                vec[i][j] = s[k];
//                i++;
//                k++;   
//             }
//             i--;
//             j++;
//             while(i >=1 && k < n){
//                vec[i][j] = s[k];
//                i--;
//                k++;   
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vec[i] != '.'){
//                     str += vec[i];
//                 }
//             }
//         }
//         return str;
//     }
// };

class Solution {
public:
    string convert(string s, int n) {
        string str = "";

        if(n == 1){
            return s;
        }

        int len = s.length();
        int m = len; 

        vector<vector<char>> vec(n, vector<char>(m, '$'));

        int i = 0, j = 0, k = 0;
        while (k < len) {
            // Going down
            while (i < n && k < len) {
                vec[i][j] = s[k];
                i++;
                k++;
            }

            i -= 2;
            j++;

            while (i >= 0 && k < len) {
                vec[i][j] = s[k];
                i--;
                j++;
                k++;
            }

            i += 2;  
            j--;     
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vec[i][j] != '$') {
                    str += vec[i][j];
                }
            }
        }

        return str;
    }
};
