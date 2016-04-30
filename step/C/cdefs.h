/***********************************************************************
* Shimon Panfil: Industrial Physics and Simulations                   **
* http://industrialphys.com                                           **
* THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           **
***********************************************************************/
#ifndef CDEFS_H
#define CDEFS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define SQR(a) ((a)*(a))
#define ALLOC_MEM(type,n) ( type *)malloc((size_t) (n)*sizeof( type))
#define ALLOC_MEM0(type,n) ( type *)calloc((size_t) (n),sizeof( type))
#define ALLOC_MEM1(type) ( type *) calloc((size_t) 1, sizeof( type))
#define FREE_MEM(pnt) if(pnt) {free(pnt);pnt=0;}
#define ERROR_MESSAGE(msg) fprintf(stderr,"ERROR: %s src: %s line:%d\n",msg,__FILE__,__LINE__)

/* data types */
typedef double	t_f64;
typedef float	t_f32;
typedef char	t_i08;
typedef unsigned char t_u08;
typedef int  t_i32;
typedef unsigned int t_u32;
typedef long long t_i64;
typedef unsigned long long t_u64;
typedef t_f32 t_c32[2];
typedef t_f64 t_c64[2];
/* high resolution timer */
double cpu_clock();

#endif


