#include <stdlib.h>

typedef struct {
    int *heap;
    int k;
    int size;
} KthLargest;

int kthLargestAdd(KthLargest* obj, int val);

static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void sift_up(int *heap, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p] > heap[i]) {
            swap(&heap[p], &heap[i]);
            i = p;
        } else {
            break;
        }
    }
}

static void sift_down(int *heap, int size, int i) {
    while ((2 * i + 1) < size) {
        int left = 2 * i + 1;
        int right = left + 1;
        int smallest = i;

        if (heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest *obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->heap = (int*)malloc(k * sizeof(int));
    obj->size = 0;

    for (int i = 0; i < numsSize; i++) {
        kthLargestAdd(obj, nums[i]);
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        sift_up(obj->heap, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        sift_down(obj->heap, obj->size, 0);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    if (obj) {
        free(obj->heap);
        free(obj);
    }
}