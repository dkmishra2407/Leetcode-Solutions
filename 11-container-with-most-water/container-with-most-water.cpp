class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();

        int i = 0;
        int j = n-1;
        int maxi = INT_MIN;
        while(i<j){
            int area = min(arr[i],arr[j]) * (j-i);

            if (arr[i] < arr[j]) {
                i++;
            } else {
                j--;
            }
            maxi = max(area,maxi);
        }

        return maxi;
    }
};