#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
private:
    std::vector<int> nums;
    std::unordered_map<int, int> val_to_index;
    std::mt19937 rng;

public:
    RandomizedSet() {
        rng.seed(1337);
        nums.reserve(200000);
        val_to_index.reserve(200000);
    }
    
    bool insert(int val) {
        auto [it, inserted] = val_to_index.emplace(val, nums.size());
        if (!inserted) {
            return false;
        }
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = val_to_index.find(val);
        if (it == val_to_index.end()) {
            return false;
        }
        int idx = it->second;
        int last_val = nums.back();
        nums[idx] = last_val;
        val_to_index[last_val] = idx;
        nums.pop_back();
        val_to_index.erase(it);
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> dist(0, static_cast<int>(nums.size()) - 1);
        return nums[dist(rng)];
    }
};