package main

import "fmt"

const (
	one   = iota*iota + 1
	two   = iota*iota + 1
	three = iota*iota + 1
	four  = iota*iota + 1
)

func main() {
	fmt.Printf("%v %T\n", one, one)
	fmt.Printf("%v %T\n", two, two)
	fmt.Printf("%v %T\n", three, three)
}
