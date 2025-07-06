class FindSumPairs {
public:
    unordered_map<int, int> m1, m2;
    vector<int> temp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            m1[num]++;
        }
        for (int num : nums2) {
            m2[num]++;
            temp.push_back(num);
        }
    }

    void add(int index, int val) {
        int oldVal = temp[index];
        int newVal = oldVal + val;
        
        m2[oldVal]--;
        if (m2[oldVal] == 0) {
            m2.erase(oldVal);
        }

        m2[newVal]++;
        temp[index] = newVal;
    }

    int count(int tot) {
        int cnt = 0;
        for (auto& [num1, freq1] : m1) {
            int complement = tot - num1;
            if (m2.find(complement) != m2.end()) {
                cnt += freq1 * m2[complement];
            }
        }
        return cnt;
    }
};
