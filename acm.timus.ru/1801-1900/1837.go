package main

import (
	"container/list"
	"fmt"
	"sort"
)

const (
	MAX      = 100000
	ISENBAEV = "Isenbaev"
)

var (
	graph   = make([][]bool, 300)
	members = make(map[string]int)
)

func add_edge(i, j int) {
	graph[i][j] = true
	graph[j][i] = true
}

func main() {
	var n, count int
	var idx [3]int
	var teammate [3]string

	fmt.Scanf("%d\n", &n)

	for i := 0; i < 300; i++ {
		graph[i] = make([]bool, 300)
		for j := 0; j < 300; j++ {
			graph[i][j] = false
		}
	}

	count = 0

	for i := 0; i < n; i++ {
		fmt.Scanf("%s %s %s\n", &teammate[0], &teammate[1], &teammate[2])
		for j := 0; j < 3; j++ {
			if k, ok := members[teammate[j]]; ok {
				idx[j] = k
			} else {
				idx[j] = count
				members[teammate[j]] = count
				count++
			}
		}
		add_edge(idx[0], idx[1])
		add_edge(idx[0], idx[2])
		add_edge(idx[1], idx[2])
	}

	names := make([]string, count)
	isenindex := make([]int, 300)

	for member, i := range members {
		names[i] = member
		isenindex[i] = MAX
	}

	if isenbaev, ok := members[ISENBAEV]; ok {
		isenindex[isenbaev] = 0
		queue := list.New()
		queue.PushFront(isenbaev)

		for queue.Len() > 0 {
			i := queue.Remove(queue.Front()).(int)
			for j := 0; j < count; j++ {
				if graph[i][j] && isenindex[j] == MAX {
					isenindex[j] = isenindex[i] + 1
					queue.PushBack(j)
				}
			}
		}
	}

	sort.Strings(names)

	for _, name := range names {
		i := members[name]

		if isenindex[i] == MAX {
			fmt.Printf("%s undefined\n", name)
		} else {
			fmt.Printf("%s %d\n", name, isenindex[i])
		}
	}
}
