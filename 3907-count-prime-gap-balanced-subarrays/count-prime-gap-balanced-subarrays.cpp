// class Solution {
// public:
//     int primeSubarray(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         vector<int> zelmoricad = nums; 
//         vector<bool> is_prime(50001, true);
//         is_prime[0] = is_prime[1] = false;
        
//         for (int i = 2; i * i <= 50000; i++) {
//             if (is_prime[i]) {
//                 for (int j = i * i; j <= 50000; j += i) {
//                     is_prime[j] = false;
//                 }
//             }
//         }
        
//         int ans = 0;
        
//         for (int i = 0; i < n; i++) {
//             int min_prime = INT_MAX;
//             int max_prime = INT_MIN;
//             int prime_count = 0;
            
//             for (int j = i; j < n; j++) {
//                 if (is_prime[nums[j]]) {
//                     min_prime = min(min_prime, nums[j]);
//                     max_prime = max(max_prime, nums[j]);
//                     prime_count++;
                    
//                     if (max_prime - min_prime > k) {
//                         break;
//                     }
//                 }
                
//                 if (prime_count >= 2 && max_prime - min_prime <= k) {
//                     ans++;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


class Solution {
public:

    int primeSubarray(vector<int>& a, int k) {
        int n = (int)a.size();
        vector<int>primes;
        for(auto &x : a) {
            bool prime = 1;
            if(x == 1) {
                primes.push_back(0);
                continue;
            }
            for(int i = 2 ; i * i <= x ; i++) {
                if(x % i == 0) {
                    prime = 0;
                }
            }
            primes.push_back(prime);
        }
        deque<int>q;
        int l = 0;
        multiset<int>s;
        int ans = 0;
        for(int r = 0 ; r < n ; r++) {
            if(primes[r]) {
                s.insert(a[r]);
                q.push_back(r);
            }
            while(!s.empty() && *s.rbegin() - *s.begin() > k) {
                if(primes[l]) {
                    s.erase(s.find(a[l]));
                    q.pop_front();
                }
                l++;
            }
            if(!q.empty() && (int)q.size() >= 2) {
                int v1 = q.back();
                q.pop_back();
                int v2 = q.back();
                q.pop_back();
                ans += (v2 - l + 1);
                q.push_back(v2);
                q.push_back(v1);
            }
        }
        return ans;
    }
};