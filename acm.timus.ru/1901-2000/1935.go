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
	var a int
	n := ReadInt32()
	ans := 0
	max := 0

	for i := 0; i < n; i++ {
		a = ReadInt32()
		if max < a {
			max = a
		}
		ans += a
	}

	fmt.Println(ans + max)
}
