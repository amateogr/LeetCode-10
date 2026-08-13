const findMinStep = (board, hand) => {
    const clean = (s) => {
        let changed = true;
        while (changed) {
            changed = false;
            for (let i = 0; i < s.length; i++) {
                let j = i;
                while (j < s.length && s[j] === s[i]) j++;
                if (j - i >= 3) {
                    s = s.slice(0, i) + s.slice(j);
                    changed = true;
                    break;
                }
            }
        }
        return s;
    };

    hand = hand.split('').sort().join('');
    let queue = [[board, hand]];
    let visited = new Set([`${board},${hand}`]);
    let steps = 0;

    while (queue.length > 0) {
        let nextQueue = [];
        
        for (let [b, h] of queue) {
            if (b === '') return steps;

            for (let i = 0; i < h.length; i++) {
                if (i > 0 && h[i] === h[i - 1]) continue;
                let color = h[i];
                let nextHand = h.slice(0, i) + h.slice(i + 1);

                for (let j = 0; j <= b.length; j++) {
                    let canInsert = false;
                    
                    if (j < b.length && b[j] === color) {
                        if (j === 0 || b[j - 1] !== color) {
                            canInsert = true;
                        }
                    } else if (j > 0 && j < b.length && b[j - 1] === b[j] && b[j] !== color) {
                        canInsert = true;
                    }

                    if (!canInsert) continue;

                    let nextBoard = clean(b.slice(0, j) + color + b.slice(j));
                    let stateKey = `${nextBoard},${nextHand}`;

                    if (!visited.has(stateKey)) {
                        visited.add(stateKey);
                        nextQueue.push([nextBoard, nextHand]);
                    }
                }
            }
        }
        queue = nextQueue;
        steps++;
    }
    
    return -1;
};