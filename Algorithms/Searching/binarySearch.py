import math

def search(arr,a,b,x):
    if b>=a:
        m = a + int((b-1) / 2)

        if arr[m] == x:
            return m
        else:
            if arr[m] > x:
                return search(arr,a,m-1,x)
            else:
                return search(arr,m+1,b,x)
    else:
        return -1



def main():
    n = int(input())
    x = int(input())
    a=[]
    while (n):
        a.append(int(input()))
        n-=1

    print(search(a,0,len(a)-1,x))
main()


