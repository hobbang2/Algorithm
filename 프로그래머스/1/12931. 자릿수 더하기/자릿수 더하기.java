import java.util.*;

public class Solution {
    public int solution(int n) {
        int answer = 0;
        int cpyN = n; 
        
        while(cpyN > 0){
            answer += (cpyN % 10);
            cpyN /= 10;
        }

        return answer;
    }
}