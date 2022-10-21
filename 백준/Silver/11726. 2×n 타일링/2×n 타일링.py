N = int(input())

arr = [ 0  for _ in range( N + 1 )]

arr[0] = 1 
arr[1] = 2 

for idx in range( 2, N ) :
    arr[idx] = ( arr[idx - 1 ] + arr[idx - 2 ] ) % 10007

print( arr[N - 1] )
