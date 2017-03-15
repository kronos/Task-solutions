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

func abs(a int) int {
	if a < 0 {
		return -a
	} else {
		return a
	}
}

func pow(a float64, s int) float64 {
	if s == 0 {
		return 1.0
	}

	x := a
	for i := 0; i < s; i++ {
		a *= x
	}
	return a
}

var rpos = 0

func prob(left, current int, p float64) float64 {
	if left == 0 && current == rpos {
		return p
	}

	if abs(current-rpos) > left {
		return 0.0
	}

	return prob(left-1, current-1, p*0.5) + prob(left-1, current+1, p*0.5)
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	var ans float64

	s1 := ReadString()
	s2 := ReadString()
	ppos := 0
	cond := 0
	ans = 0.0

	for i := 0; i < len(s1); i++ {
		if s1[i] == '-' {
			rpos--
		} else {
			rpos++
		}
	}

	for i := 0; i < len(s2); i++ {
		if s2[i] == '-' {
			ppos--
		} else if s2[i] == '+' {
			ppos++
		} else {
			cond++
		}
	}

	writer.WriteString(strconv.FormatFloat(prob(cond, ppos, 1.0), 'f', 10, 64) + "\n")
}
