/*
 * Complexity:
 *
 * I'm probably missing some import things so might not be accurate
 *
 * O(cn) when s is made of the same character, ie. "aaaaaaaaa"
 * O(cn) when result = len(s), ie. "abcde"
 *
 * Worst case should be when the length of the substrings is gradually increasing,
 * ie. "aababcabcd..."
 * I'd say it's O(n·maxlen) in this case
 */

func lengthOfLongestSubstring(s string) int {
    maxlen := 0

	/* mymap[c] set when we encounter a character */
    var mymap [256]int

	/* we won't find a string longer than maxlen after index len(s) - maxlen */
    for i := 0; i < len(s) - maxlen; i++ {
        j := i

        for j < len(s) {
            c := s[j]

			/* i+1 just because we need a unique w/respect from i non-zero value */
			uniq := i+1

			/* did we already encounter c? */
            if mymap[c] == uniq {
                break
            }

			/* we saw c */
            mymap[c] = uniq

            j++
        }

        if j-i > maxlen {
            maxlen = j-i
        }
    }

    return maxlen
}
