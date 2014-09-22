package main

import (
	"fmt"
)

func max(a, b uint64) uint64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var n, m, k int
	fmt.Scanf("%d %d %d\n", &n, &m, &k)
	sum := make([]uint64, n+1)
	dp := make([][]uint64, 2)
	dp[0] = make([]uint64, n+1)
	dp[1] = make([]uint64, n+1)

	for i := 1; i <= n; i++ {
		fmt.Scan(&sum[i])
		sum[i] += sum[i-1]
	}

	q := 1
	for i := 1; i <= k; i++ {
		q = 1 - q
		for j := i * m; j <= n; j++ {
			dp[q][j] = max(dp[q][j-1], dp[1-q][j-m]+sum[j]-sum[j-m])
		}
	}
	fmt.Println(dp[q][n])
}
