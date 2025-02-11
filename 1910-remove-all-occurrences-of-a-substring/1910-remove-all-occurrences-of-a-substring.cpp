class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i = 0;
        while (i < s.length()) {
            int slength = s.length();
            int partlength = part.length();
            if (s.substr(i, partlength) == part) {
                int fStart = 0, fEnd = i - 1;
                int sStart = i + partlength, sEnd = s.length();
                s = s.substr(fStart, fEnd - fStart + 1) +
                    s.substr(sStart, sEnd - sStart + 1);
                i=i-partlength+1;
                i=i<0? 0: i;
            } else
                i++;
        }
        return s;
    }
};