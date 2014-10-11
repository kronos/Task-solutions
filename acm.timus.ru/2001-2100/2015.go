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

type person struct {
	money  int
	weight int
}

type flat struct {
	money  int
	rooms  int
	weight int
}

func main() {
	defer writer.Flush()
	scanner.Split(bufio.ScanWords)
	zmoney := ReadInt32()
	zroom := make([]int, 3)
	zroom[1] = ReadInt32()
	zroom[2] = ReadInt32()
	flatindex := 0
	friendindex := 0
	max := -1
	var half int

	n := ReadInt32()
	friends := make([]person, n)

	for i := 0; i < n; i++ {
		friends[i].money = ReadInt32()
		friends[i].weight = ReadInt32()
	}

	m := ReadInt32()
	flats := make([]flat, m)

	for i := 0; i < m; i++ {
		flats[i].rooms = ReadInt32()
		flats[i].money = ReadInt32()
		flats[i].weight = ReadInt32()
		if flats[i].money <= zmoney {
			if zroom[flats[i].rooms]+flats[i].weight > max {
				max = zroom[flats[i].rooms] + flats[i].weight
				flatindex = i + 1
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			half = flats[j].money/2 + flats[j].money%2
			if flats[j].rooms == 2 && half <= zmoney && half <= friends[i].money {
				if flats[j].weight+friends[i].weight > max {
					max = flats[j].weight + friends[i].weight
					flatindex = j + 1
					friendindex = i + 1
				}
			}
		}
	}

	if flatindex > 0 {
		if friendindex > 0 {
			writer.WriteString("You should rent the apartment #" + strconv.Itoa(flatindex) + " with the friend #" + strconv.Itoa(friendindex) + ".\n")
		} else {
			writer.WriteString("You should rent the apartment #" + strconv.Itoa(flatindex) + " alone.\n")
		}
	} else {
		writer.WriteString("Forget about apartments. Live in the dormitory.\n")
	}
}
