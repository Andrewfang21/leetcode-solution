class Solution {
public:
    struct state {
        string s;
        int count;
    };
    struct order {
        bool operator() (state const &a, state const &b) {
            return a.count == b.count ? a.s > b.s : a.count < b.count;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mapper;
        for (string word : words)
            mapper[word] ++;
        
        priority_queue<state, vector<state>, order> q;
        for (const auto &it : mapper)
            q.push(state{it.first, it.second});
        
        vector<string> res;
        while (k --) {
            res.push_back(q.top().s);   
            q.pop();
        }
        return res;
    }
};