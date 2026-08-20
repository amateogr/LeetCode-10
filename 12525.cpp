#include <string>

class Solution {
public:
    std::string categorizeBox(int length, int width, int height, int mass) {
        const bool isBulky = (length >= 10000 || width >= 10000 || height >= 10000 || 
                              static_cast<long long>(length) * width * height >= 1000000000LL);
        const bool isHeavy = (mass >= 100);

        if (isBulky && isHeavy) return "Both";
        if (!isBulky && !isHeavy) return "Neither";
        if (isBulky) return "Bulky";
        return "Heavy";
    }
};