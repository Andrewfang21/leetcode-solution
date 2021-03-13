class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        vector<int> res(2, 0);
        while (l < r) {
            int curr = numbers[l] + numbers[r];
            if (curr < target)
                l ++;
            else if (curr > target)
                r --;
            else {
                res[0] = l + 1, res[1] = r + 1;
                return res;
            }
        }
        return res;
    }
};