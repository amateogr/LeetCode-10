var scheduleCourse = function(courses) {
    courses.sort((a, b) => a[1] - b[1]);
    
    const heap = new Uint32Array(courses.length);
    let size = 0;
    let time = 0;

    for (let i = 0; i < courses.length; i++) {
        const duration = courses[i][0];
        const lastDay = courses[i][1];

        time += duration;
        heap[size] = duration;
        let curr = size;
        size++;

        while (curr > 0) {
            const parent = (curr - 1) >> 1;
            if (heap[curr] > heap[parent]) {
                const temp = heap[curr];
                heap[curr] = heap[parent];
                heap[parent] = temp;
                curr = parent;
            } else {
                break;
            }
        }

        if (time > lastDay) {
            const max = heap[0];
            size--;
            heap[0] = heap[size];
            let idx = 0;

            while ((idx << 1) + 1 < size) {
                let left = (idx << 1) + 1;
                let right = left + 1;
                let largest = idx;

                if (heap[left] > heap[largest]) largest = left;
                if (right < size && heap[right] > heap[largest]) largest = right;

                if (largest !== idx) {
                    const temp = heap[idx];
                    heap[idx] = heap[largest];
                    heap[largest] = temp;
                    idx = largest;
                } else {
                    break;
                }
            }
            time -= max;
        }
    }

    return size;
};