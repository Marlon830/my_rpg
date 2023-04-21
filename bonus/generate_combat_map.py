def generate_map(width, height, filename) :
    try :
        fd = open(filename, 'x')
    except FileExistsError :
        fd = open(filename, 'w')
    fd.close()
    fd = open(filename, 'w')
    fd.write(str(width) + ' ' + str(height) + '\n')
    for x in range(width) :
        for y in range(height, 0, -1) :
            fd.write(str(x) + ' ' + str(y) + ' 40\n') 

generate_map(10, 20, "testmap")