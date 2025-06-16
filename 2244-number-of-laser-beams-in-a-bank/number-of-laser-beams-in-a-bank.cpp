class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>ans;

        for(auto it:bank){
            int cnt = 0;
            for(auto itr:it){
                if(itr == '1'){
                    cnt++;
                }
            }
            if(cnt > 0){
                ans.push_back(cnt);
            }
        }

        int n = ans.size();
        int fans = 0;
        
        if(n == 1){
            return 0;
        }

        for(int i=0;i<n-1;i++){
            fans += (ans[i] * ans[i+1]);
        }

        return fans;
    }
};