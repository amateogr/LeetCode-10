import java.util.*;

class Solution {
    private record Event(int x, int height) implements Comparable<Event> {
        @Override
        public int compareTo(Event other) {
            if (this.x != other.x) {
                return Integer.compare(this.x, other.x);
            }
            return Integer.compare(this.height, other.height);
        }
    }

    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<Event> events = new ArrayList<>(buildings.length * 2);
        for (int[] b : buildings) {
            events.add(new Event(b[0], -b[2]));
            events.add(new Event(b[1], b[2]));
        }
        
        Collections.sort(events);
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        map.put(0, 1);
        int prevHeight = 0;
        
        List<List<Integer>> result = new ArrayList<>();
        
        for (Event e : events) {
            if (e.height < 0) {
                map.merge(-e.height, 1, Integer::sum);
            } else {
                map.compute(e.height, (k, v) -> v == 1 ? null : v - 1);
            }
            
            int currHeight = map.lastKey();
            if (currHeight != prevHeight) {
                result.add(List.of(e.x, currHeight));
                prevHeight = currHeight;
            }
        }
        
        return result;
    }
}