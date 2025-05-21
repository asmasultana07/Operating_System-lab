
# Input: Reference string and total number of frames
pages = list(map(int, input("Reference string: ").split()))
capacity = int(input("Total frame: "))

# Initialize memory to simulate page frames
memory = [-1] * capacity
page_faults = 0

print("Formatting--")
while pages:
    page = pages.pop(0)

    if page not in memory:
        if -1 in memory:
            e = memory.index(-1)
            memory[e] = page
        else:
            # Find the page that will not be used for the longest time
            farthest_used = -1
            farthest_index = -1
            for i in range(capacity):
                if memory[i] not in pages:
                    farthest_index = i
                    break
                elif pages.index(memory[i]) > farthest_used:
                    farthest_used = pages.index(memory[i])
                    farthest_index = i

            # Replace the page with the one that won't be used for the longest time
            memory[farthest_index] = page

        page_faults += 1

    print(memory)

print(f"\nPage Miss: {page_faults}")