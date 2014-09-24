package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var scanner *bufio.Scanner = bufio.NewScanner(os.Stdin)

func ReadInt32() int {
	scanner.Scan()
	ans, _ := strconv.Atoi(scanner.Text())
	return ans
}

func mmax(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	scanner.Split(bufio.ScanWords)
	n := ReadInt32()
	m := ReadInt32()
	k := ReadInt32()

	edgex := make([]int, k+1)
	edgey := make([]int, k+1)
	dp := make([]int, k+1)

	for i := 1; i <= k; i++ {
		edgex[i] = ReadInt32()
		edgey[i] = ReadInt32()
	}

	f := true

	for p := 0; (p <= k) && f; p++ {
		f = false
		for i := 0; i < k; i++ {
			for j := i + 1; j <= k; j++ {
				if edgex[i] < edgex[j] && edgey[i] < edgey[j] {
					f = f || dp[i] < dp[j]+1
					dp[i] = mmax(dp[i], dp[j]+1)
				} else if edgex[j] < edgex[i] && edgey[j] < edgey[i] {
					f = f || dp[j] < dp[i]+1
					dp[j] = mmax(dp[j], dp[i]+1)
				}
			}
		}
	}

	fmt.Println(math.Floor(float64((n+m)*100) - float64(dp[0])*58.57864376269049 + 0.5))
}
