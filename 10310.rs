impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        if n <= 2 {
            return (0..n as i32).collect();
        }

        let mut adj = vec![vec![]; n];
        let mut degree = vec![0; n];

        for edge in edges {
            let u = edge[0] as usize;
            let v = edge[1] as usize;
            adj[u].push(v);
            adj[v].push(u);
            degree[u] += 1;
            degree[v] += 1;
        }

        let mut queue = std::collections::VecDeque::new();
        for i in 0..n {
            if degree[i] == 1 {
                queue.push_back(i);
            }
        }

        let mut remaining_nodes = n;
        while remaining_nodes > 2 {
            let len = queue.len();
            remaining_nodes -= len;
            for _ in 0..len {
                let u = queue.pop_front().unwrap();
                for &v in &adj[u] {
                    degree[v] -= 1;
                    if degree[v] == 1 {
                        queue.push_back(v);
                    }
                }
            }
        }

        queue.into_iter().map(|x| x as i32).collect()
    }
}