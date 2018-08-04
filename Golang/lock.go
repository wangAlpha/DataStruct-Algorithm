package main

import (
	"fmt"
	"sync"
)

type SafeInt struct {
	sync.Mutex
	Num int
}

func main() {
	count := SafeInt{}
	done := make(chan bool)
	for i := 0; i < 10; i++ {
		go func(int int) {
			count.Lock()
			count.Num += i
			fmt.Print(count.Num, " ")
			count.Unlock()
			done <- true
		}(i)
	}
	for i := 0; i < 10; i++ {
		<- done
	}
}
