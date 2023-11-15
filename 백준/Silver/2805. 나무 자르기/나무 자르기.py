

def get_remain_height_list( tree_height:list, cut_height : int ):
    
    remain_height = [ ( height - cut_height) if( height > cut_height) else 0 for height in tree_height]
    return remain_height


# 나무의 수, 상근이가 집으로 가져가려는 나무의 길이 
N, M  = list(map(int, input().split()))

tree_height = list(map(int, input().split()))
tree_height_sorted = sorted(tree_height)

start = 0 
end = max(tree_height)
mid = ( start + end ) // 2 
res = -1

while( start < end ):
    mid = ( start + end ) // 2 
    
    remain_height = get_remain_height_list(tree_height,mid)
    total_get = sum(remain_height)
    
    if( total_get < M ):
        end = mid 
        
    elif ( total_get >= M ):
        res = max( mid, res )
        start = mid + 1
        
print(res)
    
    