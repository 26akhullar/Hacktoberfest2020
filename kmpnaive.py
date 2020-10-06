def patternsearch(pattern, text): 
    M = len(pattern) 
    N = len(text) 
  
    for i in range(N - M + 1): 
        j = 0
        while(j < M): 
            if (text[i + j] != pattern[j]): 
                break
            j += 1
  
        if (j == M):  
            print("Pattern found at index ", i) 
      
  
    
# Main Program             
text = "THAPARUNIVERSITY"
pattern = "PARU"
patternsearch(pattern, text) 