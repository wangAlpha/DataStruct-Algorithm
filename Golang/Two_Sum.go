func twoSum(nums []int, target int) []int {
    table := make(map[int]int)
    for i, v := range nums {
        table[v] = i
    }
	for i, v := range nums {
		n := target - v
        index, ok := table[n]
        if ok == true && i != index {
            return []int{i, index}
        }
	}
	return nil
}
