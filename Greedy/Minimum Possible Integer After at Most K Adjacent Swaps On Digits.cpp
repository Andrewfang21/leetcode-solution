const int N = 3e4 + 5;
const int K = 10;

class Solution {
public:
    int BIT[N];
    
    void update(int idx, int k) {
        while (idx < N) {
            BIT[idx] += k;
            idx += (idx & -idx);
        }
    }
    
    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += BIT[idx];
            idx -= (idx & -idx);
        }
        
        return res;
    }
    
    string minInteger(string num, int k) {
        int n = num.length();
        queue<int> vec[K];
        
        for (int i = 0; i < n; i ++) {
            vec[ num[i] - '0' ].push(i);
        }
        
        string res = "";
        bool used[n];
        memset(used, false, sizeof(used));
        
        while (k > 0 && res.length() < n) {
            for (int i = 0; i <= 9; i ++) {
                if (vec[i].empty())
                    continue;
                
                int pos = vec[i].front();
                
                int cost = pos - query(pos + 1);
                if (cost > k)
                    continue;
                
                k -= cost;
                res += ('0' + i);
                
                update(pos + 1, 1);
                used[pos] = true;
                vec[i].pop();
                
                break;
            }
        }
                   
        for (int i = 0; i < n; i ++) {
            if (!used[i])
                res += num[i];
        }
        
        return res;
    }
};
