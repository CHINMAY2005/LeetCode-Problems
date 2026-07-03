class Solution:
    def isValid(self, s):
        stack = []
        pairs = {')': '(', ']': '[', '}': '{'}

        for char in s:
            if char in pairs.values():
                stack.append(char)
            else:
                if not stack or stack.pop() != pairs[char]:
                    return False

        return not stack