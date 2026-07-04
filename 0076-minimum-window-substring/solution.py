class Solution:
    def minWindow(self, s, t):
        if not t:
            return ''

        need = {}
        for char in t:
            need[char] = need.get(char, 0) + 1

        have = {}
        formed = 0
        required = len(need)
        left = 0
        best = (float('inf'), 0, 0)

        for right, char in enumerate(s):
            have[char] = have.get(char, 0) + 1
            if char in need and have[char] == need[char]:
                formed += 1

            while formed == required:
                if right - left + 1 < best[0]:
                    best = (right - left + 1, left, right)

                left_char = s[left]
                have[left_char] -= 1
                if left_char in need and have[left_char] < need[left_char]:
                    formed -= 1
                left += 1

        return '' if best[0] == float('inf') else s[best[1]:best[2] + 1]