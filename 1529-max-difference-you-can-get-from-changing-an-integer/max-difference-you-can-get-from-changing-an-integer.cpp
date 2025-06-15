
class Solution {
public:
    int getStartingDigit(int num) {
        if (num == 0) return 0;
        int digits = (int)log10(num);       
        int divisor = (int)pow(10, digits); 
        return num / divisor;               
    }

    int maxDiff(int num) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int original = num;
        int lead = getStartingDigit(num);

        int replaceTargets[3] = {0, 1, 9};

        for (int x = 0; x <= 9; ++x) {
            vector<int> candidates;
            candidates.push_back(original); 

            for (int k = 0; k < 3; ++k) {
                int y = replaceTargets[k];
                int n = original;
                int temp = 0, place = 1;

                bool invalid = false;
                while (n > 0) {
                    int digit = n % 10;
                    int newDigit;

                    if (digit == x) {
                        newDigit = y;
                        if (newDigit == 0 && (n < 10)) {
                            invalid = true;
                        }

                        if ((place * 10 > original) && newDigit == 0) {
                            invalid = true;
                        }
                    } else {
                        newDigit = digit;
                    }

                    temp += newDigit * place;
                    place *= 10;
                    n /= 10;
                }

                if (!invalid && temp != 0) {
                    candidates.push_back(temp);
                }
            }

            maxi = max(maxi, *max_element(candidates.begin(), candidates.end()));
            mini = min(mini, *min_element(candidates.begin(), candidates.end()));
        }

        return maxi - mini;
    }
};
