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
	var q int
	keyboard := "qwertyuiopasdfghjkl;zxcvbnm,./"
	dict := make(map[uint8]int)

	if ReadString() == "R" {
		q = -1
	} else {
		q = 1
	}

	s := ReadString()
	for i := 0; i < len(keyboard); i++ {
		dict[keyboard[i]] = i
	}

	r := ""
	for i := range s {
		r += string(keyboard[dict[s[i]]+q])
	}

	writer.WriteString(r + "\n")
}
