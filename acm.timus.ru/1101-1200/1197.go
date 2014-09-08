package main

import (
	"fmt"
)

var steps = [][]int{
	{1, 2},
	{2, 1},
	{-1, 2},
	{-1, -2},
	{1, -2},
	{-2, 1},
	{-2, -1},
	{2, -1},
}

func main() {
	var n, a, b int
	var s string
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		r := 0
		fmt.Scan(&s)
		x := int(s[0] - 'a')
		y := int(s[1] - '1')
		for j := 0; j < 8; j++ {
			a = x + steps[j][0]
			b = y + steps[j][1]

			if a >= 0 && a <= 7 && b >= 0 && b <= 7 {
				r++
			}
		}
		fmt.Printf("%d\n", r)
	}
}
