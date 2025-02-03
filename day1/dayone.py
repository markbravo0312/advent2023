
lines = open("input.txt" , "r").readlines()


nums_to_real = { "one": 1, "two": 2 , "three": 3 , "four": 4 , "five": 5, 
                "six": 6, "seven": 7, "eight": 8, "nine": 9}



def part1() : 
    total = 0
    
    
    for line in lines: 
        first = ""
        last = ""
        for i in line:
            if i.isdigit() : 
                if first : 
                    last = i
                else: 
                    first = i

        if last == "":
            last = first
        curr = first + last 
        
        total += int(curr) 
        
    print("Result to part1: ", total)
    
    
def part2() : 
    total = 0
    
    for line in lines: 
        first = ""
        second = ""
        for i, c in enumerate(line): 
            if c.isdigit() : 
                if first: 
                    second = c
                else: 
                    first = c
            
            for k in nums_to_real:
                if line[i:i+len(k)] == k: 
                    if first: 
                        second = str(nums_to_real[k])
                    else : 
                        first = str(nums_to_real[k])

        if second == "" : 
            second = first
            
        curr = first + second
        total += int(curr)
    
    print("result for part2: ", total)
                        
        
        
            
        
    
    
    
        
                    
        
                
                
if __name__ == "__main__": 
    part1() 
    part2()