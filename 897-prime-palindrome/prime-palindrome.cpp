class Solution {
public:
    bool isprime(int n){
        if (n < 2) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    bool ispali(int n){
        int original = n;
        int reversed = 0;

        while(n > 0){
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }

        return reversed == original;
    }

    int primePalindrome(int n) {
        if(n >= 8 && n <= 11) return 11;

        while(true){
            // skip even-length digit numbers (except 11), because they can't be prime
            int len = to_string(n).length();
            if (len % 2 == 0) {
                n = pow(10, len);
                continue;
            }

            if(ispali(n) && isprime(n)){
                return n;
            }

            n++;
        }

        return -1;
    }
};
