class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowToSeats;
        rowToSeats.reserve(reservedSeats.size());
        for (const auto& seat : reservedSeats) {
            rowToSeats[seat[0]] |= (1 << (seat[1] - 1));
        }
        int ans = 0;
        const int leftMask = 0x1E;
        const int midMask = 0x78;
        const int rightMask = 0x1E0;
        const int bothMask = 0x1FE;

        for (const auto& [row, seats] : rowToSeats) {
            if ((seats & bothMask) == 0) {
                ans += 2;
            } else if ((seats & leftMask) == 0 || (seats & midMask) == 0 || (seats & rightMask) == 0) {
                ans += 1;
            }
        }
        return ans + (n - rowToSeats.size()) * 2;
    }
};