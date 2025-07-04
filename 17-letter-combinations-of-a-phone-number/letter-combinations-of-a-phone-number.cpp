class Solution {
public:
    vector<string>ans;
    unordered_map<int,string> m;
    void f(string str,int i,string path){
        if(i == str.size()){
            if(path.size() == 0){
                return;
            }
            ans.push_back(path);
            return;
        }
        
        string nstr = m[(str[i]-'0')];

        for(auto it:nstr){
            f(str,i+1,path+it);
        }
    }
    vector<string> letterCombinations(string str) {
         m[2]="abc";m[3]="def";m[4]="ghi";m[5]="jkl";m[6]="mno";
         m[7]="pqrs";m[8]="tuv";m[9]="wxyz";
         f(str,0,"");
         return ans;
    }
};