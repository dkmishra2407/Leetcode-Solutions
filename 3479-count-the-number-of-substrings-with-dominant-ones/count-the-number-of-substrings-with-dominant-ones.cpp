class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')v.push_back(i);
        }
        v.push_back(n);
        int next=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(v[next]<i)next++;
            for(int j=0;j<200;j++)
            {
                if(next+j<v.size()) 
                {
                    if(i+j+j*j>n)break;
                    
                    int right=v[next+j]-1; 
                    int zero=j; 
                    int len=right-i+1; 
    
                    long long miniLengthString = zero+(zero*zero);
                    if(miniLengthString<=1)miniLengthString=1; 
                    
                    long long max_freedom=1e11;
                    if(j>0)max_freedom=right-v[next+j-1]+1;
                    
                    long long count=len-miniLengthString+1;
                    
                    if(count<0)count=0;
                    if(count>max_freedom)count=max_freedom;
                    
                    ans+=count;
                } 
                else 
                {
                    break;
                }
            }
        }
        return ans;
    }
};