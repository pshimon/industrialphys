/***********************************************************************
* Shimon Panfil: Industrial Physics and Simulations                   **
* http://industrialphys.com                                           **
* THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           **
***********************************************************************/
#ifdef _WIN32
#include <windows.h>
double cpu_clock() {
    	LARGE_INTEGER fi,ti;
    	double fd,td;
    	QueryPerformanceFrequency( &fi);
    	fd=(double) fi.QuadPart;
    	QueryPerformanceCounter(&ti);
	td=(double) ti.QuadPart;
	return td/fd;
}
#else
#include <time.h>
/*High-resolution per-process timer from the CPU 
 * -lrt library should be linked*/
double cpu_clock() {
    struct timespec t0;
    clockgettime(CLOCK_PROCESS_CPUTIME_ID, &t0);
    return (double) t0.tv_sec+1.0e-9*(double) t0.tv_nsec;
}
#endif


