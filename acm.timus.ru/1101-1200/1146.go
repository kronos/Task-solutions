package main

import "fmt"

func main() {
	var n, max, t int
	fmt.Scan(&n)
	array := make([][]int, n)
	sum := make([][]int, n)

	for i := 0; i < n; i++ {
		array[i] = make([]int, n)
		sum[i] = make([]int, n)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &array[i][j])
			sum[i][j] = array[i][j]

			if j > 0 {
				sum[i][j] += sum[i][j-1]
			}

			if i > 0 {
				sum[i][j] += sum[i-1][j]
			}

			if i > 0 && j > 0 {
				sum[i][j] -= sum[i-1][j-1]
			}
		}
	}
	max = array[0][0]

	for z := 0; z < n; z++ {
		for k := 0; k < n; k++ {
			for i := z; i < n; i++ {
				for j := k; j < n; j++ {
					t = sum[i][j]
					if k < j {
						t -= sum[i][k]
					}

					if z < i {
						t -= sum[z][j]
					}

					if t > max {
						max = t
					}
				}
			}
		}
	}

	fmt.Println(max)
}
