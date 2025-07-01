class Solution {
public:
    int possibleStringCount(string word) {
        // unordered_map<char,int>m;

        // for(auto it:word){
        //     m[it]++;
        // }
        // int cnt = 0;
        // for(auto it:m){
        //     if(it.second > 1){
        //         cnt += (it.second - 1);
        //     }
        // }

        // return cnt+1;

        int cnt = 0;
        int n = word.length();

        for(int i=0;i<n;i++){
            if(i == 0){
                continue;
            }

            if(word[i] == word[i-1]){
                cnt++;
            }
        }
        return cnt+1;
    }
};