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

	s1 := ReadString()
	s2 := ReadString()
	i := 0
	j := 0
	ans := 0

	for i < len(s1) && j < len(s2) {
		ans++
		if (s1[i] == 'F' && s2[j] == 'F') ||
			(s1[i] == 'L' && s2[j] == 'L') ||
			(s1[i] == 'R' && s2[j] == 'F') ||
			(s1[i] == 'R' && s2[j] == 'R') ||
			(s1[i] == 'F' && s2[j] == 'R') {
			i++
			j++
		} else if s2[j] == 'L' {
			i++
		} else {
			j++
		}
	}

	ans += len(s1) - i
	ans += len(s2) - j
	writer.WriteString(strconv.Itoa(ans) + "\n")
}
