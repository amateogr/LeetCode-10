class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] head = new int[numCourses];
        java.util.Arrays.fill(head, -1);
        int E = prerequisites.length;
        int[] next = new int[E];
        int[] to = new int[E];
        int[] indegree = new int[numCourses];
        
        for (int i = 0; i < E; i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            to[i] = v;
            next[i] = head[u];
            head[u] = i;
            indegree[v]++;
        }
        
        int[] queue = new int[numCourses];
        int qHead = 0, qTail = 0;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                queue[qTail++] = i;
            }
        }
        
        int[] order = new int[numCourses];
        int idx = 0;
        while (qHead < qTail) {
            int curr = queue[qHead++];
            order[idx++] = curr;
            for (int e = head[curr]; e != -1; e = next[e]) {
                int v = to[e];
                if (--indegree[v] == 0) {
                    queue[qTail++] = v;
                }
            }
        }
        
        return idx == numCourses ? order : new int[0];
    }
}