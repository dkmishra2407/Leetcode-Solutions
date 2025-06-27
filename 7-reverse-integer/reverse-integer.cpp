class Solution {
public:
    int reverse(int x) {
        bool isneg = false;
        if(x > INT_MAX || x <INT_MIN) return 0;
        if(x == 0){
            return x;
        }
        if(x < 0){
            isneg = true;
        }

        x = abs((long long)x);
        
        long long num = 0;

        while(x > 0){
            if(num > INT_MAX/10 || num <INT_MIN/10) return 0;
            num = ((num * 10 ) + x%10);
            x = x/10;
        }

        if(isneg){
            return (int)(-1 * num);
        }
        return (int)num;
    }
};