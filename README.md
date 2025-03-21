###RSA Algorithm Implementation
##Step 1:-Generate Two Large Prime Numbers (p and q)
    => Ensure that **p** and **q** are both greater than **2048 bits** (for RSA 2k).
    =>Use **Rabin-Miller's algorithm** to verify primality.
##Step 2:- Calculate n
    =>Compute **n = p * q;**
    =>n, will be used as a **modulus** for **encryption** and **decryption**.
##Step 3:- Calculate Euler’s Totient Function 
    **ϕ(n) = (p - 1) * (q - 1)**
##Step 4:- Calculate the Public Key (e) 
    Choose an integer e such that: **1 < e < ϕ(n)**
             **gcd(e, ϕ(n)) = 1**
##Step 5:- Calculate the Private Key (d) 
    => Determine d, the **modular multiplicative inverse of 𝑒**
    =>**d** satisfies the equation **(e * d) % ϕ(n) = 1**
    =>**e,ϕ(n)** are **co-primes** to ensure that d exists
##Step 6:- Encryption and Decryption
    **Encryption**:-Transform the plaintext into blocks where each block is smaller than 𝑛
        =>use the **public keys (e,n)** to compute: **ciphertext = (plaintext^e) % n**
    **Decryption**
        =>Use the **private key (d,n)** to compute: **plaintext = (ciphertext^d) % n**
