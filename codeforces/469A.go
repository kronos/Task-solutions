package main

import (
	"fmt"
)

func main() {
	var n, z, a int
	fmt.Scan(&n)
	ans := make([]bool, n)

	for j := 0; j < 2; j++ {
		fmt.Scan(&z)
		for i := 0; i < z; i++ {
			fmt.Scan(&a)
			ans[a-1] = true
		}
	}

	for i := 0; i < n; i++ {
		if !ans[i] {
			fmt.Println("Oh, my keyboard!")
			return
		}
	}
	fmt.Println("I become the guy.")
}
