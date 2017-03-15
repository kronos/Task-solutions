package main

import (
	"fmt"
)

func main() {
	var n, p, q int
	a := 0
	fmt.Scanf("%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d\n", &p, &q)
		if q-p > 1 {
			a++
		}
	}
	fmt.Println(a)
}
