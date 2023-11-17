function solution(number, n, m) {
    var answer = 0;
    
    if( (0 == number % n) & (0 == number % m)  ){
        answer = 1;
    }
    return answer;
}