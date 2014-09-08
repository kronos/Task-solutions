package main

import "fmt"

func main() {
	var n, k, r int
	fmt.Scanf("%d %d", &n, &k)
	if n <= k {
		r = 2
	} else {
		n *= 2
		r = n / k

		if n%k != 0 {
			r += 1
		}
	}
	fmt.Printf("%d\n", r)
}
