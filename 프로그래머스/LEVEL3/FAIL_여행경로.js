function solution(tickets) {
    let answer = [];
    let ticketQ = [];
    let grapgh = {};
    let visitCheck = {};
    
    tickets.forEach((element)=>{
        if(!Object.keys(grapgh).includes(element[0])){
            grapgh[element[0]] =[element[1]];
        }
        else{
            grapgh[element[0]].push(element[1]);
        }
    });
    
    Object.keys(grapgh).forEach((element)=>{
        grapgh[element].sort();
        visitCheck[element] = false;
    });
    
    ticketQ.push("ICN");
    
    Object.keys(grapgh).forEach((element)=>{
        if((ticketQ.length == 0 )&&(grapgh[element].length!=0)){
            ticketQ.push(element);
        }
        while(ticketQ.length!=0){
            let curCity = ticketQ[0]; ticketQ.shift();
            if((curCity == undefined)){
                continue;
            }
            
            answer.push(curCity);
            if((Object.keys(grapgh).includes(curCity))&&(grapgh[curCity].length!=0)){
                let idx = 0;
                // graph[curCity].length가 1이면 그냥 push
                // 1이 아니면 grapgh[grapgh[curCity][idx]] 가 0 이 아닐 때 까지 idx를 올려주자
                console.log(curCity,grapgh[curCity].length);
                ticketQ.push(grapgh[curCity][0]);
                grapgh[curCity].shift(); 
            }
        }
    })
    
    return answer;
}