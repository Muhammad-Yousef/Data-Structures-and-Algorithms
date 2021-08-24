def find_smallest(list):
    
    smallest = list[0]
    smallest_index = 0
    
    for i in range(1, len(list)):
        if list[i] < smallest:
            smallest = list[i]
            smallest_index = i
    
    return smallest_index

def find_biggest(list):
    
    biggest = list[0]
    biggest_index = 0
    
    for i in range(1, len(list)):
        if list[i] > biggest:
            biggest = list[i]
            biggest_index = i
    
    return biggest_index

def selection_sort(list, ascending = True):
    
    new_list = []
    
    if ascending == True:
    
        for i in range(len(list)):
            new_list.append(list.pop(find_smallest(list)))
            
    elif ascending == False:
        
        for i in range(len(list)):
            new_list.append(list.pop(find_biggest(list)))
        
    return new_list

selection_sort([5, 3, 6, 2, 10], True)

selection_sort([5, 3, 6, 2, 10], False)