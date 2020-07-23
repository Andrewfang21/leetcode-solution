class Solution {
public:
    string frequencySort(string s) {
        typedef pair<int, char> ii;
        map<char, int> mapper;
        priority_queue<ii, vector<ii>> q;
        for (char c : s)
            mapper[c] ++;
        
        for (const auto &it : mapper) {
            cout << it.first << ": " << it.second << "\n";
            q.push(make_pair(it.second, it.first));
        }
        string res = "";
        while (!q.empty()) {
            ii curr = q.top();
            q.pop();
            while (curr.first --)
                res += curr.second;
        }
        return res;
    }
};