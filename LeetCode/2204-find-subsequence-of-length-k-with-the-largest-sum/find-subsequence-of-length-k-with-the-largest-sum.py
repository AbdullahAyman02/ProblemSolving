class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        vals = [[i, nums[i]] for i in range(length)]
        vals.sort(key = lambda x : -x[1])
        vals = sorted(vals[:k])
        result = [val for idx, val in vals]
        return result
        