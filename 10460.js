const LFUCache = (() => {
    class Node {
        constructor(key, val) {
            this.key = key;
            this.val = val;
            this.freq = 1;
            this.prev = null;
            this.next = null;
        }
    }

    class DoublyLinkedList {
        constructor() {
            this.head = new Node(0, 0);
            this.tail = new Node(0, 0);
            this.head.next = this.tail;
            this.tail.prev = this.head;
            this.size = 0;
        }

        addNode(node) {
            let nextNode = this.head.next;
            this.head.next = node;
            node.prev = this.head;
            node.next = nextNode;
            nextNode.prev = node;
            this.size++;
        }

        removeNode(node) {
            let prevNode = node.prev;
            let nextNode = node.next;
            prevNode.next = nextNode;
            nextNode.prev = prevNode;
            this.size--;
        }

        removeTail() {
            if (this.size === 0) return null;
            let node = this.tail.prev;
            this.removeNode(node);
            return node;
        }
    }

    return class {
        constructor(capacity) {
            this.capacity = capacity;
            this.minFreq = 0;
            this.keyMap = new Map();
            this.freqMap = new Map();
        }

        get(key) {
            if (!this.keyMap.has(key)) return -1;
            let node = this.keyMap.get(key);
            this.updateFreq(node);
            return node.val;
        }

        put(key, value) {
            if (this.capacity <= 0) return;
            if (this.keyMap.has(key)) {
                let node = this.keyMap.get(key);
                node.val = value;
                this.updateFreq(node);
                return;
            }
            if (this.keyMap.size >= this.capacity) {
                let list = this.freqMap.get(this.minFreq);
                let nodeToRemove = list.removeTail();
                this.keyMap.delete(nodeToRemove.key);
            }
            let newNode = new Node(key, value);
            this.keyMap.set(key, newNode);
            this.minFreq = 1;
            let list = this.freqMap.get(1) || new DoublyLinkedList();
            list.addNode(newNode);
            this.freqMap.set(1, list);
        }

        updateFreq(node) {
            let freq = node.freq;
            let list = this.freqMap.get(freq);
            list.removeNode(node);
            if (freq === this.minFreq && list.size === 0) {
                this.minFreq++;
            }
            node.freq++;
            let nextList = this.freqMap.get(node.freq) || new DoublyLinkedList();
            nextList.addNode(node);
            this.freqMap.set(node.freq, nextList);
        }
    };
})();