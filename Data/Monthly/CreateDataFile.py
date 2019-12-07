import sys

_avgTemps = [2.62,3.22,5.32,8.33,11.33,13.46,14.33,13.87,12.08,9.24,6.10,3.66]

def main():
    args = len(sys.argv) - 1
    if(args == 0):
        print("Please supply source file and target file")
        return 1

    if(args == 1):
        print("Please supply target file")
        return 1

    with open(sys.argv[1], 'r') as src, open(sys.argv[2], 'w') as targ:
        temps = src.readline().split(',')
        temps = temps[:-1];
        numt = len(temps)
        points = [float(temps[i]) for i in range(len(temps))]

        for i in range(numt):
            points[i] = int((points[i] + _avgTemps[i % 12]) * 100)
            targ.write("%d\n" % points[i])

    return 0

if __name__=="__main__":
    main()
