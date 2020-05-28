class Solution {
public:
  int characterReplacement(string s, int k) {
    int res = 0;
    int n = s.size();
    int mostOccur = 'A';

    int l = 0, r = 0;
    map<char, int> exist;
    while (r < n)
    {
      exist[s[r]]++;
      if (exist[s[r]] >= exist[mostOccur])
        mostOccur = s[r];

      int currLength = r - l + 1;
      if (currLength - exist[mostOccur] > k)
      {
        exist[s[l]]--;
        l++;
        currLength--;
      }
      r++;
      res = max(res, currLength);
    }
    return res;
  }
};