#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define k 8
#define ARRAY_SIZE 2000000
#define SetBit(A,k) ( A[(k/32)] |= (1 << (k%32)) )
#define GetBit(A,k) ( A[(k/32)] & (1 << (k%32)) )

uint32_t murmur3_32(const char* key, size_t len, uint32_t seed);

typedef struct bf_t {
	int numHashes;
	int *hashes[k];
} bf_t;

bf_t * create_bf(){
	int i;
	bf_t *bloom = (bf_t *) malloc(sizeof(bf_t));
	bloom->numHashes = k;
	for(i = 0; i < k; i++){
		bloom->hashes[i] = calloc(ARRAY_SIZE / 32, sizeof(int));
	}
	return bloom;
}

void insert_bf(bf_t *b, char *s){
	int i;
	uint32_t h;
	for(i = 0; i < b->numHashes; i++){
		h = murmur3_32(s, strlen(s), (i + 1) * 10);
		SetBit(b->hashes[i], h % ARRAY_SIZE);
	}
}

int is_element(bf_t *b, char *q){
	int i;
	uint32_t h;
	for(i = 0; i < b->numHashes; i++){
		h = murmur3_32(q, strlen(q), (i + 1) * 10);
		if(!GetBit(b->hashes[i], h % ARRAY_SIZE)){
			return 0;
		}
	}
	return 1;
}

int main() {
	bf_t *b = create_bf();
	insert_bf(b, "World");
	insert_bf(b, "Good");
	int a = is_element(b, "Hello");
	int bc = is_element(b, "World");
	int c = is_element(b, "Good");
	printf("%d, %d, %d", a, bc, c);
}
