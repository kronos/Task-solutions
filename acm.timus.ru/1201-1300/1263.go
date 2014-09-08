package main

import "fmt"

var r [10000]int

func main() {
	var n, a, m int

	fmt.Scanf("%d %d\n", &n, &m)
	count := float32(m)

	for i := 0; i < m; i++ {
		fmt.Scanf("%d\n", &a)
		r[a-1]++
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%.2f%%\n", float32(r[i]*100)/count)
	}
}
