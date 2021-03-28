class Solution {
public:
    int consecutiveNumbersSum(int N) {
        double upperBound = sqrt(2 * N);
        int answer = 0;
        for (int i = 1; i < upperBound; i ++) {
            int currNum = N - (i * (i - 1) / 2);
            if (currNum % i == 0)
                answer ++;
        }
        
        return answer;
    }
};
