class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); i ++) {
            arr[i] ^= arr[i - 1];
        }
        
        vector<int> answer;
        for (vector<int> query : queries) {
            int l = query[0], r = query[1];
            if (l == 0)
                answer.push_back(arr[r]);
            else
                answer.push_back(arr[r] ^ arr[l - 1]);
        }
        
        return answer;
    }
};