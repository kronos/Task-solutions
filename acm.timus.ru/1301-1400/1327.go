package main

import "fmt"

func main() {
	var n, a, b int

	fmt.Scanf("%d\n%d\n", &a, &b)
	n = b - a + 1

	if n%2 == 0 || a%2 == 0 {
		fmt.Printf("%d\n", n/2)
	} else {
		fmt.Printf("%d\n", n/2+1)
	}
}
