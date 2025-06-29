class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        stack<char> st;

        for (auto it : s) {
            if (it == '(') {
                st.push(it);
            } else if (it == ')') {
                if(st.size() >= 1){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }
        return st.size() + ans;
    }
};