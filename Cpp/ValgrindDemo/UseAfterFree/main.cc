#include <cstdio>

int main(int argc, char** argv)
{
	int* p = new int[5];
	delete [] p;

	p[0] = 11;   
	return 0;
}
