class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        for (int i = 0; i < difficulty.size(); i ++)
            jobs.emplace_back(profit[i], difficulty[i]);
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int jobsPtr = jobs.size() - 1, workerPtr = worker.size() - 1;
        while (jobsPtr >= 0 && workerPtr >= 0) {
            while (jobsPtr >= 0 && worker[workerPtr] < jobs[jobsPtr].second)
                jobsPtr --;
            if (jobsPtr < 0)
                break;
            
            maxProfit += jobs[jobsPtr].first;
            workerPtr --;
        }
        
        return maxProfit;
    }
};