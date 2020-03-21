def main():
    n=int(input())
    memo = {}

    print(fib(n,memo))

def fib(n,memo):

    if n in memo:
        f= memo[n]

    else:
        if n<=2:
            f=1
        else:
            f = fib(n-1,memo) + fib(n-2,memo)
            memo[n] = f
    return f
main()
