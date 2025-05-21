##lrc
# 1 2 3 4 1 2 5 1 2 3 4 5
# 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
re_string = list(map(int, input("Reference string: ").split(", ")))
# 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1
page_fault = int(input("Enter No Of Frames:  "))
n = len(re_string)
frame = [-1]*page_fault
t = [0]*page_fault
c = []
total = 0
idx = 0
sum = 0

print('\nformating ')
for i in range(n):
    test= 0
    for p in range(page_fault):
        c.append(frame[p])

    for j in range(page_fault):
        if re_string[i] == frame[j]:
            test = 1
            total += 1
            t[j] = total
            break
    if test == 0:
        idx = t.index(min(t))
        frame[idx] = re_string[i]
        total += 1
        t[idx] = total
        sum += 1

    if c == frame:
        for x in range(page_fault):
            print('-', end=' ')
    else:
        for x in range(page_fault):
            if m[x] == -1:
                print("-", end=' ')
            else:
                print(frame[x], end=' ')
    c.clear()
    print()

print(f"Page Fault: {sum}")
print(f"Page Miss: {page_fault}")
print(f"Page Hit : {total_hit}")
