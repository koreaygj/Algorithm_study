package main
import "fmt"
func main(){
	var chess []int
	chess = []int{1, 1, 2, 2, 2, 8}
	for i := 0; i < 6; i++{
		var a int
		fmt.Scan(&a)
		chess[i] -= a
	}
	for _, ans := range chess{
	fmt.Print(ans, " ")
	}
}