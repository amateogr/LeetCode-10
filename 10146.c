#include <stdlib.h>

typedef struct Node {
    int key;
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node* map[10001];
} LRUCache;

static inline void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

static inline void addToHead(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->head = (Node*)malloc(sizeof(Node));
    obj->tail = (Node*)malloc(sizeof(Node));
    obj->head->next = obj->tail;
    obj->head->prev = NULL;
    obj->tail->prev = obj->head;
    obj->tail->next = NULL;
    for (int i = 0; i <= 10000; i++) {
        obj->map[i] = NULL;
    }
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = obj->map[key];
    if (!node) return -1;
    removeNode(node);
    addToHead(obj, node);
    return node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = obj->map[key];
    if (node) {
        node->val = value;
        removeNode(node);
        addToHead(obj, node);
        return;
    }
    if (obj->size == obj->capacity) {
        Node* lru = obj->tail->prev;
        removeNode(lru);
        obj->map[lru->key] = NULL;
        free(lru);
        obj->size--;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = value;
    obj->map[key] = newNode;
    addToHead(obj, newNode);
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}