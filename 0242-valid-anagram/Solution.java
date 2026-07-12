import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (!counts.containsKey(c)) {
                return false;
            }

            counts.put(c, counts.get(c) - 1);
            if (counts.get(c) == 0) {
                counts.remove(c);
            }
        }

        return counts.isEmpty();
    }
}