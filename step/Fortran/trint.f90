!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Shimon Panfil: Industrial Physics and Simulations        !
! http://industrialphys.com                                !
! THE SOFTWARE IS PROVIDED "AS IS", USE IT AT YOUR OWN RISK!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! BASED ON J. N. LYNESS AND D. JESPERSEN
!   MODERATE DEGREE SYMMETRIC QUADRAURE RULES FOR THE TRIANGLE
!   J. INST. MATH. APPL (1975),15,19-32
MODULE TRINT
USE FDEFS
IMPLICIT NONE
PUBLIC
    PRIVATE::SQ15,W1,W2,W3,A1,A2,B1,B2
    REAL(F32),PARAMETER::SQ15=SQRT(15+ZERO_F32)
    REAL(F32),PARAMETER::W1=9/(40+ZERO_F32)
    REAL(F32),PARAMETER::W2=(155-SQ15)/1200
    REAL(F32),PARAMETER::W3=(155+SQ15)/1200
    REAL(F32),PARAMETER::A1=(9+2*SQ15)/21
    REAL(F32),PARAMETER::A2=(9-2*SQ15)/21
    REAL(F32),PARAMETER::B1=(6+SQ15)/21
    REAL(F32),PARAMETER::B2=(6-SQ15)/21


    REAL(F32),PARAMETER::TRINT1(3,1)=RESHAPE([1.0/3.0,1.0/3.0,1.0],[3,1])  
    REAL(F32),PARAMETER::TRINT3(3,3)=RESHAPE([0.0,0.5,1.0/3.0, &
                                     &  0.5,0.0,1.0/3.0, &
                                     &  0.5,0.5,1.0/3.0],[3,3])
    REAL(F32),PARAMETER::TRINT7(3,7)= RESHAPE( [ &
        &   THIRD_F32,  THIRD_F32,      W1,     &
        &   A1,         B2,             W2,     &
        &   B2,         A1,             W2,     &
        &   B2,         B2,             W2,     &
        &   A2,         B1,             W3,     &
        &   B1,         A2,             W3,     &
        &   B1,         B1,             W3],[3,7])
CONTAINS
! INTEGRATION OF REAL FUNCTION F(X,Y) OVER STANDARD TRIANGLE 0<=X,Y;X+Y<=1
! GAUSSIAN QUDRATURES
FUNCTION TRGINT_GQ_F32(A,F) RESULT(RES)
    REAL(F32)::A(:,:)
    EXTERNAL F
    REAL(F32)::F,RES
    INTEGER:: I,NP
    NP=SIZE(A,2)
    RES=ZERO_F32
    DO I=1,NP
        RES=RES+F(A(1,I),A(2,I))*A(3,I)
    ENDDO
    RES=HALF_F32*RES
ENDFUNCTION TRGINT_GQ_F32
FUNCTION TRGINT_GQ_C32(A,F) RESULT(RES)
    REAL(F32)::A(:,:)
    EXTERNAL F
    COMPLEX(F32)::F,RES
    INTEGER:: I,NP
    NP=SIZE(A,2)
    RES=ZERO_F32
    DO I=1,NP
        RES=RES+F(A(1,I),A(2,I))*A(3,I)
    ENDDO
    RES=HALF_F32*RES
ENDFUNCTION TRGINT_GQ_C32

! SUBDIVISIONS 3 POINT FORMULA
FUNCTION TRGINT_SD_F32(N,F) RESULT(RES)
    INTEGER::N ! SUBDIVISIONS
    EXTERNAL F
    REAL(F32)::F,RES
    INTEGER:: I,J
    REAL(F32),PARAMETER::A=THIRD_F32
    REAL(F32),PARAMETER::B=2.0_F32*A
    REAL(F32)::S
    S=ONE_F32/N
    RES=ZERO_F32
    DO I=0,N-1
        RES=RES+(F(0,(I+HALF_F32)*S)+F((I+HALF_F32)*S,0)+F((I+HALF_F32)*S,(N-I-HALF_F32)*S))*A
    ENDDO
    DO I=1,(N-1)
        DO J=1,2*(N-I)
            RES=RES+B*F((I-HALF_F32)*S,J*HALF_F32*S)
        ENDDO     
        DO J=1,N-I
            RES=RES+B*F(I*S,(J-HALF_F32)*S)
        ENDDO
    ENDDO
    RES=HALF_F32*RES/N**2
ENDFUNCTION TRGINT_SD_F32

! FIXED ACCURACY DLT<EPSR*ABS(RES)+EPSA
FUNCTION TRGINT_F32(F,EPSA,EPSR,N0,DN) RESULT(RES)
    EXTERNAL F
    REAL(F32)::F,RES
    REAL(F32)::EPSA,EPSR
    INTEGER::N0 ! START SUBDIVISION
    INTEGER::DN ! ADD SUBDIV
    REAL(F32)::A1,A2
    INTEGER::N
    A1=TRGINT_SD_F32(N0,F)
    N=N0+DN
    A2=TRGINT_SD_F32(N,F)
    DO WHILE (ABS(A2-A1)>EPSR*HALF_F32*(ABS(A1)+ABS(A2))+EPSA)
        A1=A2
        N=N+DN
        A2=TRGINT_SD_F32(N,F)
    ENDDO
    RES=A2
ENDFUNCTION TRGINT_F32




ENDMODULE TRINT


