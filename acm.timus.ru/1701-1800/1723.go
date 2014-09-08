package main

import "fmt"

func main() {
	var s string
	var power [26]int

	fmt.Scan(&s)

	for i := 0; i < 26; i++ {
		power[i] = 0
	}

	for _, c := range s {
		power[c-'a'] += 1
	}

	max := 0
	for i := 1; i < 26; i++ {
		if power[i] > power[max] {
			max = i
		}
	}

	fmt.Printf("%c\n", 'a'+max)
}
