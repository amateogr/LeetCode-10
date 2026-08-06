#include <stdlib.h>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a < 0 ? -a : a;
}

typedef struct {
    int dx;
    int dy;
} Slope;

int compare(const void* a, const void* b) {
    Slope* s1 = (Slope*)a;
    Slope* s2 = (Slope*)b;
    if (s1->dx != s2->dx) return s1->dx - s2->dx;
    return s1->dy - s2->dy;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) return pointsSize;
    int max_pts = 0;
    Slope* slopes = (Slope*)malloc(sizeof(Slope) * pointsSize);

    for (int i = 0; i < pointsSize; i++) {
        int count = 0;
        int duplicates = 1;
        int current_max = 0;
        
        for (int j = 0; j < pointsSize; j++) {
            if (i == j) continue;
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            if (dx == 0 && dy == 0) {
                duplicates++;
                continue;
            }
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            slopes[count].dx = dx;
            slopes[count].dy = dy;
            count++;
        }

        if (count > 0) {
            qsort(slopes, count, sizeof(Slope), compare);
            int local_max = 1;
            int current_count = 1;
            for (int j = 1; j < count; j++) {
                if (slopes[j].dx == slopes[j-1].dx && slopes[j].dy == slopes[j-1].dy) {
                    current_count++;
                } else {
                    if (current_count > local_max) local_max = current_count;
                    current_count = 1;
                }
            }
            if (current_count > local_max) local_max = current_count;
            current_max = local_max + duplicates;
        } else {
            current_max = duplicates;
        }

        if (current_max > max_pts) {
            max_pts = current_max;
        }
    }

    free(slopes);
    return max_pts;
}