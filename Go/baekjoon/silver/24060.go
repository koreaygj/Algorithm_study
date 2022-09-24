package main
import(
	"bufio"
	"fmt"
	"os"
)
var cnt int
var ans = -1
var n, k int
func marge(array []int, st int, mid int, end int){
	var temp []int
	var i = st
	var j = mid + 1
	var t = 0
	for i <= mid && j <= end{
		if array[i] <= array[j]{
			temp = append(temp, array[i])
			i += 1
		}else{
			temp = append(temp, array[j])
			j += 1
		}
	}
	for i <= mid{
		temp = append(temp, array[i])
		i += 1
	}
	for j <= end{
		temp = append(temp, array[j])
		j += 1
	}
	i = st
	for i <= end{
		array[i] = temp[t]
		cnt  += 1
		if(cnt == k){
			ans = array[i]
		}
		i += 1
		t += 1
	}
}
func marge_sort(array []int, st int, end int) {
	if st < end{
		var mid = (end + st) / 2
		marge_sort(array, st, mid)
		marge_sort(array, mid + 1, end)
		marge(array, st, mid, end)
	}
}
func main(){
	var reader *bufio.Reader = bufio.NewReader(os.Stdin)
	var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	fmt.Fscanln(reader, &n, &k)
	var array []int
	for i := 0; i < n; i ++{
		var a int
		fmt.Fscan(reader, &a)
		array = append(array, a)
	}
	marge_sort(array, 0, n - 1)
	fmt.Fprintln(writer, ans)
}