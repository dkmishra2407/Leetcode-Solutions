class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        map<int,int>m;

        for(auto it:nums){
            m[it]++;
        }

        auto it = m.begin();

        while(it != m.end()){
            int num1 = it->first;
            auto itr = next(it,1);
            int num2 = itr->first;

            if(num2 - num1 == 1){
                ans = max(ans,it->second + itr->second);
            }
            it = itr;
        }

        return ans;
    }
};