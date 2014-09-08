package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scanf("%d %d", &n, &m)
	if (n*m-1)%2 == 0 {
		fmt.Print("[second]=:]\n")
	} else {
		fmt.Print("[:=[first]\n")
	}
}
