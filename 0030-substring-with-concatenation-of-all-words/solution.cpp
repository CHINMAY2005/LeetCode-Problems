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
