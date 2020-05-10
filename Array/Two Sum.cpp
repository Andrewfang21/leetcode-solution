class Solution {
public:
    map<int, int> occur;
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        bool finish = false;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (finish)
                break;
            
            for (int j = i + 1; j < nums.size(); j ++) {
                if (finish)
                    break;
                
                if (target == nums[i] + nums[j]) {              
                    res.push_back(i);
                    res.push_back(j);
                    
                    finish = true;
                }
            }
        }
        return res;
    }
};