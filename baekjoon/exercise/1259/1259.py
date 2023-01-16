while 1 :
    i = input()
    if i == '0':
        break
    
    if i[::-1] == i:
        print("yes")
    else:
        print("no")