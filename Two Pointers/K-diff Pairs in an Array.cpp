class Solution {
public:
    int findPairs(vector<int>& nums, int k) {        
        set<int> s;
        map<int, int> cnt;
        for (int n : nums) {
            s.insert(n);   
            cnt[n] ++;
        }
        
        if (k == 0) {
            int res = 0;
            for (const auto &it : cnt) {
                if (cnt[it.first] > 1)
                    res ++;
            }
            return res;
        }
        
        vector<int> numbers;
        for (const auto &it : s) {
            numbers.push_back(it);
        }
        
        if (numbers.size() <= 1)
            return 0;
        
        for (int n : numbers)
            cout << n << " ";
        puts("");
        
        int l = 0, r = 1;
        int n = numbers.size();
        int res = 0;
        while (r < n) {
            while (numbers[r] - numbers[l] < k && r < n - 1)
                r ++;
            while (numbers[r] - numbers[l] > k && l < r)
                l ++;
            if (r == n - 1 && numbers[r] - numbers[l] != k)
                break;
            
            if (numbers[r] - numbers[l] == k) {
                res ++;
                l ++, r ++;
            }
        }
        
        return res;
    }
};