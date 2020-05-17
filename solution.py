def is_prime(n):
    if (n <= 1):
        return False
    if (n == 2):
        return True
    if (n % 2 == 0):
        return False

    i = 3
    while i <= n**.5+1:
        if n % i == 0:
            return False
        i = i + 2

    return True

def prime_generator():
    n = 1
    while True:
        n += 1
        if is_prime(n):
            yield n

def rotate(n):
    size=0
    tmp=n
    while(tmp):
        if tmp>0:
            tmp//=10
            size+=1
    tmp=n
    numbers=[n]
    for _ in range(size-1):
        carry = tmp%10
        tmp//=10
        tmp+=carry*10**(size-1)
        if tmp not in numbers:
            numbers.append(tmp)
    return numbers

generator = prime_generator()
cirPrime=[]
while(True):
    tmp = next(generator)
    if tmp > 1000000: break
    if tmp in cirPrime: continue
    rot=rotate(tmp)
    
    allprime=True
    for i in range(len(rot)):
        if is_prime(rot[i]) == False:
            allprime = False
            break
    if allprime == True:
        cirPrime.extend(rot)

print(len(cirPrime))
        
