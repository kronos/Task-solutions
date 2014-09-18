package main

import (
	"fmt"
	"sort"
)

type rifle struct {
	number int
	sum    int
}

type BySum []rifle

func (r BySum) Len() int      { return len(r) }
func (r BySum) Swap(i, j int) { r[i], r[j] = r[j], r[i] }

func (r BySum) Less(i, j int) bool {
	if r[i].sum != r[j].sum {
		return r[i].sum < r[j].sum
	} else {
		return r[i].number < r[j].number
	}
}

var base = []int{0, 0, 65536, 59049, 65536, 78125, 46656, 16807, 32768, 59049, 1000000}

func main() {
	var n, j, rem, sum int
	var i, t, k int
	fmt.Scanf("%d %d\n", &k, &n)
	rifles := make([]rifle, n)
	rifles[0] = rifle{0, 1}
	rifles[1] = rifle{1, 1}
	f1 := make([]int, 10500)
	f2 := make([]int, 10500)
	bits := make([]int, base[k]+1)
	for i = 1; i <= base[k]; i++ {
		bits[i] = bits[i/k] + (i % k)
	}

	len2 := 1
	f1[0] = 1
	f2[0] = 1

	for i = 2; i < n; i++ {
		sum, rem = 0, 0

		for j = 0; j < len2; j++ {
			t = f2[j]
			f2[j] = (f1[j] + f2[j] + rem)
			rem = f2[j] / base[k]
			f2[j] %= base[k]
			sum += bits[f2[j]]
			f1[j] = t
		}

		if rem > 0 {
			f2[len2] = rem
			len2++
			sum += bits[rem]
		}

		rifles[i] = rifle{i, sum}
	}

	sort.Stable(BySum(rifles))

	for i = 0; i < n; i++ {
		fmt.Printf("%d ", rifles[i].number+1)
	}
	fmt.Println()
}
