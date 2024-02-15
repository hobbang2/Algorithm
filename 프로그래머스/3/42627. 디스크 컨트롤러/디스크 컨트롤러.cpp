#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 요청되는 시점 , 작업 소요 시간 
// [3,10,8]

typedef struct diskInfo
{
    int startTime ;
    int workTime ; 
    
    diskInfo( int _startTime , int _workTime )
    {
        startTime = _startTime ; 
        workTime = _workTime ; 
    }
}diskInfo;

bool compByStartTime( const diskInfo & fDisk , const diskInfo & sDisk )
{
    if( fDisk.startTime > sDisk.startTime )
    {
        return true ; 
    }
    else if( fDisk.startTime == sDisk.startTime )
    {
        if( fDisk.workTime > sDisk.workTime )
        {
            return true ;
        }
    }
    return false ; 
}


bool compByWorkTime( const diskInfo & fDisk , const diskInfo & sDisk )
{
    if( fDisk.workTime > sDisk.workTime )
    {
        return true ; 
    }
    else if( fDisk.workTime == sDisk.workTime )
    {
        if( fDisk.startTime > sDisk.startTime )
        {
            return true ;
        }
    }
    return false ; 
}

void GetNextWhileJob(  priority_queue <diskInfo, std::vector<diskInfo>, decltype(&compByStartTime) > & c ,priority_queue <diskInfo, std::vector<diskInfo>, decltype(&compByStartTime) > & d , int totalWorkTime ) 
{
    while( ( false == c.empty( ) )
        && ( c.top().startTime < totalWorkTime ) )
    {
        diskInfo nextTarget = c.top() ; c.pop();
        d.push( nextTarget ) ; 
    }
    return ;
}

int solution(vector<vector<int>> jobs) {
    int totalWorkTime = 0;
    int restTime = 0 ; 
    
    priority_queue <diskInfo, std::vector<diskInfo>, decltype(&compByStartTime) > pqByStartTime(compByStartTime) ;
    priority_queue <diskInfo, std::vector<diskInfo>, decltype(&compByWorkTime) > pqByWorkTime (compByWorkTime) ;
    
    for( size_t idx = 0 ; idx < jobs.size( ) ; ++idx )
    {
        const vector < int > & curVec = jobs[idx] ; 
        diskInfo curDiskInfo( curVec[0] , curVec[1] ) ; 
        pqByStartTime.push( curDiskInfo ) ; 
    }
    
    diskInfo curDiskInfo = pqByStartTime.top() ; pqByStartTime.pop() ; 
    diskInfo firstDiskInfo = curDiskInfo ;
    totalWorkTime += curDiskInfo.workTime +  curDiskInfo.startTime ;
    

    while ( false == pqByStartTime.empty( ) )
    {
        GetNextWhileJob(pqByStartTime,pqByWorkTime,totalWorkTime) ;
    
        
        if( true == pqByWorkTime.empty() )
        {
            curDiskInfo = pqByStartTime.top() ; pqByStartTime.pop() ; 
            totalWorkTime += ( curDiskInfo.startTime - totalWorkTime );
            totalWorkTime += ( curDiskInfo.workTime );
            
            while( ( false == pqByStartTime.empty( ) )
            && ( pqByStartTime.top().startTime < totalWorkTime ) )
            {
                diskInfo nextTarget = pqByStartTime.top() ; pqByStartTime.pop();
                pqByWorkTime.push( nextTarget ) ; 
            }
        }
        
        while( false == pqByWorkTime.empty( ) )
        {
             curDiskInfo = pqByWorkTime.top() ; pqByWorkTime.pop() ; 
             restTime += ( totalWorkTime -curDiskInfo.startTime ) ; 
             totalWorkTime += curDiskInfo.workTime ;
            
            while( ( false == pqByStartTime.empty( ) )
            && ( pqByStartTime.top().startTime < totalWorkTime ) )
            {
                diskInfo nextTarget = pqByStartTime.top() ; pqByStartTime.pop();
                pqByWorkTime.push( nextTarget ) ; 
            }
        }
    }
    
    return ( (totalWorkTime + restTime - firstDiskInfo.startTime) /jobs.size() );
}