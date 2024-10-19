level = int(input("Level: "))
assert level in [1, 2, 3]
# expr=input("Enter your expression: ")
# Use `n+-*/%()0123456789` to make a function
# expr="n"
# assert len(expr)<50
# assert len(set(expr)-set('n+-*/%()0123456789'))==0
# fun=eval(f'lambda n: {expr}', {}, {})
# fun = lambda n : ((1+2**(1/2))**(n-1)-(1-2**(1/2))**(n-1))/2**(3/2)
# fun = lambda n : (((1+2**(1/2))**n-(1-2**(1/2))**n)/8**(1/2)+(3/5))//1
expr="(4**(n*n)//(16**n-1-2**(2*n+1)))%(4**n)"

def fun(n):
    return (4**((n)*(n))//(16**(n)-1-2**(2*n+1))) % (4**(n))
    # return (4**((n+1)*(n+1))//(16**(n+1)-1-2**(2*n+3))) % (4**(n+1))
    # return (4**(n*(n+1))//(16**(n)-1-2*4**(n))) % (4**n)
    # return (4**(n*n)-4**(n*(n+2))//(16**(n)-1-4**(n))) % (4**n)

# flag{d0_u_UsE_COMpuTati0n_by_r0unD1ng?}
# flag{mag1C_geneRaT1Ng_fuNct10N}
# flag{p3LLs_4r3_4w3s0m3}? By copilot
# def fun(n):
#     if n==1:
#         return 0
#     if n==2:
#         return 1
#     return (2*fun(n-1)+fun(n-2))%n
if level == 1:
    # 0**(n-2)**2+0**(2**(n-1)%n-1)**2-0**(n-341)**2
    primes = list(range(2, 500))
    for j in primes[:]:
        primes = [i for i in primes if i <= j or i % j != 0]
    # print(primes)
    print([(i, fun(i)) for i in range(2, 500)])
    for i in range(2, 500):
        assert fun(i) == int(i in primes), (i, fun(i), int(i in primes))
else:
    a, b = 0, 1
    maxn = 200 if level == 3 else 40
    pells: list[None | int] = [None]
    for n in range(1, maxn):
        pells.append(a)
        a, b = b, a+2*b
    # https://oeis.org/search
    # 1+(1-2*n)//(-1+2*n+n**2)
    # 0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2378, 5741, 13860, 33461, 80782, 195025, 470832, 1136689, 2744210, 6625109, 15994428, 38613965, 93222358, 225058681, 543339720, 1311738121, 3166815962, 7645370045, 18457556052, 44560482149, 107578520350, 259717522849, 627013566048, 1513744654945, 3654502875938, 8822750406821, 21300003689580, 51422757785981, 124145519261542
    # ((1+2**(1/2))**n-(1-2**(1/2))**n)/2**(3/2)
    # for n in range(1,maxn):
    #     res=fun(n)
    #     print(f'{a}, ', end="")
    #     assert res==a, (n, res, a)
    #     if level==3:
    #         assert isinstance(res,int)
    #     a,b=b,a+2*b
    computed = [None]+[fun(i) for i in range(1, maxn)]
    print(*computed)
    print(*pells)
    assert pells == computed
    # for i in range(1, maxn):
    #     assert pells[i] == fun(i), (i+1, pells[i], fun(i))
print(open(f"flag{level}.txt").read())
