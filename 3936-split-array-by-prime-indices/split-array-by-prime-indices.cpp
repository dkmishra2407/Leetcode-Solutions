class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long diff = 0;
        long long n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<long long>primes(n+1,1);
        primes[0] = 0;
        primes[1] = 0;
        primes[2] = 1;
        for(long long i=2;i<=n;i++){
            for(long long j=i*i;j<=n;j++){
                if(j%i == 0){
                    primes[j] = 0;
                }
            }
        }

        for(long long i=0;i<n;i++){
            if(primes[i]){
                diff += nums[i];
            }
            else{
                diff -= nums[i];
            }
        }
        return abs(diff);
    }
};