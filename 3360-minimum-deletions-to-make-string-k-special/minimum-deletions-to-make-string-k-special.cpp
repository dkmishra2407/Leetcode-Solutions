// class Solution {
// public:
//     static bool mycmp(pair<char, int>& a, pair<char, int>& b) {
//         return a.second > b.second;
//     }

//     int minimumDeletions(string word, int k) {
//         unordered_map<char, int> m;

//         for (auto ch : word) {
//             m[ch]++;
//         }

//         int ans = 0;

//         vector<pair<char, int>> vec(m.begin(), m.end());

//         sort(vec.begin(), vec.end(), mycmp);

//         int i = 0, j = vec.size() - 1;

//         while (i < j) {
//             int val = abs(vec[i].second - vec[j].second);
//             int needed = val - k;
//             if (val <= k) {
//                 j--;
//             }
//             else if(needed - vec[j].second <= 0){
//                 ans += vec[j].second;
//                 vec[j].second = 0;
//                 j--;
//             }
//             else{
//                 ans += (needed - vec[j].second);
//                 vec[i].second -= (needed - vec[j].second);
//                 i++;
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;

        for (char ch : word) {
            freq[ch]++;
        }

        vector<int> freqs;
        for (auto& it : freq) {
            freqs.push_back(it.second);
        }

        int ans = INT_MAX;

        for (int i = 0; i < freqs.size(); i++) {
            int x = freqs[i];
            int deletions = 0;

            for (int y : freqs) {
                if (y < x) {
                    deletions += y; 
                } else if (y > x + k) {
                    deletions += (y - x - k);  
                }
            }

            ans = min(ans, deletions);
        }

        return ans;
    }
};
