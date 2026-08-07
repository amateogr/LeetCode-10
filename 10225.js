class MyStack {
    constructor() {
        this.q = [];
    }

    push(x) {
        this.q.push(x);
        let n = this.q.length;
        while (--n > 0) {
            this.q.push(this.q.shift());
        }
    }

    pop() {
        return this.q.shift();
    }

    top() {
        return this.q[0];
    }

    empty() {
        return this.q.length === 0;
    }
}