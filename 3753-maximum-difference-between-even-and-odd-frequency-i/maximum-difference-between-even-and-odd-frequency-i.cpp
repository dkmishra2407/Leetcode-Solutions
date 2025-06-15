class Solution {
public:
    int maxDifference(string s) {
        
        unordered_map<char,int>m;

        for(auto it:s){
            m[it]++;
        }
        int maxOdd = 1, minEven = s.size();
        for(auto it=m.begin(); it != m.end();it++){
            int value = it->second;
            if((it->second%2) == 0){
                minEven = min(minEven, value);
            }
            else{
                maxOdd = max(maxOdd, value);
            }
        }

        return maxOdd - minEven;
    }
};