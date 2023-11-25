N = int(input())
K = int(input())
sensors = list(map(int,input().split(' ')))
sensors.sort()
section_len_list = []


for idx in range(0, N - 1):
    section_len_list.append(sensors[idx + 1] - sensors[idx])

section_len_list = [ s for s in section_len_list if s > 0 ]

section_len_list.sort()
result = 0 

for idx in range( (len(section_len_list) - (K-1))):
    result += section_len_list[idx]

print(result)