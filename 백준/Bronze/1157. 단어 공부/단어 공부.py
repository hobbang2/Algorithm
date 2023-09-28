from collections import Counter

s = input().lower()
s_cnt_dict = Counter(s)

try:
    top_1 = s_cnt_dict.most_common(2)[0]
    top_2 = s_cnt_dict.most_common(2)[1]

    if(top_1[1] == top_2[1]):
        print("?")
    else:
        print(f"{top_1[0].upper()}")
except:
    top_1 = s_cnt_dict.most_common(1)[0]
    print(f"{top_1[0].upper()}")

    