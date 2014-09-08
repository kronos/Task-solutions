package main

import "fmt"

func main() {
	var n, k, a int
	cars_in_jam := 0
	fmt.Scanf("%d %d", &k, &n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		if a+cars_in_jam <= k {
			cars_in_jam = 0
		} else {
			cars_in_jam += a - k
		}

	}
	fmt.Printf("%d\n", cars_in_jam)
}
