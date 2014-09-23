package main

import (
	"bufio"
	"os"
	"sort"
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
	a := make([]int, n)

	for i := 0; i < n; i++ {
		a[i] = ReadInt32()
	}

	sort.Ints(a)

	for i := n - 1; i >= 0; i-- {
		writer.WriteString(strconv.Itoa(a[i]))
		writer.WriteByte(' ')
	}
}
