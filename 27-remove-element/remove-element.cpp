class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>temp;
        int n = nums.size();
        int cnt = 0;
        for(auto it:nums){
            if(it != val){
                temp.push_back(it);
            }
            else{
                cnt++;
            }
        }

        nums.clear();
        nums = temp;

        return n - cnt;
        // return nums.size() - count(nums.begin(),nums.end(),val);
    }
};