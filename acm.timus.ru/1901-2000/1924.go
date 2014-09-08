package main

import "fmt"

const black string = "black"
const grimy string = "grimy"

func main() {
	var n int
	fmt.Scan(&n)
	switch n % 10 {
	case 0:
		if (n/10)%2 == 0 {
			fmt.Println(black)
		} else {
			fmt.Println(grimy)
		}
	case 1, 2, 5, 6, 9:
		if (n/10)%2 == 0 {
			fmt.Println(grimy)
		} else {
			fmt.Println(black)
		}
	default:
		if (n/10)%2 == 0 {
			fmt.Println(black)
		} else {
			fmt.Println(grimy)
		}
	}
}
