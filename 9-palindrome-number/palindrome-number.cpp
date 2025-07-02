class Solution {
public:
    bool ispali(string str){
        int l = 0;
        int h = str.length() - 1;

        while(l<=h){
            if(str[l] != str[h]){
                return false;
            }
            l++;
            h--;
        }

        return true;
    }
    bool isPalindrome(int x) {
        return ispali(to_string(x));
    }
};