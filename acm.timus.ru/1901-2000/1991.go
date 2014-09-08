package main

import "fmt"

func main() {
	var n, k, a int
	bumbums := 0
	droids := 0
	fmt.Scanf("%d %d\n", &n, &k)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a)
		if a < k {
			droids += k - a
		} else {
			bumbums += a - k
		}
	}
	fmt.Printf("%d %d\n", bumbums, droids)
}
