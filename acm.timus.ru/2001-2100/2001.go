package main

import "fmt"

func main() {
	var a, b, x, b1, a2 int
	fmt.Scanf("%d %d\n", &a, &b)
	fmt.Scanf("%d %d\n", &x, &b1)
	fmt.Scanf("%d %d\n", &a2, &x)
	fmt.Printf("%d %d\n", a-a2, b-b1)
}
