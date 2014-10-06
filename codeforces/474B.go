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

func ReadString() string {
	scanner.Scan()
	return scanner.Text()
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	n := ReadInt32()
	ans := make([]int, 1000001)
	p := 1

	for i := 1; i <= n; i++ {
		for z := ReadInt32(); z > 0; z-- {
			ans[p] = i
			p++
		}
	}

	m := ReadInt32()
	for i := 0; i < m; i++ {
		writer.WriteString(strconv.Itoa(ans[ReadInt32()]) + "\n")
	}
}
