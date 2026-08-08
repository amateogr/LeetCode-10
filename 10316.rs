impl Solution {
    pub fn remove_duplicate_letters(s: String) -> String {
        let bytes = s.as_bytes();
        let mut last = [0; 26];
        for (i, &b) in bytes.iter().enumerate() {
            last[(b - b'a') as usize] = i;
        }
        let mut stack: Vec<u8> = Vec::with_capacity(26);
        let mut visited = [false; 26];
        for (i, &b) in bytes.iter().enumerate() {
            let idx = (b - b'a') as usize;
            if visited[idx] {
                continue;
            }
            while let Some(&top) = stack.last() {
                let top_idx = (top - b'a') as usize;
                if top > b && last[top_idx] > i {
                    visited[top_idx] = false;
                    stack.pop();
                } else {
                    break;
                }
            }
            stack.push(b);
            visited[idx] = true;
        }
        String::from_utf8(stack).unwrap()
    }
}