/*
 * I'm espcially proud of that one considering the hours I spent on it.
 * I started by writing a gigantic piece of code that did the work and then
 * I carefully simplified by using some logical operators theorems.
 */

package leetcode

func isMatch(s string, p string) bool {
	/* an empty pattern can't match anything except the empty string */
	if len(p) == 0 {
		return len(s) == 0
	}

	match_first := len(s) > 0 && (s[0] == p[0] || p[0] == '.')

	if len(p) >= 2 && p[1] == '*' {
		return match_first && isMatch(s[1:], p[0:]) || isMatch(s[0:], p[2:])
	}

	return match_first && isMatch(s[1:], p[1:])
}
