class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> adj[words.size()];
        unordered_map<int, int> inDeg;
        unordered_map<string, int> wordMapper;
        unordered_map<int, string> IDMapper;
        set<string> contain;
        for (int i = 0; i < words.size(); i ++) {
            contain.insert(words[i]);
            if (wordMapper.find(words[i]) == wordMapper.end()) {
                wordMapper[words[i]] = contain.size() - 1;
                IDMapper[contain.size() - 1] = words[i];
            }
        }
        
        for (string word : words) {
            for (int i = 0; i < word.length(); i ++) {
                string left = (i == 0) ? "" : word.substr(0, i);
                string right = (i == word.length() - 1) ? "" : word.substr(i + 1, word.length() - i - 1);
                string nxt = left + right;
                if (contain.find(nxt) != contain.end()) {
                    int from = wordMapper[word];
                    int to = wordMapper[nxt];
                    adj[from].push_back(to);
                    inDeg[to] ++;
                }
            }
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (const auto &w : wordMapper) {
            int id = wordMapper[w.first];
            if (inDeg[id] == 0)
                q.emplace(1, id);
        }
        
        int ans = 0;
        unordered_map<int, int> visited;
        while (!q.empty()) {
            pair<int,int> curr = q.top();
            q.pop();
                        
            visited[curr.second] = curr.first;
            ans = max(ans, curr.first);
            for (int nxt : adj[curr.second]) {
                if (visited.find(nxt) == visited.end() ||
                    visited.find(nxt) != visited.end() && visited[nxt] < curr.first + 1) {
                        q.emplace(curr.first + 1, nxt);
                }
            }
        }
        
        return ans;
    }
};