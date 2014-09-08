package main

import (
	"fmt"
)

func main() {
	var n, sum, index, a1, a2, a3, a int
	fmt.Scanf("%d %d %d %d", &n, &a1, &a2, &a3)
	index = 2
	sum = a1 + a2 + a3

	for i := 3; i < n; i++ {
		fmt.Scan(&a)
		if sum < a2+a3+a {
			sum = a2 + a3 + a
			index = i
		}
		a1, a2, a3 = a2, a3, a
	}
	fmt.Printf("%d %d\n", sum, index)
}
