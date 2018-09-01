def main():
    n = int(input())
    print(fib(n))

def fib(n):
    if n<=2:
        return 1
    else:
        return fib(n-1) + fib(n-2)
main()

