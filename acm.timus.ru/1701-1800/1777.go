package main

import "fmt"

func main() {
	var arr [10000]uint64
	var min_difference uint64
	count := 3
	fmt.Scanf("%d %d %d\n", &arr[0], &arr[1], &arr[2])

	if arr[0] < arr[1] {
		min_difference = arr[1] - arr[0]
	} else {
		min_difference = arr[0] - arr[1]
	}

	for {
		for i := 0; i < count-1; i++ {
			for j := i + 1; j < count; j++ {
				if arr[i] > arr[j] {
					if arr[i]-arr[j] < min_difference {
						min_difference = arr[i] - arr[j]
					}
				} else {
					if arr[j]-arr[i] < min_difference {
						min_difference = arr[j] - arr[i]
					}
				}
			}
		}

		if min_difference > 0 {
			arr[count] = min_difference
			count++
		} else {
			break
		}
	}

	fmt.Println(count - 2)
}
