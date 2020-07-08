#include "ipp.h"

void rescale(float *in, float * out, float scale, int len) {
	
	float max=-1;

	ippsMax_32f(in, len, &max);
  
	for (int i=0;i<len;i++) {
		out[i]=scale*in[i]/max;
	}
}

