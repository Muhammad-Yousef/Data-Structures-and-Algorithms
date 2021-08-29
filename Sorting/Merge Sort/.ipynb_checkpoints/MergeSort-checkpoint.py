def merge(left, right, sortingType):
    
    result = []
    
    while left and right:
        
        #Ascending Case
        if sortingType == 0:
            if left[0] < right[0]:
                result.append(left.pop(0))
            else:
                result.append(right.pop(0))
                
        #Descending Case
        if sortingType == 1:
            if left[0] > right[0]:
                result.append(left.pop(0))
            else:
                result.append(right.pop(0))
                
    if left:
        result += left
    if right:
        result += right
        
    return result
    
def merge_sort(a, sortingType):
    
    if len(a) <= 1:
        return a
    
    middle_index = len(a) // 2
    
    left_split = a[:middle_index]
    right_split = a[middle_index:]
    
    left_sorted = merge_sort(left_split, sortingType)
    right_sorted = merge_sort(right_split, sortingType)
    
    return merge(left_sorted, right_sorted, sortingType)