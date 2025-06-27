class Solution {
public:
    double f(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        int ind1 = (n + m) / 2;
        int ind2 = ind1 + 1;
        int cnt = 0;
        int i = 0, j = 0;
        int a = 0, b = 0;

        while (i < n && j < m) {
            int val;
            if (nums1[i] <= nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }
            cnt++;
            if (cnt == ind1) a = val;
            if (cnt == ind2) {
                b = val;
                return (a + b) / 2.0;
            }
        }

        while (i < n) {
            int val = nums1[i++];
            cnt++;
            if (cnt == ind1) a = val;
            if (cnt == ind2) {
                b = val;
                return (a + b) / 2.0;
            }
        }

        while (j < m) {
            int val = nums2[j++];
            cnt++;
            if (cnt == ind1) a = val;
            if (cnt == ind2) {
                b = val;
                return (a + b) / 2.0;
            }
        }

        return 0.0;
    }

    double f1(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        int ind = (n + m + 1) / 2;
        int cnt = 0, i = 0, j = 0;

        while (i < n && j < m) {
            int val;
            if (nums1[i] <= nums2[j]) {
                val = nums1[i++];
            } else {
                val = nums2[j++];
            }
            cnt++;
            if (cnt == ind) return val;
        }

        while (i < n) {
            int val = nums1[i++];
            cnt++;
            if (cnt == ind) return val;
        }

        while (j < m) {
            int val = nums2[j++];
            cnt++;
            if (cnt == ind) return val;
        }

        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if ((n + m) % 2 == 0) {
            return f(nums1, nums2, n, m);
        } else {
            return f1(nums1, nums2, n, m);
        }
    }
};
