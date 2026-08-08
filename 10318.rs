impl Solution {
    pub fn max_product(words: Vec<String>) -> i32 {
        let mut items = Vec::with_capacity(words.len());
        for w in words {
            let mut mask = 0;
            for b in w.bytes() {
                mask |= 1 << (b - b'a');
            }
            items.push((mask, w.len() as i32));
        }

        let mut max_val = 0;
        let n = items.len();
        for i in 0..n {
            for j in (i + 1)..n {
                if (items[i].0 & items[j].0) == 0 {
                    let prod = items[i].1 * items[j].1;
                    if prod > max_val {
                        max_val = prod;
                    }
                }
            }
        }
        max_val
    }
}