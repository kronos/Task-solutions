package main

import "fmt"

func main() {
	var n, k, a, b int
	fmt.Scanf("%d %d\n", &n, &k)
	martians := k
	britains := 0

	for i := 0; i < n; i++ {
		fmt.Scanf("%d %d\n", &a, &b)
		martians += a
		britains += b
	}

	answer := martians - britains - (n+1)*2

	if answer >= 0 {
		fmt.Printf("%d\n", answer)
	} else {
		fmt.Println("Big Bang!")
	}
}
