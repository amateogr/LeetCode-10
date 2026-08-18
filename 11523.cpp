class Solution {
public:
    int countOdds(int low, int high) noexcept {
        return ((high + 1) >> 1) - (low >> 1);
    }
};