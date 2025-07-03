class Solution {
public:
    char kthCharacter(int k) {
        
        string str = "a";
        while(str.length() < k){
            string nstr = "";
            for(auto it:str){
                if(it=='z'){
                    nstr += 'a';
                    continue;
                }
                nstr += (it+1);
            }
            str += nstr;
        }
        return str[k-1];
    }
};