#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

class RandomizedCollection {
private:
    std::vector<int> nums;
    std::unordered_map<int, std::unordered_set<int>> idxMap;
    std::mt19937 rng;

public:
    RandomizedCollection() {
        rng.seed(std::random_device{}());
    }
    
    bool insert(int val) {
        bool notPresent = idxMap[val].empty();
        idxMap[val].insert(nums.size());
        nums.push_back(val);
        return notPresent;
    }
    
    bool remove(int val) {
        auto it = idxMap.find(val);
        if (it == idxMap.end() || it->second.empty()) {
            return false;
        }
        
        int removeIdx = *(it->second.begin());
        it->second.erase(removeIdx);
        
        int lastVal = nums.back();
        if (removeIdx != nums.size() - 1) {
            nums[removeIdx] = lastVal;
            idxMap[lastVal].erase(nums.size() - 1);
            idxMap[lastVal].insert(removeIdx);
        }
        
        nums.pop_back();
        if (it->second.empty()) {
            idxMap.erase(it);
        }
        
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<size_t> dist(0, nums.size() - 1);
        return nums[dist(rng)];
    }
};