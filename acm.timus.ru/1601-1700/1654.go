package main

import (
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	var j int
	var output [200002]byte

	s, _ := ioutil.ReadAll(os.Stdin)
	rlength := 0
	slength := len(s)
	for i := 0; i < slength; {
		c := s[i]
		for j, i = i, i+1; i < slength && s[i] == c; i++ {
		}

		if (i-j)%2 == 1 {
			if rlength > 0 && output[rlength-1] == c {
				rlength--
			} else {
				output[rlength] = c
				rlength++
			}
		}
	}

	fmt.Printf("%s", output[0:rlength])
}
