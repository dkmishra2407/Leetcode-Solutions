class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();

        if (n % gs != 0) {
            return false;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        unordered_map<int, int> mp;

        for (auto it : hand) {
            mp[it]++;
        }

        for (auto it : mp) {
            pq.push(it.first);
        }

        while (!pq.empty()) {
            int start = pq.top();  
            for (int i = 0; i < gs; i++) {
                int curr = start + i;

                if (mp[curr] == 0) {
                    return false;  
                }

                mp[curr]--;

                if (mp[curr] == 0 && curr == pq.top()) {
                    pq.pop();
                }
            }

            while (!pq.empty() && mp[pq.top()] == 0) {
                pq.pop();
            }
        }

        return true;
    }
};
