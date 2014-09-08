package main

import "fmt"

var n int
var cache map[int]string = make(map[int]string)

func N(i int, n int) string {
	if cache[n] == "" {
		if i == n {
			cache[i] = fmt.Sprintf("sin(%d)", i)
		} else if i%2 == 0 {
			cache[i] = fmt.Sprintf("sin(%d+%s)", i, N(i+1, n))
		} else {
			cache[i] = fmt.Sprintf("sin(%d-%s)", i, N(i+1, n))
		}
	}
	return cache[i]
}

func S(i int) string {
	if i == 1 {
		return fmt.Sprintf("%s+%d", N(1, i), n-i+1)
	} else {
		return fmt.Sprintf("(%s)%s+%d", S(i-1), N(1, i), n-i+1)
	}
}

func main() {
	fmt.Scan(&n)
	fmt.Println(S(n))
}
