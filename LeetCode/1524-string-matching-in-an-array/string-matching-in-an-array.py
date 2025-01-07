class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        s = ' '.join(words)
        result = []
        for word in words:
            if s.count(word) > 1:
                result.append(word)
        return result
        