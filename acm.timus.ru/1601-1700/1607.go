package main

import "fmt"

func main() {
	var a, b, c, d int
	fmt.Scanf("%d %d %d %d\n", &a, &b, &c, &d)

	for a < c && a+b < c {
		a += b
		c -= d
	}

	if a > c {
		fmt.Printf("%d\n", a)
	} else {
		fmt.Printf("%d\n", c)
	}
}
