def insertionSort(A):
    
    for j in range(1, len(A)):
        
        key = A[j]
        i = j - 1
        
        # A[i] > key => increasing
        # A[i] < key => decreasing
        
        while A[i] > key and i >= 0:
            A[i + 1] = A[i]
            i -= 1
        
        A[i + 1] = key
        
        #Temporary: For Illustration Purposes Only
        print(A)
    
    return A