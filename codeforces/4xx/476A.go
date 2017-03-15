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
	number, _ := strconv.Atoi(scanner.Text())
	return number
}

func ReadInt64() int64 {
	scanner.Scan()
	number, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return number
}

func ReadString() string {
	scanner.Scan()
	return scanner.Text()
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	n := ReadInt32()
	m := ReadInt32()
	ans := -1
	if m <= n {
		ans = n/2 + n%2
		if ans%m != 0 {
			ans += m - (ans % m)
			if ans > n {
				ans = -1
			}
		}
	}

	writer.WriteString(strconv.Itoa(ans) + "\n")
}
