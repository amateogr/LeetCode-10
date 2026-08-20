#include <string>

class Solution {
public:
    bool squareIsWhite(const std::string& coordinates) {
        return (coordinates[0] + coordinates[1]) & 1;
    }
};