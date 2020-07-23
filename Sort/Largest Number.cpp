bool cmp(int l, int r) {
    string x, y;
    if (l == 0)
        x = to_string(r);
    else x = to_string(l).append(to_string(r));

    if (r == 0)
        y = to_string(l);
    else y = to_string(r).append(to_string(l));

    if (x.length() > y.length())
        return true;
    else if (x.length() < y.length())
        return false;
    else {
        for (int i = 0; i < x.length(); i ++) {
            if (x[i] - '0' > y[i] - '0')
                return true;
            else if (x[i] - '0' < y[i] - '0')
                return false;
        }
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        
        bool hasNonZero = false;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0 && !hasNonZero)
                continue;
            res = res.append(to_string(nums[i]));
            hasNonZero = true;
        }
        return res == "" ? "0" : res;
    }
};