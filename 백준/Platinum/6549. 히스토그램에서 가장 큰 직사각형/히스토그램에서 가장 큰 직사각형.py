while True:
    input_list = map(int, input().replace("\n", '').split())

    n = next(input_list)
    if n == 0:
        break
    stack = [(-1, -1)]  # (idx, h)
    max_value = 0

    for i, h in enumerate(input_list):
        if stack[-1][1] < h:
            stack.append((i, h))
        else:
            while stack[-1][1] >= h:
                idx, last_h = stack.pop()
                w = i - idx
                max_value = max(max_value, last_h * w)
                w_start_i = idx
            stack.append((w_start_i, h))


    while stack:
        i, h = stack.pop()
        w = n - i
        max_value = max(max_value, h * w)
    print(max_value)