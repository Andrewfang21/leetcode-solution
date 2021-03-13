class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        int latest = -1; 
        vector<int> answer;
        for (int i = 0; i < nums.size(); i ++) {
            q.emplace(nums[i], i);
            if (nums.size() - i == k) {
                while (true) {
                    pair<int,int> smallest = q.top();
                    q.pop();
                    if (latest < smallest.second) {
                        latest = smallest.second;
                        answer.push_back(smallest.first);
                        k --;
                        break;
                    } else continue;
                }
            }
        }
        
        return answer;
    }
};