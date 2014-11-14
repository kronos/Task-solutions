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

func ReadInt64() int64 {
	scanner.Scan()
	ans, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return ans
}

func ReadString() string {
	scanner.Scan()
	return scanner.Text()
}

const max = 32767 * 30

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)

	var j, answer, from_planet int
	n := ReadInt32()
	list1 := make([]int, 30)
	list2 := make([]int, 30)
	list2[0] = 0

	for i := 0; i < n; i++ {
		if i > 0 {
			ReadString() // *
		}

		for k := 0; k < 30; k++ {
			list1[k] = max
		}

		answer = max
		planet_count := ReadInt32()
		for j = 0; j < planet_count; j++ {
			for from_planet = ReadInt32() - 1; from_planet != -1; from_planet = ReadInt32() - 1 {
				price := ReadInt32()

				if list2[from_planet]+price < list1[j] {
					list1[j] = list2[from_planet] + price
					if answer > list1[j] {
						answer = list1[j]
					}
				}
			}
		}

		for j = 0; j < planet_count; j++ {
			list2[j] = list1[j]
		}
	}
	writer.WriteString(strconv.Itoa(answer) + "\n")
}
