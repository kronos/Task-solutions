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
	a := 0
	for i := 0; i < n; i++ {
		a += ReadInt32()
	}

	if a > 0 && a%5 == 0 {
		writer.WriteString(strconv.Itoa(a/5) + "\n")
	} else {
		writer.WriteString("-1\n")
	}
}
