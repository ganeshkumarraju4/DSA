class Solution(object):
    def jump(self, nums):
        farthest = 0
        currEnd = 0
        jumps =0
        for i in range(len(nums)-1):
            farthest = max(farthest,nums[i]+i)
            if i == currEnd:
                jumps  = jumps+1
                currEnd = farthest
        return jumps

        