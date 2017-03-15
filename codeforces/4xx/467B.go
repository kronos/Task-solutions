package main

import (
	"fmt"
)

func count(n int) int {
	a := 0
	for n != 0 {
		a++
		n &= n - 1
	}
	return a
}

func main() {
	var n, m, k int
	fmt.Scanf("%d %d %d\n", &n, &m, &k)
	sum := make([]int, m+1)
	for i := 0; i <= m; i++ {
		fmt.Scanf("%d\n", &sum[i])
	}

	a := 0
	for i := 0; i < m; i++ {
		if count(sum[m]^sum[i]) <= k {
			a++
		}
	}

	fmt.Println(a)
}
