class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list) # [char counts] -> [string]
        for word in strs:
            c = [0] * 26
            for char in word:
                c[ord(char) - ord('a')] += 1
            d[tuple(c)].append(word) # lists cann't be keys of dictionary
            
        return list(d.values())