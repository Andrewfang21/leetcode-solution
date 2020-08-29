class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> cnt;
        vector<int> vec;
        for (auto a : arr)
            cnt[a] ++;
        for (auto a : cnt)
            vec.push_back(a.second);
        
        sort(vec.begin(), vec.end(), greater<int>());
        int res = 0;
        int target = arr.size() / 2;
        for (int x : vec) {
            target -= x;
            res ++;
            if (target <= 0)
                break;
        }
        return res;
    }
};
