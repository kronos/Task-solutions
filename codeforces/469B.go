package main

import (
	"fmt"
)

func main() {
	var p, q, l, r int
	fmt.Scanf("%d %d %d %d\n", &p, &q, &l, &r)
	a := make([]int, p)
	b := make([]int, p)
	c := make([]int, q)
	d := make([]int, q)
	for i := 0; i < p; i++ {
		fmt.Scanf("%d %d\n", &a[i], &b[i])
	}

	for i := 0; i < q; i++ {
		fmt.Scanf("%d %d\n", &c[i], &d[i])
	}

	ans := 0
	for t := l; t <= r; t++ {
		f := false
		for i := 0; (i < p) && !(f); i++ {
			for j := 0; (j < q) && !(f); j++ {
				f = (c[j]+t <= b[i]) && (d[j]+t >= a[i])
			}
		}

		if f {
			ans++
		}
	}
	fmt.Println(ans)
}
