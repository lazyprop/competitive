def main():
    a = []
    n = int(input())
    
    while n:
        a.append(int(input()))
        n-=1

    print(search(a,n,0,n-1,0))
        

def search(a,n,f,l,i):
    m = f+int(n-1/2)
    
    if n==1:
        return i

    if a[m] < a[m+1]:
        search(a,int(n/2),f,m,m)
    else:
        search(a,int(n/2),m+1,l,m)

main()




