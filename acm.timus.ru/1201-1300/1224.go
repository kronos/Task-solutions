package main

import (
	"fmt"
)

func main() {
	var n, m uint64
	fmt.Scanf("%d %d\n", &n, &m)
	if n <= m {
		if n%2 == 0 {
			println(2 + (n/2-1)*4)
		} else {
			println((n - 1) * 2)
		}
	} else {
		if m%2 == 0 {
			println(3 + (m/2-1)*4)
		} else {
			println((m-1)*2 + 1)
		}
	}
}
