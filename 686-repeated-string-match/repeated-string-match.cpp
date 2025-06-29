// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         if (a == b) {
//             return 1;
//         }
//         map<char,int>m1,m2;

//         for(auto it:a){
//             m1[it]++;
//         }
//         for(auto it:b){
//             m2[it]++;
//         }

//         if(m1.size() != m2.size()){
//             return -1;
//         }

//         auto it = m1.begin();
//         auto itr = m2.begin();
//         int maxi = 1;
//         while(it != m1.end()){
//             if(it->first != itr->first){
//                 return -1;
//             }
//             maxi = max(maxi,itr->second);
//             it = next(it,1);
//             itr = next(itr,1);
//         }
//         int cnt = 0;
//         while (a.find(b) == string::npos) {
//             a = a + a;
//             cnt++;

//             if(a.size() > b.size()*(maxi+2)){
//                 return -1;
//             }
//         }

//         return cnt+1;
//     }
// };

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (repeated.find(b) != string::npos) {
            return count;
        }

        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};
