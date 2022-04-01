class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        courseList = { i : [] for i in range(numCourses)}
        
        for course, pre in prerequisites:
            courseList[pre].append(course)
            
        visited = set()
        
        def dfs(course):
            if course in visited:
                return False
            if courseList[course] == []:
                return True
            
            visited.add(course)
            for prereq in courseList[course]:
                if not dfs(prereq):
                    return False
            
            visited.remove(course)
            courseList[course] = []
            return True
        
        for course in range(numCourses):
            if not dfs(course):
                return False
            
        return True
