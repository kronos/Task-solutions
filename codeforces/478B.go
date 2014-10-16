package main

import (
	"bufio"
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

func ReadInt64() int64 {
	scanner.Scan()
	ans, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return ans
}

func ReadString() string {
	scanner.Scan()
	return scanner.Text()
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	n := ReadInt64()
	m := ReadInt64()

	max := (n - m + 1) * (n - m) / 2
	x := n / m
	y := n % m
	min := y*(x+1)*x/2 + (m-y)*x*(x-1)/2

	writer.WriteString(strconv.FormatInt(min, 10) + " " + strconv.FormatInt(max, 10) + "\n")
}
