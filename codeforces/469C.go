package main

import (
	"fmt"
)

func main() {
	var n, i int
	fmt.Scanf("%d\n", &n)
	if n < 4 {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
		q := 0
		for i = n; i > 7; i -= 4 {
			fmt.Printf("%d - %d = 1\n", i, i-1)
			fmt.Printf("%d - %d = -1\n", i-3, i-2)
			fmt.Printf("1 + -1 = 0\n")
			q++
		}
		switch i {
		case 4:
			fmt.Println("1 * 2 = 2")
			fmt.Println("2 * 3 = 6")
			fmt.Println("4 * 6 = 24")
			break
		case 5:
			fmt.Println("1 - 2 = -1")
			fmt.Println("5 + -1 = 4")
			fmt.Println("4 + 4 = 8")
			fmt.Println("8 * 3 = 24")
			break
		case 6:
			fmt.Println("1 - 2 = -1")
			fmt.Println("-1 - 6 = -7")
			fmt.Println("-7 - 5 = -12")
			fmt.Println("4 * 3 = 12")
			fmt.Println("12 - -12 = 24")
			break
		case 7:
			fmt.Println("1 - 2 = -1")
			fmt.Println("-1 - 7 = -8")
			fmt.Println("-8 - 6 = -14")
			fmt.Println("3 - 5 = -2")
			fmt.Println("-14 * -2 = 28")
			fmt.Println("28 - 4 = 24")
			break
		}
		for i = 0; i < q; i++ {
			fmt.Printf("0 + 24 = 24\n")
		}
	}
}
