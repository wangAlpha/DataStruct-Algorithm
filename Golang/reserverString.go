package main

import "fmt"

func main() {
	str := "abcdefg"
	reserveString(str)
}

func reserveString(str string) {
	for v := range str {
		fmt.Printf(v)
	}
}
