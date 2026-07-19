from collections import Counter

class Solution:
    def findSubstring(self, s: str, words: list[str]) -> list[int]:
        if not s or not words:
            return []
            
        word_len = len(words[0])
        word_count = len(words)
        total_len = word_len * word_count
        s_len = len(s)
        
        if s_len < total_len:
            return []
            
        word_freq = Counter(words)
        result = []
        
        # Run sliding window for each starting offset [0, word_len)
        for i in range(word_len):
            left = i
            right = i
            seen = {}
            words_used = 0
            
            while right + word_len <= s_len:
                word = s[right : right + word_len]
                right += word_len
                
                if word in word_freq:
                    seen[word] = seen.get(word, 0) + 1
                    words_used += 1
                    
                    # If we have seen this word more times than it appears in words,
                    # shrink the window from the left until seen[word] <= word_freq[word]
                    while seen[word] > word_freq[word]:
                        left_word = s[left : left + word_len]
                        seen[left_word] -= 1
                        words_used -= 1
                        left += word_len
                        
                    # If the number of words matches, we found a valid starting index
                    if words_used == word_count:
                        result.append(left)
                else:
                    # Reset the window if the word is not in words
                    seen.clear()
                    words_used = 0
                    left = right
                    
        return result
