class Solution {
public:
    bool backspaceCompare(string S, string T) {
        deque<char> x, y;
        for (char s : S) {
            if (s != '#')   x.push_back(s);
            if (s == '#' && !x.empty())     x.pop_back();
        }
        for (char t : T) {
            if (t != '#')   y.push_back(t);
            if (t == '#' && !y.empty())     y.pop_back();
        }
        
        return x == y;
    }
};