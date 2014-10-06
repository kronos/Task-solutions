package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
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
	s := make([]string, 4)

	s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)\n"
	s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|\n"
	s[0] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)\n"

	if n >= 3 {
		s[3] = "|O.......................|\n"
		n--
	} else {
		s[3] = "|#.......................|\n"
	}

	for i := 1; i <= n; i++ {
		s[i%3] = strings.Replace(s[i%3], "#", "O", 1)
	}

	writer.WriteString("+------------------------+\n")
	writer.WriteString(s[1])
	writer.WriteString(s[2])
	writer.WriteString(s[3])
	writer.WriteString(s[0])
	writer.WriteString("+------------------------+\n")
}
