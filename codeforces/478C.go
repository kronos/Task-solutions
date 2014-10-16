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

func ReadInt64() int64 {
	scanner.Scan()
	ans, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return ans
}

func ReadString() string {
	scanner.Scan()
	return scanner.Text()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	a := make([]int, 3)
	a[0] = ReadInt32()
	a[1] = ReadInt32()
	a[2] = ReadInt32()
	sort.Ints(a)
	r := int64(a[0]) // min
	g := int64(a[1])
	b := int64(a[2]) // max
	writer.WriteString(strconv.FormatInt(min((r+g+b)/3, r+g), 10) + "\n")
}
