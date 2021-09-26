"""
# Definition for a Node.
class Node(object):
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        oldNew = {}
        def clone(node):
            if node in oldNew:
                return oldNew[node]
            
            new = Node(node.val)
            oldNew[node] = new
            for neighbor in node.neighbors:
                new.neighbors.append(clone(neighbor))
                
            return new
        
        if node:
            return clone(node)
        else:
            return None
