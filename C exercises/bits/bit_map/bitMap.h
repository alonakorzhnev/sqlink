#ifndef BITMAP_H
#define BITMAP_H

typedef struct
{
	unsigned int m_nf;
	int* m_arr;
	
}BitMap;

typedef int (*bitFunc)(BitMap*, int);

int callFunc(bitFunc func, BitMap* bm, int n);

BitMap* createBM(int nf);

void destroyBM(BitMap* bm);

int bitOn(BitMap* bm, int n);

int bitOff(BitMap* bm, int n);

int bitStatus(BitMap* bm, int n);

int printBM(BitMap* bm);

#endif