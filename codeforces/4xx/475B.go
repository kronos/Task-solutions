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

var (
	n, m, count int
	row, col    string
	visited     []bool
)

func dfs(i, j int) {
	index := i*m + j
	if i < 0 || j < 0 || i >= n || j >= m || visited[index] {
		return
	}

	visited[index] = true

	if row[i] == '>' {
		dfs(i, j+1)
	} else {
		dfs(i, j-1)
	}

	if col[j] == 'v' {
		dfs(i+1, j)
	} else {
		dfs(i-1, j)
	}
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	n = ReadInt32()
	m = ReadInt32()
	row = ReadString()
	col = ReadString()
	count = n * m
	f := true

	for i := 0; (i < n) && (f); i++ {
		for j := 0; (j < m) && (f); j++ {
			visited = make([]bool, count)
			dfs(i, j)
			for k := 0; (k < count) && (f); k++ {
				f = visited[k]
			}
		}
	}

	if f {
		writer.WriteString("YES\n")
	} else {
		writer.WriteString("NO\n")
	}
}
