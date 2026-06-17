class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sortedStrings = []
        for index, string in enumerate(strs):
            sortedStrings.append((sorted(string), index))

        sortedStrings = sorted(sortedStrings)
        ans = []
        while len(sortedStrings) > 0:
            group = []
            anagram = sortedStrings[0]
            while len(sortedStrings) > 0 and anagram[0] in sortedStrings[0]:
                originalIndex = sortedStrings[0][1]
                group.append(strs[originalIndex])
                sortedStrings.remove(sortedStrings[0])

            ans.append(group)

        return ans


