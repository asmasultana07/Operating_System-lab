##fifo_page
# 1 2 3 4 1 2 5 1 2 3 4 5
# 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
re_string = list(map(int, input("Reference string: ").split())) 
frame = int(input("total frame: "))

memory= [" "]*frame ## frame sequence

i= 0
page_fault = 0
total_hit= 0

print("formating--")
while re_string != []:
    if i == frame:
        i=0
    x = re_string.pop(0)
    if str(x) in memory:
        total_hit += 1
        print("---- ")
    else:
        page_fault += 1
        memory[i] = str(x)
        i += 1
        print(memory)

print(f"\nPage Miss: {page_fault}")
print(f"Page Hit : {total_hit}")
