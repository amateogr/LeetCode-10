#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long long sum;
    int i;
    int j;
} Node;

typedef struct {
    Node* data;
    int size;
    int capacity;
} MinHeap;

static MinHeap* createHeap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->data = (Node*)malloc(capacity * sizeof(Node));
    h->size = 0;
    h->capacity = capacity;
    return h;
}

static void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

static void push(MinHeap* h, long long sum, int i, int j) {
    if (h->size >= h->capacity) {
        h->capacity *= 2;
        h->data = (Node*)realloc(h->data, h->capacity * sizeof(Node));
    }
    int curr = h->size++;
    h->data[curr] = (Node){sum, i, j};
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (h->data[parent].sum > h->data[curr].sum) {
            swap(&h->data[parent], &h->data[curr]);
            curr = parent;
        } else {
            break;
        }
    }
}

static Node pop(MinHeap* h) {
    Node root = h->data[0];
    h->data[0] = h->data[--h->size];
    int curr = 0;
    while (true) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int smallest = curr;
        if (left < h->size && h->data[left].sum < h->data[smallest].sum) smallest = left;
        if (right < h->size && h->data[right].sum < h->data[smallest].sum) smallest = right;
        if (smallest != curr) {
            swap(&h->data[curr], &h->data[smallest]);
            curr = smallest;
        } else {
            break;
        }
    }
    return root;
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0 || k == 0) return NULL;

    int initial_cap = k < nums1Size ? k : nums1Size;
    MinHeap* h = createHeap(initial_cap + 1);

    for (int i = 0; i < nums1Size && i < k; i++) {
        push(h, (long long)nums1[i] + nums2[0], i, 0);
    }

    int** result = (int**)malloc(k * sizeof(int*));
    *returnColumnSizes = (int*)malloc(k * sizeof(int));

    int count = 0;
    while (h->size > 0 && count < k) {
        Node node = pop(h);
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = nums1[node.i];
        result[count][1] = nums2[node.j];
        (*returnColumnSizes)[count] = 2;
        count++;

        if (node.j + 1 < nums2Size) {
            push(h, (long long)nums1[node.i] + nums2[node.j + 1], node.i, node.j + 1);
        }
    }

    *returnSize = count;
    free(h->data);
    free(h);
    return result;
}