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
