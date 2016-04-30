/***********************************************************************
* Shimon Panfil: Industrial Physics and Simulations                   **
* http://industrialphys.com                                           **
* THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           **
***********************************************************************/
#include "arr.h"
/* float arrays */

void init_arr1_f32(t_arr1_f32 *a) {
    a->data=0;
    a->n1=0;
}

void clean_arr1_f32(t_arr1_f32 *a) {
    FREE_MEM(a->data);
    init_arr1_f32(a);
}

int make_arr1_f32(t_arr1_f32 *a,int n1) {
    int oldsize=a->n1;
    if(n1<1) return 1;
    if(n1!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f32,n1);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    return 0;
}
	
int write_arr1_f32(t_arr1_f32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr1_f32(t_arr1_f32 *a,char *file) {
    int ret,n1;
    FILE* fp;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}    
    if(make_arr1_f32(a,n1)){ret=-3;goto abend;};
    if(fread(a->data,sizeof(t_f32),n1,fp)!=n1) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr2_f32(t_arr2_f32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
}

void clean_arr2_f32(t_arr2_f32 *a) {
    FREE_MEM(a->data);
    init_arr2_f32(a);
}

int make_arr2_f32(t_arr2_f32 *a,int n1,int n2) {
    int oldsize=a->n1*a->n2;
    int newsize=n1*n2;
    if((n1<1)||(n2<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    return 0;	

}
	
int write_arr2_f32(t_arr2_f32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr2_f32(t_arr2_f32 *a,char *file) {
    int ret,n1,n2;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr2_f32(a,n1,n2)){ret=-3;goto abend;};
    n=n1*n2;
    if(fread(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr3_f32(t_arr3_f32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
}

void clean_arr3_f32(t_arr3_f32 *a) {
    FREE_MEM(a->data);
    init_arr3_f32(a);
}

int make_arr3_f32(t_arr3_f32 *a,int n1,int n2,int n3) {
    int oldsize=a->n1*a->n2*a->n3;
    int newsize=n1*n2*n3;
    if((n1<1)||(n2<1)||(n3<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    return 0;	

}
	
int write_arr3_f32(t_arr3_f32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr3_f32(t_arr3_f32 *a,char *file) {
    int ret,n1,n2,n3;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr3_f32(a,n1,n2,n3)){ret=-3;goto abend;};
    n=n1*n2*n3;
    if(fread(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

void init_arr4_f32(t_arr4_f32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
    a->n4=0;
}

void clean_arr4_f32(t_arr4_f32 *a) {
    FREE_MEM(a->data);
    init_arr4_f32(a);
}

int make_arr4_f32(t_arr4_f32 *a,int n1,int n2,int n3,int n4) {
    int oldsize=a->n1*a->n2*a->n3*a->n4;
    int newsize=n1*n2*n3*n4;
    if((n1<1)||(n2<1)||(n3<1)||(n4<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    a->n4=n4;
    return 0;	

}
	
int write_arr4_f32(t_arr4_f32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3*a->n4;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr4_f32(t_arr4_f32 *a,char *file) {
    int ret,n1,n2,n3,n4;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr4_f32(a,n1,n2,n3,n4)){ret=-3;goto abend;};
    n=n1*n2*n3*n4;
    if(fread(a->data,sizeof(t_f32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

/* double arrays*/

void init_arr1_f64(t_arr1_f64 *a) {
    a->data=0;
    a->n1=0;
}

void clean_arr1_f64(t_arr1_f64 *a) {
    FREE_MEM(a->data);
    init_arr1_f64(a);
}

int make_arr1_f64(t_arr1_f64 *a,int n1) {
    int oldsize=a->n1;
    if(n1<1) return 1;
    if(n1!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f64,n1);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    return 0;
}
	
int write_arr1_f64(t_arr1_f64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr1_f64(t_arr1_f64 *a,char *file) {
    int ret,n1;
    FILE* fp;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}    
    if(make_arr1_f64(a,n1)){ret=-3;goto abend;};
    if(fread(a->data,sizeof(t_f64),n1,fp)!=n1) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr2_f64(t_arr2_f64 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
}

void clean_arr2_f64(t_arr2_f64 *a) {
    FREE_MEM(a->data);
    init_arr2_f64(a);
}

int make_arr2_f64(t_arr2_f64 *a,int n1,int n2) {
    int oldsize=a->n1*a->n2;
    int newsize=n1*n2;
    if((n1<1)||(n2<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f64,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    return 0;	

}
	
int write_arr2_f64(t_arr2_f64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr2_f64(t_arr2_f64 *a,char *file) {
    int ret,n1,n2;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr2_f64(a,n1,n2)){ret=-3;goto abend;};
    n=n1*n2;
    if(fread(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr3_f64(t_arr3_f64 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
}

void clean_arr3_f64(t_arr3_f64 *a) {
    FREE_MEM(a->data);
    init_arr3_f64(a);
}

int make_arr3_f64(t_arr3_f64 *a,int n1,int n2,int n3) {
    int oldsize=a->n1*a->n2*a->n3;
    int newsize=n1*n2*n3;
    if((n1<1)||(n2<1)||(n3<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f64,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    return 0;	

}
	
int write_arr3_f64(t_arr3_f64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr3_f64(t_arr3_f64 *a,char *file) {
    int ret,n1,n2,n3;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr3_f64(a,n1,n2,n3)){ret=-3;goto abend;};
    n=n1*n2*n3;
    if(fread(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

void init_arr4_f64(t_arr4_f64 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
    a->n4=0;
}

void clean_arr4_f64(t_arr4_f64 *a) {
    FREE_MEM(a->data);
    init_arr4_f64(a);
}

int make_arr4_f64(t_arr4_f64 *a,int n1,int n2,int n3,int n4) {
    int oldsize=a->n1*a->n2*a->n3*a->n4;
    int newsize=n1*n2*n3*n4;
    if((n1<1)||(n2<1)||(n3<1)||(n4<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_f64,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    a->n4=n4;
    return 0;	

}
	
int write_arr4_f64(t_arr4_f64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3*a->n4;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr4_f64(t_arr4_f64 *a,char *file) {
    int ret,n1,n2,n3,n4;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr4_f64(a,n1,n2,n3,n4)){ret=-3;goto abend;};
    n=n1*n2*n3*n4;
    if(fread(a->data,sizeof(t_f64),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

/* complex float arrays */

void init_arr1_c32(t_arr1_c32 *a) {
    a->data=0;
    a->n1=0;
}

void clean_arr1_c32(t_arr1_c32 *a) {
    FREE_MEM(a->data);
    init_arr1_c32(a);
}

int make_arr1_c32(t_arr1_c32 *a,int n1) {
    int oldsize=a->n1;
    if(n1<1) return 1;
    if(n1!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c32,n1);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    return 0;
}
	
int write_arr1_c32(t_arr1_c32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr1_c32(t_arr1_c32 *a,char *file) {
    int ret,n1;
    FILE* fp;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}    
    if(make_arr1_c32(a,n1)){ret=-3;goto abend;};
    if(fread(a->data,sizeof(t_c32),n1,fp)!=n1) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr2_c32(t_arr2_c32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
}

void clean_arr2_c32(t_arr2_c32 *a) {
    FREE_MEM(a->data);
    init_arr2_c32(a);
}

int make_arr2_c32(t_arr2_c32 *a,int n1,int n2) {
    int oldsize=a->n1*a->n2;
    int newsize=n1*n2;
    if((n1<1)||(n2<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    return 0;	

}
	
int write_arr2_c32(t_arr2_c32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr2_c32(t_arr2_c32 *a,char *file) {
    int ret,n1,n2;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr2_c32(a,n1,n2)){ret=-3;goto abend;};
    n=n1*n2;
    if(fread(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr3_c32(t_arr3_c32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
}

void clean_arr3_c32(t_arr3_c32 *a) {
    FREE_MEM(a->data);
    init_arr3_c32(a);
}

int make_arr3_c32(t_arr3_c32 *a,int n1,int n2,int n3) {
    int oldsize=a->n1*a->n2*a->n3;
    int newsize=n1*n2*n3;
    if((n1<1)||(n2<1)||(n3<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    return 0;	

}
	
int write_arr3_c32(t_arr3_c32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr3_c32(t_arr3_c32 *a,char *file) {
    int ret,n1,n2,n3;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr3_c32(a,n1,n2,n3)){ret=-3;goto abend;};
    n=n1*n2*n3;
    if(fread(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

void init_arr4_c32(t_arr4_c32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
    a->n4=0;
}

void clean_arr4_c32(t_arr4_c32 *a) {
    FREE_MEM(a->data);
    init_arr4_c32(a);
}

int make_arr4_c32(t_arr4_c32 *a,int n1,int n2,int n3,int n4) {
    int oldsize=a->n1*a->n2*a->n3*a->n4;
    int newsize=n1*n2*n3*n4;
    if((n1<1)||(n2<1)||(n3<1)||(n4<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    a->n4=n4;
    return 0;	

}
	
int write_arr4_c32(t_arr4_c32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3*a->n4;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr4_c32(t_arr4_c32 *a,char *file) {
    int ret,n1,n2,n3,n4;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr4_c32(a,n1,n2,n3,n4)){ret=-3;goto abend;};
    n=n1*n2*n3*n4;
    if(fread(a->data,sizeof(t_c32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

/* comlex double arrays */

void init_arr1_c64(t_arr1_c64 *a) {
    a->data=0;
    a->n1=0;
}

void clean_arr1_c64(t_arr1_c64 *a) {
    FREE_MEM(a->data);
    init_arr1_c64(a);
}

int make_arr1_c64(t_arr1_c64 *a,int n1) {
    int oldsize=a->n1;
    if(n1<1) return 1;
    if(n1!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c64,n1);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    return 0;
}
	
int write_arr1_c64(t_arr1_c64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr1_c64(t_arr1_c64 *a,char *file) {
    int ret,n1;
    FILE* fp;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}    
    if(make_arr1_c64(a,n1)){ret=-3;goto abend;};
    if(fread(a->data,sizeof(t_c64),n1,fp)!=n1) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr2_c64(t_arr2_c64 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
}

void clean_arr2_c64(t_arr2_c64 *a) {
    FREE_MEM(a->data);
    init_arr2_c64(a);
}

int make_arr2_c64(t_arr2_c64 *a,int n1,int n2) {
    int oldsize=a->n1*a->n2;
    int newsize=n1*n2;
    if((n1<1)||(n2<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c64,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    return 0;	

}
	
int write_arr2_c64(t_arr2_c64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr2_c64(t_arr2_c64 *a,char *file) {
    int ret,n1,n2;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr2_c64(a,n1,n2)){ret=-3;goto abend;};
    n=n1*n2;
    if(fread(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr3_c64(t_arr3_c64 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
}

void clean_arr3_c64(t_arr3_c64 *a) {
    FREE_MEM(a->data);
    init_arr3_c64(a);
}

int make_arr3_c64(t_arr3_c64 *a,int n1,int n2,int n3) {
    int oldsize=a->n1*a->n2*a->n3;
    int newsize=n1*n2*n3;
    if((n1<1)||(n2<1)||(n3<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c64,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    return 0;	

}
	
int write_arr3_c64(t_arr3_c64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr3_c64(t_arr3_c64 *a,char *file) {
    int ret,n1,n2,n3;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr3_c64(a,n1,n2,n3)){ret=-3;goto abend;};
    n=n1*n2*n3;
    if(fread(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

void init_arr4_c64(t_arr4_c64 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
    a->n4=0;
}

void clean_arr4_c64(t_arr4_c64 *a) {
    FREE_MEM(a->data);
    init_arr4_c64(a);
}

int make_arr4_c64(t_arr4_c64 *a,int n1,int n2,int n3,int n4) {
    int oldsize=a->n1*a->n2*a->n3*a->n4;
    int newsize=n1*n2*n3*n4;
    if((n1<1)||(n2<1)||(n3<1)||(n4<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_c64,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    a->n4=n4;
    return 0;	

}
	
int write_arr4_c64(t_arr4_c64 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3*a->n4;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr4_c64(t_arr4_c64 *a,char *file) {
    int ret,n1,n2,n3,n4;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr4_c64(a,n1,n2,n3,n4)){ret=-3;goto abend;};
    n=n1*n2*n3*n4;
    if(fread(a->data,sizeof(t_c64),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

/* int arrays */

void init_arr1_i32(t_arr1_i32 *a) {
    a->data=0;
    a->n1=0;
}

void clean_arr1_i32(t_arr1_i32 *a) {
    FREE_MEM(a->data);
    init_arr1_i32(a);
}

int make_arr1_i32(t_arr1_i32 *a,int n1) {
    int oldsize=a->n1;
    if(n1<1) return 1;
    if(n1!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_i32,n1);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    return 0;
}
	
int write_arr1_i32(t_arr1_i32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr1_i32(t_arr1_i32 *a,char *file) {
    int ret,n1;
    FILE* fp;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}    
    if(make_arr1_i32(a,n1)){ret=-3;goto abend;};
    if(fread(a->data,sizeof(t_i32),n1,fp)!=n1) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr2_i32(t_arr2_i32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
}

void clean_arr2_i32(t_arr2_i32 *a) {
    FREE_MEM(a->data);
    init_arr2_i32(a);
}

int make_arr2_i32(t_arr2_i32 *a,int n1,int n2) {
    int oldsize=a->n1*a->n2;
    int newsize=n1*n2;
    if((n1<1)||(n2<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_i32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    return 0;	

}
	
int write_arr2_i32(t_arr2_i32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr2_i32(t_arr2_i32 *a,char *file) {
    int ret,n1,n2;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr2_i32(a,n1,n2)){ret=-3;goto abend;};
    n=n1*n2;
    if(fread(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 


void init_arr3_i32(t_arr3_i32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
}

void clean_arr3_i32(t_arr3_i32 *a) {
    FREE_MEM(a->data);
    init_arr3_i32(a);
}

int make_arr3_i32(t_arr3_i32 *a,int n1,int n2,int n3) {
    int oldsize=a->n1*a->n2*a->n3;
    int newsize=n1*n2*n3;
    if((n1<1)||(n2<1)||(n3<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_i32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    return 0;	

}
	
int write_arr3_i32(t_arr3_i32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr3_i32(t_arr3_i32 *a,char *file) {
    int ret,n1,n2,n3;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr3_i32(a,n1,n2,n3)){ret=-3;goto abend;};
    n=n1*n2*n3;
    if(fread(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

void init_arr4_i32(t_arr4_i32 *a) {
    a->data=0;
    a->n1=0;
    a->n2=0;
    a->n3=0;
    a->n4=0;
}

void clean_arr4_i32(t_arr4_i32 *a) {
    FREE_MEM(a->data);
    init_arr4_i32(a);
}

int make_arr4_i32(t_arr4_i32 *a,int n1,int n2,int n3,int n4) {
    int oldsize=a->n1*a->n2*a->n3*a->n4;
    int newsize=n1*n2*n3*n4;
    if((n1<1)||(n2<1)||(n3<1)||(n4<1)) return 1;
    if(newsize!=oldsize) {
	FREE_MEM(a->data);
	a->data=ALLOC_MEM(t_i32,newsize);
	if(a->data==0) return -1;
    }
    a->n1=n1;
    a->n2=n2;
    a->n3=n3;
    a->n4=n4;
    return 0;	

}
	
int write_arr4_i32(t_arr4_i32 *a,char *file) {
    FILE* fp;
    size_t n=a->n1*a->n2*a->n3*a->n4;
    int ret;
    fp=fopen(file,"wb");
    if(!fp) return -1;
    if(fwrite(&a->n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(&a->n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fwrite(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3;goto abend;}
    ret=0;
abend:    
    fclose(fp);
    return ret;
}

int read_arr4_i32(t_arr4_i32 *a,char *file) {
    int ret,n1,n2,n3,n4;
    FILE* fp;
    size_t n;
    fp=fopen(file,"rb");
    if(!fp) return -1;
    if(fread(&n1,sizeof(int),1,fp)!=1) {ret=-2;goto abend;} 
    if(fread(&n2,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n3,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(fread(&n4,sizeof(int),1,fp)!=1) {ret=-2;goto abend;}
    if(make_arr4_i32(a,n1,n2,n3,n4)){ret=-3;goto abend;};
    n=n1*n2*n3*n4;
    if(fread(a->data,sizeof(t_i32),n,fp)!=n) {ret=-3; goto abend;}
    ret=0;
abend:	
    fclose(fp);
    return  ret;
} 

