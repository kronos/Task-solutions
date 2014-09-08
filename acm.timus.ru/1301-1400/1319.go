package main

import "fmt"

func main() {
	var i, j, k, n int
	q := 1
	fmt.Scanf("%d", &n)
	arr := make([][]int, n)

	for i := range arr {
		arr[i] = make([]int, n)
	}

	for i = 0; i < n; i++ {
		for j = 0; j < n; j++ {
			arr[i][j] = 0
		}
	}

	for k = n - 1; k >= 0; k-- {
		for i, j = 0, k; j < n; i, j, q = i+1, j+1, q+1 {
			arr[i][j] = q
		}
	}

	for k = 1; k < n; k++ {
		for i, j = k, 0; i < n; i, j, q = i+1, j+1, q+1 {
			arr[i][j] = q
		}
	}

	for _, row := range arr {
		for _, e := range row {
			fmt.Printf("%d ", e)
		}
		fmt.Println()
	}
}
