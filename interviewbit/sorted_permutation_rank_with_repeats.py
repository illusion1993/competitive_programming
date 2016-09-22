class Solution:
    # @param A : string
    # @return an integer
    def findRank(self, A):
        sol = 0
        pos = 0
        fixed = ''
        
        occurence = [0 for i in range(0, 52)]
        for i in A:
            occurence[self.getIndexOf(i)] += 1
        
        while pos < len(A) - 1:
            for i in range(0, 52):
                if i < self.getIndexOf(A[pos]):
                    if occurence[i]:
                        sol = (sol + self.countPerms(fixed + self.getCharAtIndex(i), A)) % 1000003
                else:
                    break
            fixed += A[pos]
            occurence[self.getIndexOf(A[pos])] -= 1
            pos += 1
        
        return (sol + 1) % 1000003
    
    def factorial(self, n):
        if n == 0:
            return 1
        return n * self.factorial(n - 1)
    
    def getIndexOf(self, c):
        if ord(c) <= 90:
            return ord(c) - 65
        return ord(c) - 97 + 26
    
    def getCharAtIndex(self, i):
        if i <= 25:
            return chr(i + 65)
        return chr(i + 97 - 26);
    
    def countPerms(self, sub, sup):
        occurence = [0 for i in range(0, 52)]
        for i in sup:
            occurence[self.getIndexOf(i)] += 1
        for i in sub:
            occurence[self.getIndexOf(i)] -= 1
        
        repetitions = [i for i in occurence if i > 1]
        
        numerator = self.factorial(len(sup)-len(sub))
        denominator = 1
        for i in repetitions:
            denominator *= i
        return (numerator / denominator) % 1000003

