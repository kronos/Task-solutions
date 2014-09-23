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
	k := len(ReadString())
	ans := 1
	for ; n > 0; n -= k {
		ans *= n
	}
	writer.WriteString(strconv.Itoa(ans) + "\n")
}
