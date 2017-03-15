package main

import (
	"fmt"
	"math"
)

func calc(a, b, n uint64) (uint64, uint64) {
	var b1 uint64
	ra := a
	rb := b
	if a*b < n*6 {
		n1 := float64(n)
		limit := uint64(math.Ceil(math.Sqrt(6.0 * n1)))
		min := uint64(10e9*6 + 1)

		for ; a <= limit; a++ {
			b1 = uint64(math.Ceil(n1 * 6.0 / float64(a)))

			if b1 >= b && a*b1 < min {
				min = a * b1
				ra, rb = a, b1
			}
		}
	}

	return ra, rb
}

func main() {
	var n, a, b uint64
	fmt.Scanf("%d %d %d\n", &n, &a, &b)

	if a > b {
		b, a = calc(b, a, n)
	} else {
		a, b = calc(a, b, n)
	}

	fmt.Printf("%d\n%d %d\n", a*b, a, b)
}
