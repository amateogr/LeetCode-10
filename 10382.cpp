#include <vector>
#include <random>

class Solution {
    std::vector<ListNode*> nodes;
    std::mt19937 rng;

public:
    Solution(ListNode* head) : rng(std::random_device{}()) {
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
    }
    
    int getRandom() {
        std::uniform_int_distribution<size_t> dist(0, nodes.size() - 1);
        return nodes[dist(rng)]->val;
    }
};