# 0030 - Substring with Concatenation of All Words

## Problem
You are given a string `s` and an array of strings `words`. All the strings of `words` are of the same length.

A concatenated substring in `s` is a substring that contains all the strings of any permutation of `words` concatenated.

Return the starting indices of all concatenated substrings in `s`. You can return the answer in any order.

## Key Insight
Since all words have the same length (let's call it `wordLen`), we can view the string `s` as a sequence of words rather than a sequence of characters. By running a sliding window with a step size of `wordLen`, we can find all valid concatenations. To cover all alignments, we run the sliding window `wordLen` times, starting at indices from `0` to `wordLen - 1`.

## Approach
1. Return empty if `s` is empty or `words` is empty.
2. Initialize parameters:
   - `wordLen`: length of a single word in `words`.
   - `wordCount`: number of words in `words`.
   - `totalLen`: `wordLen * wordCount` (length of the concatenated substring).
3. Compute the frequency map of words in `words` (`wordFreq`).
4. Iterate `i` from `0` to `wordLen - 1`:
   - Initialize two pointers `left = i` and `right = i` to represent the window bounds.
   - Maintain a frequency map `seen` for words encountered in the current window.
   - Maintain `wordsUsed` to count valid words in the window.
   - While `right + wordLen <= s.length()`:
     - Extract the next word at `right`: `word = s.substring(right, right + wordLen)`.
     - Increment `right` by `wordLen`.
     - If `word` is in `wordFreq`:
       - Record it in `seen` and increment `wordsUsed`.
       - If `seen[word] > wordFreq[word]`, shrink the window from the `left` (increment `left` by `wordLen`, decrement counts) until the occurrence of `word` matches its frequency in `words`.
       - If `wordsUsed == wordCount`, record `left` as a valid starting index.
     - Else (the word is invalid):
       - Reset the window: clear `seen`, set `wordsUsed = 0`, and slide `left` to `right`.
5. Return the list of starting indices.

## Why It Works
Running the sliding window `wordLen` times covers all possible character offsets. Shifting indices by `wordLen` instead of 1 reduces character comparisons drastically. Over-allocation of a word triggers window shrinking from the left, ensuring we maintain a linear runtime complexity.

## Complexity
- Time: `O(wordLen * N)` where `N` is the length of string `s`. The string is parsed in `wordLen` passes, and in each pass, each character is visited at most twice (once by `right` and once by `left`).
- Space: `O(M * L)` where `M` is the number of words and `L` is the length of each word, used to store word frequency maps.

## Python
```python
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
```

## Java
```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }
        
        int wordLen = words[0].length();
        int wordCount = words.length;
        int totalLen = wordLen * wordCount;
        int sLen = s.length();
        
        if (sLen < totalLen) {
            return result;
        }
        
        Map<String, Integer> wordFreq = new HashMap<>();
        for (String word : words) {
            wordFreq.put(word, wordFreq.getOrDefault(word, 0) + 1);
        }
        
        // Run sliding window for each starting offset [0, wordLen)
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            Map<String, Integer> seen = new HashMap<>();
            int wordsUsed = 0;
            
            while (right + wordLen <= sLen) {
                String word = s.substring(right, right + wordLen);
                right += wordLen;
                
                if (wordFreq.containsKey(word)) {
                    seen.put(word, seen.getOrDefault(word, 0) + 1);
                    wordsUsed++;
                    
                    while (seen.get(word) > wordFreq.get(word)) {
                        String leftWord = s.substring(left, left + wordLen);
                        seen.put(leftWord, seen.get(leftWord) - 1);
                        wordsUsed--;
                        left += wordLen;
                    }
                    
                    if (wordsUsed == wordCount) {
                        result.add(left);
                    }
                } else {
                    seen.clear();
                    wordsUsed = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
}
```

## C++
```cpp
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) {
            return result;
        }
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();
        
        if (sLen < totalLen) {
            return result;
        }
        
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        // Run sliding window for each starting offset [0, wordLen)
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            unordered_map<string, int> seen;
            int wordsUsed = 0;
            
            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordFreq.count(word)) {
                    seen[word]++;
                    wordsUsed++;
                    
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        wordsUsed--;
                        left += wordLen;
                    }
                    
                    if (wordsUsed == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    seen.clear();
                    wordsUsed = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
```
