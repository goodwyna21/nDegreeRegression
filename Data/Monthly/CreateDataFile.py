import sys

#gotta remove the NaN's on the data file with last known value

_avgTemps = [2.62,3.22,5.32,8.33,11.33,13.46,14.33,13.87,12.08,9.24,6.10,3.66]

def main():
    args = len(sys.argv) - 1
    if(args == 0):
        print("Please supply source file and target file")
        return 1

    if(args == 1):
        print("Please supply target file")
        return 1

    reader = csv.reader(open("test.csv", "rb"), delimiter=",")
    x = list(reader)
    result = numpy.array(x).astype("float")

    return 0

if __name__=="__main__":
    main()
