#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string ans = "1";
        
        for (int i = 1; i < n; ++i) {
            std::string next_ans = "";
            int count = 1;
            
            for (int j = 1; j < ans.length(); ++j) {
                if (ans[j] == ans[j - 1]) {
                    count++;
                } else {
                    next_ans += std::to_string(count) + ans[j - 1];
                    count = 1;
                }
            }
            
            next_ans += std::to_string(count) + ans.back();
            ans = next_ans;
        }
        
        return ans;
    }
};