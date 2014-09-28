package main

import (
	"bufio"
	"os"
	"strconv"
)

type member struct {
	name    string
	surname string
}

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
	var pos int
	var s, mmin, mmax string
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	n := ReadInt32()
	members := make([]member, n)
	members2 := make([]member, n)
	for i := 0; i < n; i++ {
		members[i].name = ReadString()
		members[i].surname = ReadString()
	}

	for i := 0; i < n; i++ {
		pos = ReadInt32() - 1
		members2[i] = members[pos]
	}

	f := true
	if members2[0].name < members2[0].surname {
		s = members2[0].name
	} else {
		s = members2[0].surname
	}

	for i := 1; (i < n) && f; i++ {
		if members2[i].name < members2[i].surname {
			mmin = members2[i].name
			mmax = members2[i].surname
		} else {
			mmin = members2[i].surname
			mmax = members2[i].name
		}

		if mmin > s {
			s = mmin
		} else if mmax > s {
			s = mmax
		} else {
			f = false
		}
	}

	if f {
		writer.WriteString("YES\n")
	} else {
		writer.WriteString("NO\n")
	}
}
