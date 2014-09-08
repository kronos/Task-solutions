package main

import "fmt"

func main() {
	var n int
	r := ""
	fmt.Scanf("%d", &n)

	if n < 5 {
		r = "few"
	} else if n < 10 {
		r = "several"
	} else if n < 20 {
		r = "pack"
	} else if n < 50 {
		r = "lots"
	} else if n < 100 {
		r = "horde"
	} else if n < 250 {
		r = "throng"
	} else if n < 500 {
		r = "swarm"
	} else if n < 1000 {
		r = "zounds"
	} else {
		r = "legion"
	}

	fmt.Printf("%s\n", r)
}
