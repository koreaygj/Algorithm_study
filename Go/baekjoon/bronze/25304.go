package main
import "fmt"
func main(){
	var x int
	var n int
	var sum int
	fmt.Scan(&x)
	fmt.Scan(&n)
	for i := 1; i <= n; i++{
		var a int
		var b int
		fmt.Scan(&a, &b)
		sum += a * b
	}
	if(x == sum){
		fmt.Println("Yes")
	}else{
		fmt.Println("No")
	}
}