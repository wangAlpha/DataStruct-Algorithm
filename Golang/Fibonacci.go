package main

func fib(n int) int {
	arr := [2]int{0, 1}
	for n >= 2 {
		arr[0] = arr[0] + arr[1]
		arr[1] = arr[0] + arr[1]
		n -= 2
	}
	return arr[n]
}

func main() {
	for i := 0; i < 39; i++ {
		print(fib(i), " ")
	}
	println()
}
