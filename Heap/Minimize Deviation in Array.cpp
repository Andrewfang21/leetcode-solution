class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int, vector<int>> q;
        int smallest = INT_MAX;
        int deviation = INT_MAX;
        
        for (int num : nums) {
            if (num % 2 == 1)
                num *= 2;
            q.push(num);
            smallest = min(smallest, num);
        }
        
        while (!q.empty()) {
            int largest = q.top();
            q.pop();
            deviation = min(deviation, largest - smallest);
            if (largest % 2 == 1)
                break;
            
            q.push(largest / 2);
            smallest = min(smallest, largest / 2);
        }
        
        return deviation;
    }
};