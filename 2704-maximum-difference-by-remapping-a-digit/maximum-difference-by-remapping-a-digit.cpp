class Solution {
public:
    int minMaxDifference(int temp) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i <= 9; i++) {
            int place = 1;
            int num = temp;
            int minu = 0;
            while (num > 0) {
                int d = num % 10;
                if (d == i) {
                    minu += (0 * place);
                } else {
                    minu += (d * place);
                }
                place *= 10;
                num = num / 10;
            }
            mini = min(mini, minu);
        }

        for (int i = 0; i <= 9; i++) {
            int place = 1;
            int maxu = 0;
            int num = temp;

            while (num > 0) {
                int d = num % 10;
                if (d == i) {
                    maxu += (9 * place);
                } else {
                    maxu += (d * place);
                }
                place *= 10;
                num = num / 10;
            }
            maxi = max(maxi, maxu);
        }

        return maxi - mini;
    }
};