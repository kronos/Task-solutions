package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner *bufio.Scanner = bufio.NewScanner(os.Stdin)

func ReadInt32() int {
	scanner.Scan()
	ans, _ := strconv.Atoi(scanner.Text())
	return ans
}

func main() {
	scanner.Split(bufio.ScanWords)
	k := ReadInt32()
	a := make([]int, k)
	ans := 0

	for i := 0; i < k; i++ {
		a[i] = ReadInt32()
	}

	sort.Ints(a)
	k = k/2 + k%2

	for i := 0; i < k; i++ {
		ans += a[i]/2 + a[i]%2
	}
	fmt.Println(ans)
}
