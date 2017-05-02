s = 'abcbcbcd'

def longestIncreasingSubsequence(s):
    dp0 = [1 for i in range(0, len(s))]
    dp1 = [s[i] for i in range(0, len(s))]
    maxLen = 0

    for i in range(1, len(s)):
        for j in range(0, i):
            if s[j] <= s[i]:
                if dp0[j] + 1 > dp0[i]:
                    dp1[i] = dp1[j] + s[i]
                    dp0[i] = dp0[j] + 1
                    maxLen = max(maxLen, len(dp1[i]))
                elif dp0[j] + 1 == dp0[i]:
                    dp1[i] = min(dp1[j] + s[i], dp1[i])
                    maxLen = max(maxLen, len(dp1[i]))
    x = [i for i in dp1 if len(i) is maxLen]
    return min(x)

print longestIncreasingSubsequence(s)
