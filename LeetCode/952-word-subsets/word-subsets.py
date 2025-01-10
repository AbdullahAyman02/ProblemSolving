class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        def max_freq(word):
            frequencies = [0] * 26
            for letter in word:
                frequencies[ord(letter) - ord('a')] += 1
            return frequencies
        
        word2 = [0] * 26
        for word in words2:
            for i, c in enumerate(max_freq(word)):
                word2[i] = max(word2[i], c)
        
        result = []
        for word in words1:
            if all(count >= max_freq for count, max_freq in zip(max_freq(word), word2)):
                result.append(word)
        return result
        