class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        alphabet = dict()
        i = 0
        for character in order:
            alphabet[character] = i
            i += 1
            
        first = 0
        
        for x in range(0, len(words) - 1):
            for y in range(len(words[x])):
                if y >= len(words[x + 1]):
                    return False
                if words[x][y] != words[x+1][y]:
                    if alphabet[words[x][y]] > alphabet[words[x+1][y]]:
                        return False
                    break
    
        return True
