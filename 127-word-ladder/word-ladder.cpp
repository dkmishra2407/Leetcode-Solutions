// class Solution {
// public:
//     int ladderLength(string start, string end, vector<string>& arr) {
//         unordered_set<string>st(arr.begin(),arr.end());
//         vector<string>vec;

//         vec.push_back(start);
//         int ans = 0;
//         while(!st.empty()){
//             ans++;
//             for(auto it:vec){
//             for(int i=0;i<it.size();i++){
//                 for(char t= 'a';t<'z';t++){
//                     it[i] = t;
//                     if(it == end){
//                         return ans;
//                     }
//                     if(st.find(it) == st.end()){
//                         vec.push_back(it);
//                         st.erase(it);
//                     }
//                 }
//             }
//         }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int ladderLength(string start, string end, vector<string>& arr) {
        unordered_set<string> st(arr.begin(), arr.end());
        if(st.find(end) == st.end()) return 0;

        vector<string> vec;
        vec.push_back(start);
        int ans = 1;

        while (!vec.empty()) {
            vector<string> temp;
            for (auto it : vec) {
                for (int i = 0; i < it.size(); i++) {
                    char original = it[i];
                    for (char t = 'a'; t <= 'z'; t++) {
                        it[i] = t;
                        if (it == end) return ans + 1;
                        if (st.find(it) != st.end()) {
                            temp.push_back(it);
                            st.erase(it);
                        }
                    }
                    it[i] = original; 
                }
            }
            vec = temp;
            ans++;
        }
        return 0; 
    }
};
