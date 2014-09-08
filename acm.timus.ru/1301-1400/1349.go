package main

import "fmt"

func main() {
	var n int

	fmt.Scanf("%d", &n)

	switch n {
	case 1:
		fmt.Println("1 2 3")
	case 2:
		fmt.Println("3 4 5")
	default:
		fmt.Println("-1")
	}
}
