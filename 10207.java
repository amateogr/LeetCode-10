class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        List<Integer>[] adj = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] p : prerequisites) {
            adj[p[1]].add(p[0]);
            indegree[p[0]]++;
        }
        Queue<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue.offer(i);
            }
        }
        int processed = 0;
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            processed++;
            for (int next : adj[curr]) {
                if (--indegree[next] == 0) {
                    queue.offer(next);
                }
            }
        }
        return processed == numCourses;
    }
}