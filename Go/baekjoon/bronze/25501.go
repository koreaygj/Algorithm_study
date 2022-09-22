package main
import(
	"bufio"
	"fmt"
	"os"
)
func recursion(s string, l int, r int, cnt int) (int, int){
	cnt++
	if(l >= r){
		return 1, cnt
	}else if(s[l] != s[r]){
		return 0, cnt
	}
	return recursion(s, l + 1, r - 1, cnt)
}
func palindrome(s string) (int, int){
	return recursion(s, 0, len(s) - 1, 0)
}
func main(){
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var k int
	fmt.Fscanln(reader, &k)
	for i := 0; i < k ; i++{
		var input string
		var ans, count int
		fmt.Fscanln(reader, &input)
		ans, count = palindrome(input)
		fmt.Fprintln(writer, ans, count)
	}
}