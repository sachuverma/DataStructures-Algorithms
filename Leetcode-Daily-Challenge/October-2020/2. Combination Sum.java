class Solution {
    public List<List<Integer>> combinationSum(int[] can, int tar) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        some(0, can, tar, ans, temp, 0);
        return ans;
    }

    public static void some(int i, int[] can, int tar, List<List<Integer>> ans, List<Integer> temp, int sum) {
        if (sum == tar) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        if (i >= can.length) {
            return;
        }
        if (sum > tar)
            return;

        temp.add(can[i]);
        some(i, can, tar, ans, temp, sum + can[i]);
        temp.remove(temp.size() - 1);
        some(i + 1, can, tar, ans, temp, sum);
    }
}
