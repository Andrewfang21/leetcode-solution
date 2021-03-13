class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> encode;
        map<string, char> decode;

        vector<string> strings;
        istringstream iss(s);
        for (string ss; iss >> ss;)
            strings.push_back(ss);
        
        if (strings.size() != pattern.length())
            return false;
        
        for (int i = 0; i < pattern.length(); i ++) {
            if (encode.find(pattern[i]) == encode.end() &&
                decode.find(strings[i]) == decode.end()) {
                encode[pattern[i]] = strings[i];
                decode[strings[i]] = pattern[i];
            } else if (decode.find(strings[i]) != decode.end() &&
                       encode.find(pattern[i]) != encode.end()) {
                if (encode[pattern[i]] == strings[i] && decode[strings[i]] == pattern[i])
                    continue;
                else return false;
            } else return false;
        }
        return true;
    }
};