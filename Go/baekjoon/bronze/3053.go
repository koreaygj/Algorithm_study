package main
import (
	"fmt"
	"math"
)
func main(){
	var r float64
	fmt.Scanln(&r)
	fmt.Printf("%.6f\n", r * r * math.Pi)
	fmt.Printf("%.6f\n",2.00000 * r * r)
}