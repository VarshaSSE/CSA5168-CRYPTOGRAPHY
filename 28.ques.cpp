#include <stdio.h>
#include <math.h>
long long int calculatePower(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    for (long long int i = 0; i < exponent; i++) {
        result = (result * base) % modulus;
    }
    return result;
}
int main() {
    long long int prime, generator, secretAlice, secretBob, publicAlice, publicBob, secretKeyAlice, secretKeyBob;
    printf("Enter a prime number (P): ");
    scanf("%lld", &prime);
    printf("Enter a generator value (G): ");
    scanf("%lld", &generator);
    printf("Enter Alice's private key (a): ");
    scanf("%lld", &secretAlice);
    publicAlice = calculatePower(generator, secretAlice, prime);
    printf("Enter Bob's private key (b): ");
    scanf("%lld", &secretBob);
    publicBob = calculatePower(generator, secretBob, prime);
    secretKeyAlice = calculatePower(publicBob, secretAlice, prime);
    secretKeyBob = calculatePower(publicAlice, secretBob, prime);
    printf("Prime number (P): %lld\n", prime);
    printf("Generator value (G): %lld\n", generator);
    printf("Alice's private key (a): %lld\n", secretAlice);
    printf("Bob's private key (b): %lld\n", secretBob);
    printf("Alice's public key: %lld\n", publicAlice);
    printf("Bob's public key: %lld\n", publicBob);
    printf("Secret key for Alice: %lld\n", secretKeyAlice);
    printf("Secret key for Bob: %lld\n", secretKeyBob);
    return 0;
}
