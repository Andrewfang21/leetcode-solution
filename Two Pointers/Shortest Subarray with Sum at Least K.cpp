class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int res = INT_MAX;
        deque<int> q;
        for (int i = 0; i < A.size(); i ++) {
            if (i)  A[i] += A[i - 1];
            if (A[i] >= K)
                res = min(res, i + 1);
            while (!q.empty() && A[i] - A[q.front()] >= K) {
                res = min(res, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && A[i] <= A[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};