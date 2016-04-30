!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Shimon Panfil: Industrial Physics and Simulations                   !!
! http://industrialphys.com                                           !!
! THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK           !!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
MODULE VEC3D
USE FDEFS
IMPLICIT NONE
PUBLIC
CONTAINS
REAL(F32) FUNCTION LENGTH(A) 
    REAL(F32)::A(3)
    LENGTH=SQRT(A(1)**2+A(2)**2+A(3)**2)
ENDFUNCTION LENGTH

REAL(F32) FUNCTION DOT(A,B) 
    REAL(F32)::A(3),B(3)
    DOT=A(1)*B(1)+A(2)*B(2)+A(3)*B(3)
ENDFUNCTION DOT
COMPLEX(F32) FUNCTION CDOT(A,B)
    COMPLEX(F32)::A(3)
    REAL(F32)::B(3)
    CDOT=A(1)*B(1)+A(2)*B(2)+A(3)*B(3)
ENDFUNCTION CDOT

FUNCTION CROSS(A,B) RESULT(C)
    REAL(F32)::A(3),B(3),C(3)
    C(1)=A(2)*B(3)-A(3)*B(2)
    C(2)=A(3)*B(1)-A(1)*B(3)
    C(3)=A(1)*B(2)-A(2)*B(1)
ENDFUNCTION CROSS
FUNCTION CCROSS(A,B) RESULT(C)
    COMPLEX(F32)::A(3),C(3)
    REAL(F32)::B(3)
    C(1)=A(2)*B(3)-A(3)*B(2)
    C(2)=A(3)*B(1)-A(1)*B(3)
    C(3)=A(1)*B(2)-A(2)*B(1)
ENDFUNCTION CCROSS
FUNCTION MXV(A,B) RESULT(C)
    REAL(F32)::A(3,3),C(3),B(3)
        C(1)=A(1,1)*B(1)+A(1,2)*B(2)+A(1,3)*B(3)
        C(2)=A(2,1)*B(1)+A(2,2)*B(2)+A(2,3)*B(3)
        C(3)=A(3,1)*B(1)+A(3,2)*B(2)+A(3,3)*B(3)
ENDFUNCTION MXV

FUNCTION CMXV(A,B) RESULT(C)
    COMPLEX(F32)::A(3,3),C(3)
    REAL(F32)::B(3)    
        C(1)=A(1,1)*B(1)+A(1,2)*B(2)+A(1,3)*B(3)
        C(2)=A(2,1)*B(1)+A(2,2)*B(2)+A(2,3)*B(3)
        C(3)=A(3,1)*B(1)+A(3,2)*B(2)+A(3,3)*B(3)
ENDFUNCTION CMXV
!making rotation matrix RxRyRz
FUNCTION ROT_MAT (AX,AY,AZ) RESULT(M)
    REAL(F32)::AX,AY,AZ,M(3,3)
    REAL(F32)::CZ,SZ,CY,SY,CX,SX
    CX=COS(AX*TORAD_F32);SX=SIN(AX*TORAD_F32)
    CY=COS(AY*TORAD_F32);SY=SIN(AY*TORAD_F32)
    CZ=COS(AZ*TORAD_F32);SZ=SIN(AZ*TORAD_F32)
    M(1,1)=CY*CZ;          M(1,2)=-CY*SZ;         M(1,3)=SY
    M(2,1)=SX*SY*CZ+CX*SZ; M(2,2)=-SX*SY*SZ+CX*CZ;M(2,3)=-SX*CY
    M(3,1)=-CX*SY*CZ+SX*SZ;M(3,2)=CX*SY*SZ+SX*CZ; M(3,3)=CX*CY
ENDFUNCTION ROT_MAT

ENDMODULE VEC3D
