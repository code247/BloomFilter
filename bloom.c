#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define k 8
#define ARRAY_SIZE 62500
#define SetBit(A,k) ( A[(k/32)] |= (1 << (k%32)) )
#define GetBit(A,k) ( A[(k/32)] & (1 << (k%32)) )

typedef struct bf_t {
	int numHashes;
	int hashes[k];
} bf_t;

bf_t * create_bf(){
	bf_t *bloom = (bf_t *) malloc(sizeof(bf_t));
	bloom->numHashes = k;
	for(int i = 0; i < k; i++){
		bloom->hashes[i] = calloc(ARRAY_SIZE, sizeof(int));
	}
	return bloom;
}

void insert_bf(bf_t *b, char *s){

}

int is_element(bf_t *b, char *q){
	if() {
		return 1;
	} else return 0;
}

int main() {
	char *a = calloc(10, sizeof(char));
	int b = a[500];
}
