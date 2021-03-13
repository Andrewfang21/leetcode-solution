class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> occur;
        for (int i = 0; i < S.length(); i ++)
            occur[S[i]] = i;
        
        int currFarthest = occur[S[0]];
        int left = 0, right = 0;
        vector<int> partitions;
        
        while (right < S.size()) {
            currFarthest = max(currFarthest, occur[S[right]]);
            if (currFarthest == right) {
                int length = right - left + 1;
                partitions.push_back(length);
                left = right + 1;
            }
            right ++;
        }
        
        return partitions;
    }
};