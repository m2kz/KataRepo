input_file_header = open('input', 'r')

root = 'cyrupz'
parsed = [[0 for x in range(2000)] for y in range(10)]

def parser():
    line = input_file_header.readline()
    cnt = 0
    while line:
        word_counter = 0
        for word in line.split():
                parsed[word_counter][cnt] = word
                word_counter += 1
        cnt += 1
        line = input_file_header.readline()
    print(parsed)

def buildtree():
    pass

parser()