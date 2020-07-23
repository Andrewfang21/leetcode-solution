class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
    MedianFinder() {
           
    }
    
    void addNum(int num) {
        int n = minHeap.size();
        int m = maxHeap.size();
        
        if (n == 0 || m == 0) {
            if (n == 0 && m == 0) {
                minHeap.push(num);
            } else {
                if (n == 0) {
                    if (num > maxHeap.top())
                        minHeap.push(num);
                    else {
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                        maxHeap.push(num);
                    }
                } else {
                    if (num > minHeap.top()) {
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(num);
                    } else maxHeap.push(num);
                }
            }
            return;
        }
        
        if (n > m) {
            if (num > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } else maxHeap.push(num);
        } else if (n < m) {
            if (num > maxHeap.top())
                minHeap.push(num);
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        } else {
            if (num > maxHeap.top()) {
                minHeap.push(num);
            } else maxHeap.push(num);
        }
    }
    
    double findMedian() {
        int n = minHeap.size();
        int m = maxHeap.size();
        
        if (n == m)
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else {
            if (n > m)
                return minHeap.top();
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */