package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	if n < 1 {
		fmt.Printf("%d\n", (n+1)*(2-n)/2)
	} else {
		fmt.Printf("%d\n", (n+1)*n/2)
	}
}
