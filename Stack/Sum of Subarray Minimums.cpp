class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left(arr.size(), 0), right(arr.size(), 0);
        stack<pair<int,int>> st;
        
        for (int i = 0; i < arr.size(); i ++) {
            int curr = 1;
            while (!st.empty() && st.top().first > arr[i]) {
                curr += st.top().second;
                st.pop();
            }
            
            left[i] = curr;
            st.emplace(arr[i], curr);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = arr.size() - 1; i >= 0; i --) {
            int curr = 1;
            while (!st.empty() && st.top().first >= arr[i]) {
                curr += st.top().second;
                st.pop();
            }
            
            right[i] = curr;
            st.emplace(arr[i], curr);
        }
        
        long long answer = 0;
        const long long MOD = 1e9 + 7;
        for (int i = 0; i < arr.size(); i ++) {
            answer = (answer + (((long long) left[i] * (long long) arr[i]) % MOD * (long long) right[i] % MOD) % MOD) % MOD;
        }
        
        return answer;
    }
};
