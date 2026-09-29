class Solution:
    def encode(self, strs: List[str]) -> str:
        encoded_str = ""
        for s in strs:
            encoded_str += f"{len(s)}\\{s}"
        return encoded_str
        
    def decode(self, s: str) -> List[str]:
        if len(s) == 0:
            return []
            
        words = []
        l, r = 0, 0
        while r < len(s):
            while (s[r] != '\\'):
                r += 1
            str_len = int(s[l:r])

            # point to first char of word
            l = r + 1
            # point to end of word + 1
            r = l + str_len
            
            words.append(s[l:r])

            # first digit of next num
            l = r
        return words

