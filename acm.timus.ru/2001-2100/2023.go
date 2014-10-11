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

func abs(a int) int {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	var s string
	n := ReadInt32()
	ans := 0
	d := make(map[uint8]int)
	d['A'] = 0
	d['P'] = 0
	d['O'] = 0
	d['R'] = 0

	d['B'] = 1
	d['M'] = 1
	d['S'] = 1

	d['D'] = 2
	d['G'] = 2
	d['J'] = 2
	d['K'] = 2
	d['T'] = 2
	d['W'] = 2

	current := 0
	for i := 0; i < n; i++ {
		s = ReadString()
		ans += abs(current - d[s[0]])
		current = d[s[0]]
	}

	writer.WriteString(strconv.Itoa(ans) + "\n")
}
