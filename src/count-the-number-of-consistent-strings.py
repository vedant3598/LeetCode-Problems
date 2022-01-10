class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        count = 0
        arr = list()
        start = 97
        for i in range(0, 26):
            arr.append(0)
            
        for i, c in enumerate(allowed):
            index = ord(c) - start
            arr[index] = 1
            
        for word in words: 
            allow = True
            for i, c in enumerate(word):
                num = ord(c) - start
                if arr[num] == 0:
                    allow = False
                    break
            if allow == True:
                count += 1
        return count
