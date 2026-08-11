import java.util.*;

class Twitter {
    private static int timestamp = 0;

    private static class Tweet {
        int id;
        int time;
        Tweet next;

        Tweet(int id, int time) {
            this.id = id;
            this.time = time;
            this.next = null;
        }
    }

    private final Map<Integer, Tweet> tweetMap;
    private final Map<Integer, Set<Integer>> followingMap;

    public Twitter() {
        this.tweetMap = new HashMap<>();
        this.followingMap = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {
        Tweet t = new Tweet(tweetId, timestamp++);
        t.next = tweetMap.get(userId);
        tweetMap.put(userId, t);
    }

    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();
        PriorityQueue<Tweet> pq = new PriorityQueue<>((a, b) -> b.time - a.time);

        if (tweetMap.containsKey(userId)) {
            pq.offer(tweetMap.get(userId));
        }

        Set<Integer> followees = followingMap.get(userId);
        if (followees != null) {
            for (int followeeId : followees) {
                Tweet t = tweetMap.get(followeeId);
                if (t != null) {
                    pq.offer(t);
                }
            }
        }

        int count = 0;
        while (!pq.isEmpty() && count < 10) {
            Tweet t = pq.poll();
            res.add(t.id);
            count++;
            if (t.next != null) {
                pq.offer(t.next);
            }
        }

        return res;
    }

    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followingMap.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (!followingMap.containsKey(followerId)) return;
        followingMap.get(followerId).remove(followeeId);
    }
}