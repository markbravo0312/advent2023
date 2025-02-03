import re
lines = open("input.txt", "r").readlines()



def part1() : 
    total = 0
    for line in lines:
        gameid, vals = line.split(":")
        id = re.findall(r'\d+', gameid)[0]
        
        reds = re.findall(r'\d+ red', vals)
        blues = re.findall(r'\d+ blue', vals)
        greens = re.findall(r'\d+ green', vals)
        
        valid = True
        
        for s in reds: 
            x = int(s.split(' ')[0])
            if x > 12: 
                valid = False
                
        for s in blues: 
            x = int(s.split(' ')[0])
            if x > 14:
                valid =  False
                
        for s in greens: 
            x = int(s.split(' ')[0])
            if x > 13:
                valid = False
                
        if valid:
            total += int(id)
            
    print("Result to part1: ", total)
            

def getmin (nums) :
    res = 0
    for x in nums: 
        num = int(x.split(' ')[0])
        res = max(res, num)
        
    return res
        
            
def part2() : 
    total = 0
    
    
    for line in lines: 
        reds = re.findall(r"\d+ red", line)
        blues = re.findall(r"\d+ blue", line)
        greens = re.findall(r"\d+ green",line)
        
        minred = getmin(reds)
        mingreen = getmin(greens)
        minblue = getmin(blues)
        
        total += minred * mingreen * minblue

    print("Result for part2: ", total)

        
        

if __name__ == '__main__':
    part1()
    part2()
        
        