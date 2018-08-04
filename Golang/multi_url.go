package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"sync"
)

func main() {
	urls := []string{
		"http://blog.csdn.net/wangshubo1989/article/details/77949252",
		"http://blog.csdn.net/wangshubo1989/article/details/77933654",
		"http://blog.csdn.net/wangshubo1989/article/details/77893561",
	}
	jsonResponses := make(chan string)
	var wg sync.WaitGroup

	wg.Add(len(urls))
	for _, url := range urls {
		go func(url string) {
			defer wg.Done()
			res, err := http.Get(url)
			if err != nil {
				log.Fatal(err)
			} else {
				defer res.Body.Close()
				body, err := ioutil.ReadAll(res.Body)
				if err != nil {
					log.Fatal(err)
				} else {
					jsonResponses <- string(body)
				}
			}
		}(url)
	}
	go func() {
		for response := range jsonResponses {
			fmt.Println(response)
		}
	}()
	wg.Wait()
}
