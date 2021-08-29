def QuickSort(list):
    
    if len(list) < 2:
        return list      #Base case, arrays with 0 or 1 element are already sorted!
    else:
        #Recursive Case
        pivot = list[0]
        
        #Sub-array of all elements smaller than the pivot
        smaller = [x for x in list[1:] if x <= pivot]
        
        #Sub-array of all elements greater than the pivot
        greater = [x for x in list[1:] if x > pivot]
        
        return QuickSort(smaller) + [pivot] + QuickSort(greater)