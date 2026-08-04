public class Solution {
    public IList<IList<int>> Permute(int[] nums) {
        var result = new List<IList<int>>();
        Backtrack(nums, new List<int>(), new bool[nums.Length], result);
        return result;
    }

    private void Backtrack(int[] nums, List<int> current, bool[] used, IList<IList<int>> result) {
        if (current.Count == nums.Length) {
            result.Add(new List<int>(current));
            return;
        }

        for (int i = 0; i < nums.Length; i++) {
            if (used[i]) continue;
            used[i] = true;
            current.Add(nums[i]);
            Backtrack(nums, current, used, result);
            current.RemoveAt(current.Count - 1);
            used[i] = false;
        }
    }
}