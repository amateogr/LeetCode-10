class CustomMinHeap {
    constructor() {
        this.heap = [];
    }

    size() {
        return this.heap.length;
    }

    push(val) {
        this.heap.push(val);
        this._up(this.heap.length - 1);
    }

    pop() {
        if (this.size() === 0) return null;
        const top = this.heap[0];
        const bottom = this.heap.pop();
        if (this.size() > 0) {
            this.heap[0] = bottom;
            this._down(0);
        }
        return top;
    }

    _up(i) {
        while (i > 0) {
            let p = (i - 1) >> 1;
            if (this.heap[i][0] < this.heap[p][0]) {
                [this.heap[i], this.heap[p]] = [this.heap[p], this.heap[i]];
                i = p;
            } else {
                break;
            }
        }
    }

    _down(i) {
        let last = this.heap.length - 1;
        while ((i << 1) + 1 <= last) {
            let left = (i << 1) + 1;
            let right = left + 1;
            let small = left;
            if (right <= last && this.heap[right][0] < this.heap[left][0]) {
                small = right;
            }
            if (this.heap[small][0] < this.heap[i][0]) {
                [this.heap[i], this.heap[small]] = [this.heap[small], this.heap[i]];
                i = small;
            } else {
                break;
            }
        }
    }
}

function smallestRange(nums) {
    const minHeap = new CustomMinHeap();
    let maxVal = -Infinity;
    let rangeStart = 0;
    let rangeEnd = Infinity;

    for (let i = 0; i < nums.length; i++) {
        minHeap.push([nums[i][0], i, 0]);
        maxVal = Math.max(maxVal, nums[i][0]);
    }

    while (true) {
        const [minVal, r, c] = minHeap.pop();

        if (maxVal - minVal < rangeEnd - rangeStart) {
            rangeStart = minVal;
            rangeEnd = maxVal;
        }

        if (c + 1 === nums[r].length) {
            break;
        }

        const nextVal = nums[r][c + 1];
        minHeap.push([nextVal, r, c + 1]);
        maxVal = Math.max(maxVal, nextVal);
    }

    return [rangeStart, rangeEnd];
}