package main

import "fmt"

func main() {
	var n, m, a, b int
	ans := 0

	fmt.Scanf("%d %d %d %d\n", &n, &m, &a, &b)

	if m*a <= b {
		ans = a * n
	} else {
		if n >= m {
			ans = (n / m) * b
			n %= m
		}

		if n > 0 {
			if b <= a*n {
				ans += b
			} else {
				ans += a * n
			}
		}
	}

	fmt.Println(ans)
}
