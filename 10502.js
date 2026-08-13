var findMaximizedCapital = function(k, w, profits, capital) {
    class MaxHeap {
        constructor() {
            this.data = [];
        }
        push(val) {
            this.data.push(val);
            let i = this.data.length - 1;
            while (i > 0) {
                let p = (i - 1) >> 1;
                if (this.data[i] <= this.data[p]) break;
                let tmp = this.data[i];
                this.data[i] = this.data[p];
                this.data[p] = tmp;
                i = p;
            }
        }
        pop() {
            if (this.data.length === 0) return 0;
            let top = this.data[0];
            let bottom = this.data.pop();
            if (this.data.length > 0) {
                this.data[0] = bottom;
                let i = 0;
                let len = this.data.length;
                while ((i << 1) + 1 < len) {
                    let left = (i << 1) + 1;
                    let right = left + 1;
                    let maxIdx = i;
                    if (this.data[left] > this.data[maxIdx]) maxIdx = left;
                    if (right < len && this.data[right] > this.data[maxIdx]) maxIdx = right;
                    if (maxIdx === i) break;
                    let tmp = this.data[i];
                    this.data[i] = this.data[maxIdx];
                    this.data[maxIdx] = tmp;
                    i = maxIdx;
                }
            }
            return top;
        }
        isEmpty() {
            return this.data.length === 0;
        }
    }

    let n = profits.length;
    let indices = new Int32Array(n);
    for (let i = 0; i < n; i++) indices[i] = i;
    
    indices.sort((a, b) => capital[a] - capital[b]);
    
    let heap = new MaxHeap();
    let ptr = 0;
    
    for (let j = 0; j < k; j++) {
        while (ptr < n && capital[indices[ptr]] <= w) {
            heap.push(profits[indices[ptr]]);
            ptr++;
        }
        if (heap.isEmpty()) break;
        w += heap.pop();
    }
    
    return w;
};