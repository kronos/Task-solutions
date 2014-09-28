package main

import "fmt"

func sum(n int) int {
	ans := 0
	for n > 0 {
		ans += n % 10
		n /= 10
	}
	return ans
}

func power(n, p int) int {
	if p == 0 {
		return 1
	}

	if p%2 == 0 {
		a := power(n, p/2)
		return a * a
	} else {
		return n * power(n, p-1)
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, 73)
	for i := 0; i <= power(10, n/2)-1; i++ {
		a[sum(i)]++
	}
	ans := 0
	for i := 0; i <= 72; i++ {
		ans += a[i] * a[i]
	}
	fmt.Println(ans)
}
