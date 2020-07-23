class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : A) {
            if (num >= 0)
                minHeap.push(num);
            else maxHeap.push(-num);
        }
        
        int res = 0;
        while (K --) {
            if (!maxHeap.empty()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();            
                continue;
            }
            if (!minHeap.empty()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        while (!minHeap.empty())
            res += minHeap.top(), minHeap.pop();
        while (!maxHeap.empty())
            res -= maxHeap.top(), maxHeap.pop();
        
        return res;
    }
};