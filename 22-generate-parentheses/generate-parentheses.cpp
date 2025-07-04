class Solution {
public:
    vector<string>ans;
    void f(int n,string str,int op,int cl){
        if(str.size() == n*2){
            ans.push_back(str);
            return;
        }

        if(op + 1 <= n){
            f(n,str + '(',op+1,cl);
        }

        if(op > cl){
            f(n,str + ')',op,cl+1);
        }

    }
    vector<string> generateParenthesis(int n) {
        f(n,"",0,0);
        return ans;
    }
};