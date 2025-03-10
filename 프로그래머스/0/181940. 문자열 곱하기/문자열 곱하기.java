class Solution {
    public String solution(String my_string, int k) {
        String answer = "";
        
        for(int idx = 0 ; idx < k ; ++idx){
            answer += my_string;
        }
        
        return answer;
    }
}