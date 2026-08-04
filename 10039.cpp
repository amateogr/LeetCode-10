#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int target, int sum, int start, vector<int>& current, vector<vector<int>>& result) {
        if (sum == target) {
            result.push_back(current);
            return;
        }
        
        if (sum > target) {
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);
            backtrack(candidates, target, sum + candidates[i], i, current, result);
            current.pop_back();
        }
    }
};