class Solution {
public:
    int countTriplets(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i ++)
            arr[i] ^= arr[i - 1];
        
        int answer = 0;
        for (int i = 0; i < arr.size(); i ++) {
            for (int j = i + 1; j < arr.size(); j ++) {
                int curr = (i == 0) ? arr[j] : arr[j] ^ arr[i - 1];
                if (curr == 0)
                    answer += (j - i);
            }
        }
        return answer;
    }
};