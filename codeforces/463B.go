package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner *bufio.Scanner = bufio.NewScanner(os.Stdin)

func ReadInt32() int {
	scanner.Scan()
	ans, _ := strconv.Atoi(scanner.Text())
	return ans
}

func main() {
	scanner.Split(bufio.ScanWords)

	var n, h1, h2 int
	n = ReadInt32()
	power := 0
	ans := 0
	h1 = 0
	for i := 0; i < n; i++ {
		h2 = ReadInt32()
		power += h1 - h2
		if power < 0 {
			ans += power
			power = 0
		}
		h1 = h2
	}

	fmt.Println(-ans)
}
