package main

import (
	"expvar"
	"io"
	"net/http"
	"strconv"
	"time"

	"github.com/paulbellamy/ratecounter"
)

var (
	counter        *ratecounter.RateCounter
	histsperminute = expvar.NewInt("hits_per_minute")
)

func increment(w http.ResponseWriter, r *http.Request) {
	counter.Incr(1)
	histsperminute.Set(counter.Rate())
	io.WriteString(w, strconv.FormatInt(counter.Rate(), 10))
}

func main() {
	counter = ratecounter.NewRateCounter(1 * time.Minute)
	http.HandleFunc("/increment", increment)
	http.ListenAndServe(":8000", nil)
}
