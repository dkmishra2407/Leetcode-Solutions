class Solution {
public:
    int possibleStringCount(string word) {
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