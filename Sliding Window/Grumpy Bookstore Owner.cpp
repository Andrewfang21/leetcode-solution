class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
    int n = customers.size();
    int potentials[n + 5];
    int pref[n + 5];

    pref[0] = potentials[0] = 0;
    for (int i = 1; i <= n; i ++) {
      pref[i] = pref[i - 1] + (grumpy[i - 1] == 0 ? customers[i - 1] : 0);
      potentials[i] = potentials[i - 1] + customers[i - 1];
    }

    int l = 1, r = X;
    int res = -1;
    while (r <= n) {
      int rem = (pref[n] - pref[r]) + (pref[l - 1] - pref[0]);
      int potential = potentials[r] - potentials[l - 1];
      res = max(res, rem + potential);

      l ++;
      r ++;
    }

    return res;
  }
};