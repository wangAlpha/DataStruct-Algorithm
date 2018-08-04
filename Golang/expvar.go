package main

import (
	"expvar"
	"net"
	"net/http"
)

var (
	test = expvar.NewMap("Test")
)

func init() {
	test.Add("go", 10)
	test.Add("go", 10)
}

func main() {
	sock, err := net.Listen("tcp", "localhost:8080")
	if err != nil {
		panic("error")
	}
	go func() {
		http.Serve(sock, nil)
	}()
	select {}
}
