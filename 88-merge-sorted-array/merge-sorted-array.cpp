class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1.begin(), nums1.begin() + m);
        int i = 0;  // Pointer for temp
        int j = 0;  // Pointer for nums2
        int k = 0;  // Pointer for merged result in nums1

        while(i < m && j < n){
            if(temp[i] <= nums2[j]){
                nums1[k] = temp[i];
                k++;
                i++;
            }
            else{
                nums1[k] = nums2[j];
                k++;
                j++;
            }
        }

        while(i < m){
            nums1[k] = temp[i];
            k++;
            i++;
        }

        while(j < n){
            nums1[k] = nums2[j];
            k++;
            j++;
        }
    }
};
