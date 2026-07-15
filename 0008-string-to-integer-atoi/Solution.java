class Solution {
    public int myAtoi(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        int n = s.length();
        int i = 0;
        
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        int sign = 1;
        char firstChar = s.charAt(i);
        if (firstChar == '-') {
            sign = -1;
            i++;
        } else if (firstChar == '+') {
            i++;
        }
        
        int res = 0;
        while (i < n && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i) - '0';
            
            if (res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && digit > 7)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            
            res = res * 10 + digit;
            i++;
        }
        
        return sign * res;
    }
}
