level=int(input("Level: "))
assert level in [1,2,3]
# expr=input("Enter your expression: ")
# Use `n+-*/%()0123456789` to make a function
# n % 2 > 0 || n == 2
# n % 2 + 0 ** (n - 2)
# expr="0**(0**(n-2)+0**(3**(n-1))%n)"
# assert len(expr)<50
# assert len(set(expr)-set('n+-*/%()0123456789'))==0
# fun=eval(f'lambda n: {expr}', {}, {})
# 0**(n-2)
# print([(i, 0**((i-2)*(i-2))) for i in range(2,500)])
fun = lambda n: 0**(n-2)**2+0**(2**(n-1)%n-1)**2-0**(n-341)**2
if level==1:
    primes=list(range(2,500))
    for j in primes[:]:
        primes=[i for i in primes if i<=j or i%j!=0]
    # print(primes)
    print([(i, fun(i)) for i in range(2,500)])
    for i in range(2,500):
        assert fun(i)==int(i in primes), (i, fun(i), int(i in primes))
else:
    a,b=0,1
    maxn=200 if level==3 else 40
    for n in range(1,maxn):
        res=fun(n)
        assert res==a
        if level==3:
            assert isinstance(res,int)
        a,b=b,a+2*b
print(open(f"flag{level}.txt").read())