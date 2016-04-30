/***********************************************************************
* Shimon Panfil: Industrial Physics and Simulations                   **
* http://industrialphys.com                                           **
* THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           **
***********************************************************************/
#ifndef FARR_F32_H
#define FARR_F32_H
#include "cdefs.h"
/* fortran-style index: i1=1,n1 */
#define FEL1(a,i1) (a)->data[(i1)-1]
/* fortran-style index: i1=1,n1,i2=1,n2 col-major */
#define FEL2(a,i1,i2) (a)->data[(i1)-1+(a)->n1*((i2)-1)]
/* fortran-style index: i1=1,n1,i2=1,n2,i3=1,n3 col-major */
#define FEL3(a,i1,i2,i3) (a)->data[(i1)-1+(a)->n1*((i2)-1+(a)->n2*((i3)-1))]
/* fortran-style index: i1=1,n1,i2=1,n2,i3=1,n3,i4=1,n4 col-major */
#define FEL4(a,i1,i2,i3,i4) (a)->data[(i1)-1+(a)->n1*((i2)-1+(a)->n2*((i3)-1+(a)->n3*((i4)-1)))]

/* float arrays*/
/* one dimensional  array */

typedef struct  {
    t_f32 *data;
    int n1;
} t_arr1_f32;
void init_arr1_f32(t_arr1_f32 *a);
void clean_arr1_f32(t_arr1_f32 *a);
int make_arr1_f32(t_arr1_f32 *a,int n1);
int write_arr1_f32(t_arr1_f32 *a,char *file);
int read_arr1_f32(t_arr1_f32 *a,char *file);

/* two dimensional  array, matrix */

typedef struct  {
    t_f32 *data;
    int n1,n2;
} t_arr2_f32;
void init_arr2_f32(t_arr2_f32 *a);
void clean_arr2_f32(t_arr2_f32 *a);
int make_arr2_f32(t_arr2_f32 *a,int n1,int n2);
int write_arr2_f32(t_arr2_f32 *a,char *file);
int read_arr2_f32(t_arr2_f32 *a,char *file);

/* 3d  array */

typedef struct  {
    t_f32 *data;
    int n1,n2,n3;
} t_arr3_f32;
void init_arr3_f32(t_arr3_f32 *a);
void clean_arr3_f32(t_arr3_f32 *a);
int make_arr3_f32(t_arr3_f32 *a,int n1,int n2,int n3);
int write_arr3_f32(t_arr3_f32 *a,char *file);
int read_arr3_f32(t_arr3_f32 *a,char *file);

/* 4d  array */

typedef struct  {
    t_f32 *data;
    int n1,n2,n3,n4;
} t_arr4_f32;
void init_arr4_f32(t_arr4_f32 *a);
void clean_arr4_f32(t_arr4_f32 *a);
int make_arr4_f32(t_arr4_f32 *a,int n1,int n2,int n3,int n4);
int write_arr4_f32(t_arr4_f32 *a,char *file);
int read_arr4_f32(t_arr4_f32 *a,char *file);

/* double arrays*/
/* one dimensional  array */

typedef struct  {
    t_f64 *data;
    int n1;
} t_arr1_f64;
void init_arr1_f64(t_arr1_f64 *a);
void clean_arr1_f64(t_arr1_f64 *a);
int make_arr1_f64(t_arr1_f64 *a,int n1);
int write_arr1_f64(t_arr1_f64 *a,char *file);
int read_arr1_f64(t_arr1_f64 *a,char *file);

/* two dimensional  array, matrix */

typedef struct  {
    t_f64 *data;
    int n1,n2;
} t_arr2_f64;
void init_arr2_f64(t_arr2_f64 *a);
void clean_arr2_f64(t_arr2_f64 *a);
int make_arr2_f64(t_arr2_f64 *a,int n1,int n2);
int write_arr2_f64(t_arr2_f64 *a,char *file);
int read_arr2_f64(t_arr2_f64 *a,char *file);

/* 3d  array */

typedef struct  {
    t_f64 *data;
    int n1,n2,n3;
} t_arr3_f64;
void init_arr3_f64(t_arr3_f64 *a);
void clean_arr3_f64(t_arr3_f64 *a);
int make_arr3_f64(t_arr3_f64 *a,int n1,int n2,int n3);
int write_arr3_f64(t_arr3_f64 *a,char *file);
int read_arr3_f64(t_arr3_f64 *a,char *file);

/* 4d  array */

typedef struct  {
    t_f64 *data;
    int n1,n2,n3,n4;
} t_arr4_f64;
void init_arr4_f64(t_arr4_f64 *a);
void clean_arr4_f64(t_arr4_f64 *a);
int make_arr4_f64(t_arr4_f64 *a,int n1,int n2,int n3,int n4);
int write_arr4_f64(t_arr4_f64 *a,char *file);
int read_arr4_f64(t_arr4_f64 *a,char *file);

/* int arrays*/
/* one dimensional  array */

typedef struct  {
    t_i32 *data;
    int n1;
} t_arr1_i32;
void init_arr1_i32(t_arr1_i32 *a);
void clean_arr1_i32(t_arr1_i32 *a);
int make_arr1_i32(t_arr1_i32 *a,int n1);
int write_arr1_i32(t_arr1_i32 *a,char *file);
int read_arr1_i32(t_arr1_i32 *a,char *file);

/* two dimensional  array, matrix */

typedef struct  {
    t_i32 *data;
    int n1,n2;
} t_arr2_i32;
void init_arr2_i32(t_arr2_i32 *a);
void clean_arr2_i32(t_arr2_i32 *a);
int make_arr2_i32(t_arr2_i32 *a,int n1,int n2);
int write_arr2_i32(t_arr2_i32 *a,char *file);
int read_arr2_i32(t_arr2_i32 *a,char *file);

/* 3d  array */

typedef struct  {
    t_i32 *data;
    int n1,n2,n3;
} t_arr3_i32;
void init_arr3_i32(t_arr3_i32 *a);
void clean_arr3_i32(t_arr3_i32 *a);
int make_arr3_i32(t_arr3_i32 *a,int n1,int n2,int n3);
int write_arr3_i32(t_arr3_i32 *a,char *file);
int read_arr3_i32(t_arr3_i32 *a,char *file);

/* 4d  array */

typedef struct  {
    t_i32 *data;
    int n1,n2,n3,n4;
} t_arr4_i32;
void init_arr4_i32(t_arr4_i32 *a);
void clean_arr4_i32(t_arr4_i32 *a);
int make_arr4_i32(t_arr4_i32 *a,int n1,int n2,int n3,int n4);
int write_arr4_i32(t_arr4_i32 *a,char *file);
int read_arr4_i32(t_arr4_i32 *a,char *file);

/* complex float arrays*/
/* one dimensional  array */

typedef struct  {
    t_c32 *data;
    int n1;
} t_arr1_c32;
void init_arr1_c32(t_arr1_c32 *a);
void clean_arr1_c32(t_arr1_c32 *a);
int make_arr1_c32(t_arr1_c32 *a,int n1);
int write_arr1_c32(t_arr1_c32 *a,char *file);
int read_arr1_c32(t_arr1_c32 *a,char *file);

/* two dimensional  array, matrix */

typedef struct  {
    t_c32 *data;
    int n1,n2;
} t_arr2_c32;
void init_arr2_c32(t_arr2_c32 *a);
void clean_arr2_c32(t_arr2_c32 *a);
int make_arr2_c32(t_arr2_c32 *a,int n1,int n2);
int write_arr2_c32(t_arr2_c32 *a,char *file);
int read_arr2_c32(t_arr2_c32 *a,char *file);

/* 3d  array */

typedef struct  {
    t_c32 *data;
    int n1,n2,n3;
} t_arr3_c32;
void init_arr3_c32(t_arr3_c32 *a);
void clean_arr3_c32(t_arr3_c32 *a);
int make_arr3_c32(t_arr3_c32 *a,int n1,int n2,int n3);
int write_arr3_c32(t_arr3_c32 *a,char *file);
int read_arr3_c32(t_arr3_c32 *a,char *file);

/* 4d  array */

typedef struct  {
    t_c32 *data;
    int n1,n2,n3,n4;
} t_arr4_c32;
void init_arr4_c32(t_arr4_c32 *a);
void clean_arr4_c32(t_arr4_c32 *a);
int make_arr4_c32(t_arr4_c32 *a,int n1,int n2,int n3,int n4);
int write_arr4_c32(t_arr4_c32 *a,char *file);
int read_arr4_c32(t_arr4_c32 *a,char *file);

/* complex double arrays*/
/* one dimensional  array */

typedef struct  {
    t_c64 *data;
    int n1;
} t_arr1_c64;
void init_arr1_c64(t_arr1_c64 *a);
void clean_arr1_c64(t_arr1_c64 *a);
int make_arr1_c64(t_arr1_c64 *a,int n1);
int write_arr1_c64(t_arr1_c64 *a,char *file);
int read_arr1_c64(t_arr1_c64 *a,char *file);

/* two dimensional  array, matrix */

typedef struct  {
    t_c64 *data;
    int n1,n2;
} t_arr2_c64;
void init_arr2_c64(t_arr2_c64 *a);
void clean_arr2_c64(t_arr2_c64 *a);
int make_arr2_c64(t_arr2_c64 *a,int n1,int n2);
int write_arr2_c64(t_arr2_c64 *a,char *file);
int read_arr2_c64(t_arr2_c64 *a,char *file);

/* 3d  array */

typedef struct  {
    t_c64 *data;
    int n1,n2,n3;
} t_arr3_c64;
void init_arr3_c64(t_arr3_c64 *a);
void clean_arr3_c64(t_arr3_c64 *a);
int make_arr3_c64(t_arr3_c64 *a,int n1,int n2,int n3);
int write_arr3_c64(t_arr3_c64 *a,char *file);
int read_arr3_c64(t_arr3_c64 *a,char *file);

/* 4d  array */

typedef struct  {
    t_c64 *data;
    int n1,n2,n3,n4;
} t_arr4_c64;
void init_arr4_c64(t_arr4_c64 *a);
void clean_arr4_c64(t_arr4_c64 *a);
int make_arr4_c64(t_arr4_c64 *a,int n1,int n2,int n3,int n4);
int write_arr4_c64(t_arr4_c64 *a,char *file);
int read_arr4_c64(t_arr4_c64 *a,char *file);


#endif
