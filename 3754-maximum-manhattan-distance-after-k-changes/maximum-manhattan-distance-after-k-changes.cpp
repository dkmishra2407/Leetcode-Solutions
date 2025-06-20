class Solution {
public:
    // static bool myf(pair<char,int>&a,pair<char,int>&b){
    //     if(a.second == b.second){
    //         return a.first > b.first;
    //     }
    //     return a.second > b.second;
    // }
    // int maxDistance(string s, int k) {
    //     int maxi = INT_MIN;
    //     // n  e  s  w
    //     int delrow[4] = {-1, 0, 1, 0};
    //     int delcol[4] = { 0, 1, 0, -1};
    //     int row = 0;
    //     int col = 0;

    //     map<char,int>m;
    //     for(auto it:s){
    //         m[it]++;
    //     }
    //     vector<pair<char,int>>vec(m.begin(),m.end());
    //     sort(vec.begin(),vec.end(),myf);

    //     for(auto it:vec){
    //         char c = it.first;
    //         int cnt = it.second;

    //             if(c == 'N'){
    //                 row += (cnt*delrow[0]);
    //                 col += (cnt*delcol[0]);
    //             }
    //             else if(c == 'E'){
    //                 row += (cnt*delrow[1]);
    //                 col += (cnt*delcol[1]);
    //             }
    //             else if(c == 'S'){
    //                 row += (cnt*delrow[2]);
    //                 col += (cnt*delcol[2]);
    //             }
    //             else{
    //                 row += (cnt*delrow[3]);
    //                 col += (cnt*delcol[3]);
    //             }

    //         int val = abs(row) + abs(col);

    //         if(val < maxi && k>0){

    //             k -= min(k,cnt);
    //             int cal = min(k,cnt);

    //             if(c == 'N'){
    //                 c = 'S';
    //             }
    //             else if(c == 'S'){
    //                 c = 'N';
    //             }
    //             else if(c == 'E'){
    //                 c = 'W';
    //             }
    //             else{
    //                 c = 'E';
    //             }

    //             if(c == 'N'){
    //                 row += (cal*delrow[0]);
    //                 col += (cal*delcol[0]);
    //             }
    //             else if(c == 'E'){
    //                 row += (cal*delrow[1]);
    //                 col += (cal*delcol[1]);
    //             }
    //             else if(c == 'S'){
    //                 row += (cal*delrow[2]);
    //                 col += (cal*delcol[2]);
    //             }
    //             else{
    //                 row += (cal*delrow[3]);
    //                 col += (cal*delcol[3]);
    //             }

    //             val = abs(row) + abs(col);
    //         }

    //         maxi = max(maxi,val);
    //     }

    //     return maxi;
    // }

    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
            
            int x = abs(north - south);
            int y = abs(east - west);
            int MD = x + y;
            int dis = MD + min(2 * k, i + 1 - MD);
            ans = max(ans, dis);
        }
        
        return ans;
    }
};