package main

func main() {
	str1, str2 := "bad", "abd"
	result := isBrotherString(str1, str2)
	print(result)
}

func isBrotherString(s1, s2 string) bool {
	if len(s2) != len(s2) {
		return false
	}
	dict := make(map[int]int)
	for c := range s1 {
		dict[c]++
	}
	for c := range s2 {
		dict[c]--
	}
	for c := range dict {
		if c != 0 {
			print(c)
			return false
		}
	}
	return true
}
