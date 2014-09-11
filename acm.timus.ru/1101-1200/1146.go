package main

import "fmt"

func main() {
	var n, max, t, j int
	fmt.Scanf("%d\n", &n)
	array := make([][]int, n+1)
	sum := make([][]int, n+1)

	for i := 0; i <= n; i++ {
		array[i] = make([]int, n+1)
		sum[i] = make([]int, n+1)
	}

	for i := 1; i <= n; i++ {
		for j = 1; j < n; j++ {
			fmt.Scanf("%d", &array[i][j])
			sum[i][j] = array[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]
		}
		fmt.Scanf("%d\n", &array[i][j])
		sum[i][j] = array[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]
	}
	max = array[1][1]

	for z := 1; z <= n; z++ {
		for k := 1; k <= n; k++ {
			for i := z; i <= n; i++ {
				for j := k; j <= n; j++ {
					t = sum[i][j] - sum[i][k-1] - sum[z-1][j] + sum[z-1][k-1]

					if t > max {
						max = t
					}
				}
			}
		}
	}

	fmt.Println(max)
}
