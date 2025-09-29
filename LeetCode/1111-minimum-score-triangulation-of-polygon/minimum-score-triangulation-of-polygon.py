class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        N = len(values)
        dp = [[0] * N for _ in range(N)]
        for start in reversed(range(N)):
            for end in range(start + 2, N):
                score = float(inf)
                for k in range(start + 1, end):
                    score = min(score, values[start] * values[k] * values[end] + dp[start][k] + dp[k][end])
                dp[start][end] = score
        return dp[0][N - 1]
        