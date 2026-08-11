import java.util.Map;
import java.util.TreeMap;

class SummaryRanges {
    private final TreeMap<Integer, Integer> map;

    public SummaryRanges() {
        this.map = new TreeMap<>();
    }

    public void addNum(int val) {
        Integer lo = map.floorKey(val);
        if (lo != null && map.get(lo) >= val) {
            return;
        }

        Integer hi = map.ceilingKey(val);
        boolean mergeLo = (lo != null && map.get(lo) + 1 == val);
        boolean mergeHi = (hi != null && hi - 1 == val);

        if (mergeLo && mergeHi) {
            map.put(lo, map.get(hi));
            map.remove(hi);
        } else if (mergeLo) {
            map.put(lo, val);
        } else if (mergeHi) {
            map.put(val, map.get(hi));
            map.remove(hi);
        } else {
            map.put(val, val);
        }
    }

    public int[][] getIntervals() {
        int[][] result = new int[map.size()][2];
        int i = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            result[i][0] = entry.getKey();
            result[i][1] = entry.getValue();
            i++;
        }
        return result;
    }
}