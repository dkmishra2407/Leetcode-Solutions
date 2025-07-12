class MedianFinder {
public:
    priority_queue<int> maxi; 
    priority_queue<int, vector<int>, greater<int>>
        mini; 
    MedianFinder() {}

    void addNum(int num) {
        if (mini.empty() || num >= mini.top()) {
            mini.push(num);
        } else {
            maxi.push(num);
        }

        if (mini.size() > maxi.size() + 1) {
            maxi.push(mini.top());
            mini.pop();
        } else if (maxi.size() > mini.size()) {
            mini.push(maxi.top());
            maxi.pop();
        }
    }

    double findMedian() {
        if (mini.size() == maxi.size()) {
            return ((mini.top() + maxi.top()) / 2.0);
        } else {
            return (mini.top());
        }
    }
};