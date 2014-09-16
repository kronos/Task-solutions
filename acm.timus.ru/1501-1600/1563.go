package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var s string
	var n int
	dict := make(map[string]bool) // go does not have set
	r := 0

	fmt.Scanf("%d\n", &n)
	in := bufio.NewReader(os.Stdin)

	for i := 0; i < n; i++ {
		s, _ = in.ReadString('\n')
		if dict[s] {
			r++
		} else {
			dict[s] = true
		}
	}

	fmt.Println(r)
}
