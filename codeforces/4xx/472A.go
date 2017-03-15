package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner *bufio.Scanner = bufio.NewScanner(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func ReadInt32() int {
	scanner.Scan()
	ans, _ := strconv.Atoi(scanner.Text())
	return ans
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	n := ReadInt32()
	if n%2 == 0 {
		fmt.Printf("%d %d\n", 4, n-4)
	} else {
		fmt.Printf("%d %d\n", 9, n-9)
	}
}
