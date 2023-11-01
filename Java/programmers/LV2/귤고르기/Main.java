import java.util.*;
class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        Map<Integer, Integer> map = new HashMap<> ();
        for (int i : tangerine) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        List<Integer> keyList = new ArrayList<>(map.keySet());
        keyList.sort(((a, b) -> map.get(b) - map.get(a)));
        for(int i : keyList){
            if(k <= 0)
                break;
            k -= map.get(i);
            answer++;
        }
        return answer;
    }
}