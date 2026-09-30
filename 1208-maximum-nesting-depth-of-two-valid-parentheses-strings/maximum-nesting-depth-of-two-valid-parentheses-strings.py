class Solution(object):
    def maxDepthAfterSplit(self, seq):
        depth = 0
        ans = [0]*len(seq)
        for i in range(0,len(seq)-1):
            if seq[i] == '(':
                if depth%2!=0:
                    ans[i] = 1
                depth = depth +1
            else:
                if depth%2==0:
                    ans[i] = 1
                depth = depth-1

        return ans




        