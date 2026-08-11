#include <string>
#include <unordered_map>
#include <unordered_set>
#include <list>

class AllOne {
private:
    struct Node {
        int count;
        std::unordered_set<std::string> keys;
        Node(int c) : count(c) {}
    };

    std::list<Node> lst;
    std::unordered_map<std::string, std::list<Node>::iterator> keyMap;

public:
    AllOne() {}

    void inc(std::string key) {
        if (keyMap.find(key) == keyMap.end()) {
            if (lst.empty() || lst.front().count > 1) {
                lst.push_front(Node(1));
            }
            lst.front().keys.insert(key);
            keyMap[key] = lst.begin();
        } else {
            auto curr = keyMap[key];
            int nextCount = curr->count + 1;
            auto nextIt = std::next(curr);

            if (nextIt == lst.end() || nextIt->count > nextCount) {
                nextIt = lst.insert(nextIt, Node(nextCount));
            }

            nextIt->keys.insert(key);
            keyMap[key] = nextIt;
            curr->keys.erase(key);

            if (curr->keys.empty()) {
                lst.erase(curr);
            }
        }
    }

    void dec(std::string key) {
        auto curr = keyMap[key];
        int prevCount = curr->count - 1;

        if (prevCount == 0) {
            keyMap.erase(key);
            curr->keys.erase(key);
        } else {
            auto prevIt = (curr == lst.begin()) ? lst.end() : std::prev(curr);

            if (curr == lst.begin() || prevIt->count < prevCount) {
                prevIt = lst.insert(curr, Node(prevCount));
            }

            prevIt->keys.insert(key);
            keyMap[key] = prevIt;
            curr->keys.erase(key);
        }

        if (curr->keys.empty()) {
            lst.erase(curr);
        }
    }

    std::string getMaxKey() {
        if (lst.empty()) return "";
        return *(lst.back().keys.begin());
    }

    std::string getMinKey() {
        if (lst.empty()) return "";
        return *(lst.front().keys.begin());
    }
};