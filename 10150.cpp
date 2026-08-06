#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::vector<int> st;
        st.reserve(tokens.size() / 2 + 1);
        for (const auto& t : tokens) {
            if (t.size() > 1 || std::isdigit(t[0])) {
                st.push_back(std::stoi(t));
            } else {
                int b = st.back();
                st.pop_back();
                int a = st.back();
                st.pop_back();
                switch (t[0]) {
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    case '/': st.push_back(a / b); break;
                }
            }
        }
        return st.back();
    }
};