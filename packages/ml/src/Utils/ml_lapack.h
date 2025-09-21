/* ******************************************************************** */
/* See the file COPYRIGHT for a complete copyright notice, contact      */
/* person and disclaimer.                                               */
/* ******************************************************************** */
#ifndef ML_BLAS_LAPACK_WRAPPERS_H
#define ML_BLAS_LAPACK_WRAPPERS_H

/* Wrappers for blas & lapack routines.   This file is the result of merging
 * Epetra_BLAS_wrappers.h & Epetra_LAPACK_wrappers.h and a few cosmetic
 * changes.  */

#include "ml_common.h"

#ifdef f2c_i2
/* for -i2 */
typedef short ftnlen;
#else
typedef long ftnlen;
#endif

#if defined(CRAY_T3X) || defined(INTEL_CXML) || defined(INTEL_MKL)

/* All three of these machines use a simple uppercase mangling of Fortran names */

/* if F77_BLAS_MANGLE is defined undefine it because we want to redefine */

#if defined(CRAY_T3X)

#include "fortran.h"
#define ml_fcd fcd
#define PREFIX

#define DGBSV_F77   F77_BLAS_MANGLE(sgbsv,SGBSV)
#define DGTTRF_F77  F77_BLAS_MANGLE(sgttrf,SGTTRF)
#define DGTTS2_F77  F77_BLAS_MANGLE(sgtts2,SGTTS2)
#define DGETRF_F77  F77_BLAS_MANGLE(sgetrf,SGETRF)
#define DGETRS_F77  F77_BLAS_MANGLE(sgetrs,SGETRS)
#define DGESVD_F77  F77_BLAS_MANGLE(sgesvd,SGESVD)
#define DPOTRF_F77  F77_BLAS_MANGLE(spotrf,SPOTRF)
#define DPOTRS_F77  F77_BLAS_MANGLE(spotrs,SPOTRS)
#define DPOTRI_F77  F77_BLAS_MANGLE(spotri,SPOTRI)
#define DPOCON_F77  F77_BLAS_MANGLE(spocon,SPOCON)
#define DPOSV_F77   F77_BLAS_MANGLE(sposv,SPOSV)
#define DPOEQU_F77  F77_BLAS_MANGLE(spoequ,SPOEQU)
#define DPORFS_F77  F77_BLAS_MANGLE(sporfs,SPORFS)
#define DPOSVX_F77  F77_BLAS_MANGLE(sposvx,SPOSVX)
#define DGELS_F77   F77_BLAS_MANGLE(sgels,SGELS)
#define DGEEV_F77   F77_BLAS_MANGLE(sgeev,SGEEV)
#define DGEHRD_F77  F77_BLAS_MANGLE(sgehrs,SGEHRS)
#define DHSEQR_F77  F77_BLAS_MANGLE(shseqr,SHSEQR)
#define DORGHR_F77  F77_BLAS_MANGLE(sorghr,SORGHR)
#define DORMHR_F77  F77_BLAS_MANGLE(sormhr,SORMHR)
#define DTREVC_F77  F77_BLAS_MANGLE(strevc,STREVC)
#define DTREXC_F77  F77_BLAS_MANGLE(strexc,STREXC)
#define DGELSS_F77  F77_BLAS_MANGLE(sgelss,SGELSS)
#define DSTEV_F77   F77_BLAS_MANGLE(sstev,SSTEV)
#define DGEQPF_F77  F77_BLAS_MANGLE(sgeqpf,SGEQPF)
#define DGEQRF_F77  F77_BLAS_MANGLE(sgeqrf,SGEQRF)
#define DORGQR_F77  F77_BLAS_MANGLE(sorgqr,SORGQR)
#define DSTEQR_F77  F77_BLAS_MANGLE(ssteqr,SSTEQR)

#endif
#if defined(INTEL_CXML)

#define ml_fcd char *, unsigned int
#define PREFIX __stdcall

#define DGEEV_F77   F77_BLAS_MANGLE(dgeev,DGEEV)
#define DGEHRD_F77  F77_BLAS_MANGLE(dgehrd,DGEHRD)
#define DGELS_F77   F77_BLAS_MANGLE(dgels,DGELS)
#define DGBSV_F77   F77_BLAS_MANGLE(dgbsv,DGBSV)
#define DGTTRF_F77  F77_BLAS_MANGLE(dgttrf,DGTTRF)
#define DGTTS2_F77  F77_BLAS_MANGLE(dgtts2,DGTTS2)
#define DGETRF_F77  F77_BLAS_MANGLE(dgetrf,DGETRF)
#define DGETRS_F77  F77_BLAS_MANGLE(dgetrs,DGETRS)
#define DGESVD_F77  F77_BLAS_MANGLE(dgesvd,DGESVD)
#define DHSEQR_F77  F77_BLAS_MANGLE(dhseqr,DHSEQR)
#define DORGHR_F77  F77_BLAS_MANGLE(dorghr,DORGHR)
#define DORMHR_F77  F77_BLAS_MANGLE(dormhr,DORMHR)
#define DPOTRF_F77  F77_BLAS_MANGLE(dpotrf,DPOTRF)
#define DPOTRS_F77  F77_BLAS_MANGLE(dpotrs,DPOTRS)
#define DPOTRI_F77  F77_BLAS_MANGLE(dpotri,DPOTRI)
#define DPOCON_F77  F77_BLAS_MANGLE(dpocon,DPOCON)
#define DPOSV_F77   F77_BLAS_MANGLE(dposv,DPOSV)
#define DPOEQU_F77  F77_BLAS_MANGLE(dpoequ,DPOEQU)
#define DPORFS_F77  F77_BLAS_MANGLE(dporfs,DPORFS)
#define DPOSVX_F77  F77_BLAS_MANGLE(dposvx,DPOSVX)
#define DTREVC_F77  F77_BLAS_MANGLE(dtrevc,DTREVC)
#define DTREXC_F77  F77_BLAS_MANGLE(dtrexc,DTREXC)
#define DGELSS_F77  F77_BLAS_MANGLE(dgelss,DGELSS)
#define DSTEV_F77   F77_BLAS_MANGLE(dstev,DSTEV)
#define DGEQPF_F77  F77_BLAS_MANGLE(dgeqpf,DGEQPF)
#define DGEQRF_F77  F77_BLAS_MANGLE(dgeqrf,DGEQRF)
#define DORGQR_F77  F77_BLAS_MANGLE(dorgqr,DORGQR)
#define DSTEQR_F77  F77_BLAS_MANGLE(dsteqr,DSTEQR)

#endif
#if defined(INTEL_MKL)

#define ml_fcd char *
#define PREFIX

#define DGBSV_F77   F77_BLAS_MANGLE(dgbsv,DGBSV)
#define DGTTRF_F77  F77_BLAS_MANGLE(dgttrf,DGTTRF)
#define DGTTS2_F77  F77_BLAS_MANGLE(dgtts2,DGTTS2)
#define DGETRF_F77  F77_BLAS_MANGLE(dgetrf,DGETRF)
#define DGETRS_F77  F77_BLAS_MANGLE(dgetrs,DGETRS)
#define DGESVD_F77  F77_BLAS_MANGLE(dgesvd,DGESVD)
#define DPOTRF_F77  F77_BLAS_MANGLE(dpotrf,DPOTRF)
#define DPOTRS_F77  F77_BLAS_MANGLE(dpotrs,DPOTRS)
#define DPOTRI_F77  F77_BLAS_MANGLE(dpotri,DPOTRI)
#define DPOCON_F77  F77_BLAS_MANGLE(dpocon,DPOCON)
#define DPOSV_F77   F77_BLAS_MANGLE(dposv,DPOSV)
#define DPOEQU_F77  F77_BLAS_MANGLE(dpoequ,DPOEQU)
#define DPORFS_F77  F77_BLAS_MANGLE(dporfs,DPORFS)
#define DPOSVX_F77  F77_BLAS_MANGLE(dposvx,DPOSVX)
#define DGELS_F77   F77_BLAS_MANGLE(dgels,DGELS)
#define DGEEV_F77   F77_BLAS_MANGLE(dgeev,DGEEV)
#define DGEHRD_F77  F77_BLAS_MANGLE(dgehrd,DGEHRD)
#define DHSEQR_F77  F77_BLAS_MANGLE(dhseqr,DHSEQR)
#define DORGHR_F77  F77_BLAS_MANGLE(dorghr,DORGHR)
#define DORMHR_F77  F77_BLAS_MANGLE(dormhr,DORMHR)
#define DTREVC_F77  F77_BLAS_MANGLE(dtrevc,DTREVC)
#define DTREXC_F77  F77_BLAS_MANGLE(dtrexc,DTREXC)
#define DGELSS_F77  F77_BLAS_MANGLE(dgelss,DGELSS)
#define DSTEV_F77   F77_BLAS_MANGLE(dstev,DSTEV)
#define DGEQPF_F77  F77_BLAS_MANGLE(dgeqpf,DGEQPF)
#define DGEQRF_F77  F77_BLAS_MANGLE(dgeqrf,DGEQRF)
#define DORGQR_F77  F77_BLAS_MANGLE(dorgqr,DORGQR)
#define DSTEQR_F77  F77_BLAS_MANGLE(dsteqr,DSTEQR)

#endif

#ifdef F77_BLAS_MANGLE
#undef F77_BLAS_MANGLE
#endif

#define F77_BLAS_MANGLE(lcase,UCASE) UCASE

#else

#define ml_fcd const char *
#define PREFIX

/* Use autoconf's definition of F77_BLAS_MANGLE
   unless using old make system */

#ifdef TRILINOS_NO_CONFIG_H

#ifdef F77_BLAS_MANGLE
#undef F77_BLAS_MANGLE
#endif

#ifdef TRILINOS_HAVE_NO_FORTRAN_UNDERSCORE
#define F77_BLAS_MANGLE(lcase,UCASE) lcase
#else /* TRILINOS_HAVE_NO_FORTRAN_UNDERSCORE not defined*/
#define F77_BLAS_MANGLE(lcase,UCASE) lcase ## _
#endif /* TRILINOS_HAVE_NO_FORTRAN_UNDERSCORE */
#endif /* TRILINOS_NO_CONFIG_H */

#define DGBSV_F77   F77_BLAS_MANGLE(dgbsv,DGBSV)
#define DGTTRF_F77  F77_BLAS_MANGLE(dgttrf,DGTTRF)
#define DGTTS2_F77  F77_BLAS_MANGLE(dgtts2,DGTTS2)
#define DGETRF_F77  F77_BLAS_MANGLE(dgetrf,DGETRF)
#define DGETRS_F77  F77_BLAS_MANGLE(dgetrs,DGETRS)
#define DGESVD_F77  F77_BLAS_MANGLE(dgesvd,DGESVD)
#define DPOTRF_F77  F77_BLAS_MANGLE(dpotrf,DPOTRF)
#define DPOTRS_F77  F77_BLAS_MANGLE(dpotrs,DPOTRS)
#define DPOTRI_F77  F77_BLAS_MANGLE(dpotri,DPOTRI)
#define DPOCON_F77  F77_BLAS_MANGLE(dpocon,DPOCON)
#define DPOSV_F77   F77_BLAS_MANGLE(dposv,DPOSV)
#define DPOEQU_F77  F77_BLAS_MANGLE(dpoequ,DPOEQU)
#define DPORFS_F77  F77_BLAS_MANGLE(dporfs,DPORFS)
#define DPOSVX_F77  F77_BLAS_MANGLE(dposvx,DPOSVX)
#define DGELS_F77   F77_BLAS_MANGLE(dgels,DGELS)
#define DGEEV_F77   F77_BLAS_MANGLE(dgeev,DGEEV)
#define DGEHRD_F77  F77_BLAS_MANGLE(dgehrd,DGEHRD)
#define DHSEQR_F77  F77_BLAS_MANGLE(dhseqr,DHSEQR)
#define DORGHR_F77  F77_BLAS_MANGLE(dorghr,DORGHR)
#define DORMHR_F77  F77_BLAS_MANGLE(dormhr,DORMHR)
#define DTREVC_F77  F77_BLAS_MANGLE(dtrevc,DTREVC)
#define DTREXC_F77  F77_BLAS_MANGLE(dtrexc,DTREXC)
#define DGELSS_F77  F77_BLAS_MANGLE(dgelss,DGELSS)
#define DSTEV_F77   F77_BLAS_MANGLE(dstev,DSTEV)
#define DGEQPF_F77  F77_BLAS_MANGLE(dgeqpf,DGEQPF)
#define DGEQRF_F77  F77_BLAS_MANGLE(dgeqrf,DGEQRF)
#define DORGQR_F77  F77_BLAS_MANGLE(dorgqr,DORGQR)
#define DSTEQR_F77  F77_BLAS_MANGLE(dsteqr,DSTEQR)

#endif

#define DGETRI_F77  F77_BLAS_MANGLE(dgetri,DGETRI)
#define DGERFS_F77  F77_BLAS_MANGLE(dgerfs,DGERFS)
#define DGECON_F77  F77_BLAS_MANGLE(dgecon,DGECON)
#define DGESVX_F77  F77_BLAS_MANGLE(dgesvx,DGESVX)
#define DGESV_F77   F77_BLAS_MANGLE(dgesv,DGESV)
#define DGEEQU_F77  F77_BLAS_MANGLE(dgeequ,DGEEQU)
#define DLAMCH_F77  F77_BLAS_MANGLE(dlamch,DLAMCH)
#define DGELSS_F77  F77_BLAS_MANGLE(dgelss,DGELSS)
#define DSTEV_F77   F77_BLAS_MANGLE(dstev,DSTEV)
#define DGEQPF_F77  F77_BLAS_MANGLE(dgeqpf,DGEQPF)
#define DGEQRF_F77  F77_BLAS_MANGLE(dgeqrf,DGEQRF)
#define DORGQR_F77  F77_BLAS_MANGLE(dorgqr,DORGQR)
#define DSTEQR_F77  F77_BLAS_MANGLE(dsteqr,DSTEQR)

#define SGBSV_F77   F77_BLAS_MANGLE(sgbsv,SGBSV)
#define SGTTRF_F77  F77_BLAS_MANGLE(sgttrf,SGTTRF)
#define SGTTS2_F77  F77_BLAS_MANGLE(sgtts2,SGTTS2)
#define SGETRF_F77  F77_BLAS_MANGLE(sgetrf,SGETRF)
#define SGETRS_F77  F77_BLAS_MANGLE(sgetrs,SGETRS)
#define SGESVD_F77  F77_BLAS_MANGLE(sgesvd,SGESVD)
#define SGETRI_F77  F77_BLAS_MANGLE(sgetri,SGETRI)
#define SGERFS_F77  F77_BLAS_MANGLE(sgerfs,SGERFS)
#define SGECON_F77  F77_BLAS_MANGLE(sgecon,SGECON)
#define SGESVX_F77  F77_BLAS_MANGLE(sgesvx,SGESVX)
#define SGESV_F77   F77_BLAS_MANGLE(sgesv,SGESV)
#define SGEEQU_F77  F77_BLAS_MANGLE(sgeequ,SGEEQU)
#define SPOTRF_F77  F77_BLAS_MANGLE(spotrf,SPOTRF)
#define SPOTRS_F77  F77_BLAS_MANGLE(spotrs,SPOTRS)
#define SPOTRI_F77  F77_BLAS_MANGLE(spotri,SPOTRI)
#define SPOCON_F77  F77_BLAS_MANGLE(spocon,SPOCON)
#define SPOSV_F77   F77_BLAS_MANGLE(sposv,SPOSV)
#define SPOEQU_F77  F77_BLAS_MANGLE(spoequ,SPOEQU)
#define SPORFS_F77  F77_BLAS_MANGLE(sporfs,SPORFS)
#define SPOSVX_F77  F77_BLAS_MANGLE(sposvx,SPOSVX)
#define SGELS_F77   F77_BLAS_MANGLE(sgels,SGELS)
#define SGEEV_F77   F77_BLAS_MANGLE(sgeev,SGEEV)
#define SGEHRD_F77  F77_BLAS_MANGLE(sgehrd,SGEHRD)
#define SHSEQR_F77  F77_BLAS_MANGLE(shseqr,SHSEQR)
#define SORGHR_F77  F77_BLAS_MANGLE(sorghr,SORGHR)
#define SORMHR_F77  F77_BLAS_MANGLE(sormhr,SORMHR)
#define STREVC_F77  F77_BLAS_MANGLE(strevc,STREVC)
#define STREXC_F77  F77_BLAS_MANGLE(strexc,STREXC)
#define SLAMCH_F77  F77_BLAS_MANGLE(slamch,SLAMCH)
#define SGELSS_F77  F77_BLAS_MANGLE(sgelss,SGELSS)
#define SSTEV_F77   F77_BLAS_MANGLE(sstev,SSTEV)
#define SGEQPF_F77  F77_BLAS_MANGLE(sgeqpf,SGEQPF)

#define DLASWP_F77  F77_BLAS_MANGLE(dlaswp,DLASWP)
#define DLAIC1_F77  F77_BLAS_MANGLE(dlaic1,DLAIC1)


#ifdef __cplusplus
extern "C" {
#endif

/* Aztec-2.1 already defines these variables in header files */

#ifndef HAVE_ML_AZTEC2_1

  /* Double precision LAPACK linear solvers */
void PREFIX DGBSV_F77(const int *n, const int *m, const int *i, const int *k, double *a, const int *j, int *ipiv, double * b, const int *nn, int *info);
void PREFIX DGETRF_F77(const int* m, const int* n, double* a, const int* lda, int* ipiv, int* info);
void PREFIX DGTTRF_F77(const int* leng, double* a, double *b, double *c, double *d, int *e, int *info);
void PREFIX DGTTS2_F77(const int * itrans, const int* n, const int* nrhs, const double* a, const double* b,
                       const double* c, const double* d, const int* e, double* x, const int* ldx);
void PREFIX DGETRS_F77(ml_fcd, const int* n, const int* nrhs, const double* a,
                       const int* lda, const int* ipiv, double* x , const int* ldx, int* info);
void PREFIX DGESVD_F77(ml_fcd, ml_fcd, const int* m, const int* n, double* a,
                       const int* lda, double* s, double* u, const int* ldu, double* vt, const int* ldut,
		       double* work, const int* lwork, int* info);
void PREFIX DGETRI_F77(const int* n, double* a, const int* lda, const int*ipiv, double * work , const int* lwork, int* info);
void PREFIX DGECON_F77(ml_fcd norm, const int* n, const double* a, const int* lda,
                       const double *anorm, double * rcond, double * work,
                       int * iwork, int* info);
void PREFIX DGESV_F77(const int * n, const int * nrhs, double* a,
                       const int* lda, int*ipiv, double*x , const int* ldx, int* info);
void PREFIX DGEEQU_F77(const int* m, const int* n, const double* a, const int* lda, double * r, double * c,
			double * rowcnd, double * colcnd,
                       double * amax, int* info);
void PREFIX DGERFS_F77(ml_fcd, const int * n, const int * nrhs,  const double * a,
                       const int * lda, const double * af, const int * ldaf, const int*ipiv,
                       const double * b, const int * ldb, double * x, const int * ldx,
                       double * ferr, double * berr, double * work,
                       int * iwork, int * info);
void PREFIX DGESVX_F77(ml_fcd, ml_fcd, const int * n, const int * nrhs, double * a,
                       const int * lda, double * af, const int * ldaf, int*ipiv, char * equed,
                       double * r, double *c, double * b, const int * ldb, double * x, const int * ldx,
                       double * rcond, double * ferr, double * berr, double * work,
                       int * iwork, int * info);

void PREFIX DPOTRF_F77(ml_fcd, const int* n, double* a, const int* lda, int* info);
void PREFIX DPOTRS_F77(ml_fcd, const int * n, const int * nrhs, const double* a,
                       const int* lda, double*x , const int* ldx, int* info);
void PREFIX DPOTRI_F77(ml_fcd, const int* n, double* a, const int* lda, int* info);
void PREFIX DPOCON_F77(ml_fcd, const int* n, const double* a, const int* lda,
                       const double * anorm, double * rcond, double * work,
                       int * iwork, int* info);
void PREFIX DPOSV_F77(ml_fcd, const int * n, const int * nrhs, double* a,
                       const int* lda, double*x , const int* ldx, int* info);
void PREFIX DPOEQU_F77(const int* n, const double* a, const int* lda, double * s, double * scond,
                       double * amax, int* info);

void PREFIX DPORFS_F77(ml_fcd, const int * n, const int * nrhs, const double * a,
                       const int * lda, const double * af, const int * ldaf,
                       const double * b, const int * ldb, double * x, const int * ldx,
                       double * ferr, double * berr, double * work,
                       int * iwork, int * info);

void PREFIX DPOSVX_F77(ml_fcd, ml_fcd, const int * n, const int * nrhs, double * a,
                       const int * lda, double * af, const int * ldaf, char * equed,
                       double * s, double * b, const int * ldb, double * x, const int * ldx,
                       double * rcond, double * ferr, double * berr, double * work,
                       int * iwork, int * info);

void PREFIX DGELSS_F77(const int * m, const int * n, const int * nrhs, double * a,
				   const int * lda, double * b, const int * ldb, double * s,
				   const double * rcond, int * rank, double * work,
				   const int * lwork, int * info);

void PREFIX DGEQPF_F77(const int * m, const int * n, double * a,
				   const int * lda, int * jpvt, double * tau,
				   double * work, int * info);
/*
#define DGEQRF_F77  F77_BLAS_MANGLE(sgeqrf,SGEQRF)
#define DORGQR_F77  F77_BLAS_MANGLE(sorgqr,SORGQR)
*/
void PREFIX DGEQRF_F77(const int *, const int *, double *, const int *,
                 double *, double *, const int *, int *);

void PREFIX DORGQR_F77(const int *m, const int *n, const int *k, double * a,
                 const int *lda, const double *tau, double *work, const int *lwork,
                 int *info);
void PREFIX DSTEQR_F77(ml_fcd, const int *, double *, double *, double *, const int *,
                 double *, int *);

  /* Single precision LAPACK linear solvers*/
void PREFIX SGETRF_F77(const int* m, const int* n, float* a, const int* lda, int* ipiv, int* info);
void PREFIX SGETRS_F77(ml_fcd, const int* n, const int* nrhs, const float* a,
                       const int* lda, const int* ipiv, float* x , const int* ldx, int* info);
void PREFIX SGESVD_F77(ml_fcd, ml_fcd, const int* m, const int* n, float* a,
               const int* lda, float* s, float* u, const int* ldu, float* vt, const int* ldut,
               float* work, const int* lwork, int* info);
void PREFIX SGETRI_F77(const int* n, float* a, const int* lda, const int*ipiv, float * work , const int* lwork, int* info);
void PREFIX SGECON_F77(ml_fcd norm, const int* n, const float* a, const int* lda,
                       const float * anorm, float * rcond, float * work,
                       int * iwork, int* info);
void PREFIX SGESV_F77(const int * n, const int * nrhs, float* a,
                       const int* lda, int*ipiv, float*x , const int* ldx, int* info);
void PREFIX SGEEQU_F77(const int* m, const int* n, const float* a, const int* lda, float * r, float * c,
            float * rowcnd, float * colcnd,
            float * amax, int* info);
void PREFIX SGERFS_F77(ml_fcd, const int * n, const int * nrhs,  const float * a,
                       const int * lda, const float * af, const int * ldaf, const int*ipiv,
                       const float * b, const int * ldb, float * x, const int * ldx,
                       float * ferr, float * berr, float * work,
                       int * iwork, int * info);
void PREFIX SGESVX_F77(ml_fcd, ml_fcd, const int * n, const int * nrhs, float * a,
                       const int * lda, float * af, const int * ldaf, int*ipiv, char * equed,
                       float * r, float *c, float * b, const int * ldb, float * x, const int * ldx,
                       float * rcond, float * ferr, float * berr, float * work,
                       int * iwork, int * info);

void PREFIX SPOTRF_F77(ml_fcd, const int* n, float* a, const int* lda, int* info);
void PREFIX SPOTRS_F77(ml_fcd, const int * n, const int * nrhs, const float* a,
                       const int* lda, float*x , const int* ldx, int* info);
void PREFIX SPOTRI_F77(ml_fcd, const int* n, float* a, const int* lda, int* info);
void PREFIX SPOCON_F77(ml_fcd, const int* n, const float* a, const int* lda,
                       const float * anorm, float * rcond, float * work,
                       int * iwork, int* info);
void PREFIX SPOSV_F77(ml_fcd, const int * n, const int * nrhs, float* a,
                       const int* lda, float*x , const int* ldx, int* info);
void PREFIX SPOEQU_F77(const int* n, const float* a, const int* lda, float * s, float * scond,
                       float * amax, int* info);

void PREFIX SPORFS_F77(ml_fcd, const int * n, const int * nrhs, const float * a,
                       const int * lda, const float * af, const int * ldaf,
                       const float * b, const int * ldb, float * x, const int * ldx,
                       float * ferr, float * berr, float * work,
                       int * iwork, int * info);

void PREFIX SPOSVX_F77(ml_fcd, ml_fcd, const int * n, const int * nrhs, float * a,
                       const int * lda, float * af, const int * ldaf, char * equed,
                       float * s, float * b, const int * ldb, float * x, const int * ldx,
                       float * rcond, float * ferr, float * berr, float * work,
                       int * iwork, int * info);

void PREFIX SGELSS_F77(const int * m, const int * n, const int * nrhs, float * a,
                       const int * lda, float * b, const int * ldb, float * s,
                       const float * rcond, int * rank, float * work,
                       const int * lwork, int * info);

void PREFIX SGEQPF_F77(const int * m, const int * n, float * a,
                       const int * lda, int * jpvt, float * tau,
                       float * work, int * info);


  /* Double precision LAPACK eigen solvers*/
void PREFIX DGELS_F77(ml_fcd ch, const int*, const int*, const int*,
                       double*, const int*, double*, const int*, double*, const int*, int*);

void PREFIX DGEEV_F77(ml_fcd, ml_fcd, const int*, double*, const int*,
                      double*, double*, double*, const int*, double*, const int*,
                      double*, const int*, int*);

void PREFIX DGEHRD_F77(const int * n, const int * ilo, const int * ihi, double * A,
                        const int * lda, double * tau, double * work, const int * lwork,
                        int * info);

void PREFIX DHSEQR_F77(ml_fcd job, ml_fcd, const int * n, const int * ilo, const int * ihi,
                        double * h, const int * ldh, double * wr, double * wi, double * z,
                        const int * ldz, double * work, const int * lwork, int * info);

void PREFIX DORGHR_F77(const int * n, const int * ilo, const int * ihi, double * a, const int * lda, const double * tau,
                        double * work, const int * lwork, int * info);

void PREFIX DORMHR_F77(ml_fcd, ml_fcd, const int * m, const int * n, const int * ilo,
                        const int * ihi, const double * a, const int * lda, const double * tau, double * c,
                        const int * ldc, double * work, const int * lwork, int * info);

void PREFIX DTREVC_F77(ml_fcd, ml_fcd, int * select, const int * n, const double * t,
                        const int * ldt, double *vl, const int * ldvl, double * vr, const int * ldvr,
                        const int * mm, int * m, double * work, int * info);

void PREFIX DTREXC_F77(ml_fcd, const int * n, double * t, const int * ldt, double * q,
                        const int * ldq, int * ifst, int * ilst, double * work, int * info);

void PREFIX DSTEV_F77(ml_fcd jobz, const int * n, double * d,
                      double * e, double * z, const int * ldz,
                      double * work, int * info);

double PREFIX DLAMCH_F77(ml_fcd);


  /* Single precision LAPACK eigen solvers*/
void PREFIX SGELS_F77(ml_fcd, const int*, const int*, const int*,
                       float*, const int*, float*, const int*, float*, const int*, int*);

void PREFIX SGEEV_F77(ml_fcd, ml_fcd, const int*, float*, const int*,
                      float*, float*, float*, const int*, float*, const int*,
                      float*, const int*, int*);

void PREFIX SGEHRD_F77(const int * n, const int * ilo, const int * ihi, float * A,
                        const int * lda, float * tau, float * work, const int * lwork,
                        int * info);

void PREFIX SHSEQR_F77(ml_fcd job, ml_fcd, const int * n, const int * ilo, const int * ihi,
                        float * h, const int * ldh, float * wr, float * wi, float * z,
                        const int * ldz, float * work, const int * lwork, int * info);

void PREFIX SORGHR_F77(const int * n, const int * ilo, const int * ihi, float * a, const int * lda, const float * tau,
                        float * work, const int * lwork, int * info);

void PREFIX SORMHR_F77(ml_fcd, ml_fcd, const int * m, const int * n, const int * ilo,
                        const int * ihi, const float * a, const int * lda, const float * tau, float * c,
                        const int * ldc, float * work, const int * lwork, int * info);

void PREFIX STREVC_F77(ml_fcd, ml_fcd, int * select, const int * n, const float * t,
                        const int * ldt, float *vl, const int * ldvl, float * vr, const int * ldvr,
                        const int * mm, int * m, float * work, int * info);

void  PREFIX STREXC_F77(ml_fcd, const int * n, float * t, const int * ldt, float * q,
                        const int * ldq, int * ifst, int * ilst, float * work, int * info);

void PREFIX SSTEV_F77(ml_fcd jobz, const int * n, float * d,
                      float * e, float * z, const int * ldz,
                      float * work, int * info);

float  PREFIX SLAMCH_F77(ml_fcd);

#endif

#ifdef __cplusplus
}
#endif


/* Define fcd (Fortran ml_fcd descriptor) for non-standard situations */

#if defined(CRAY_T3X) || defined(INTEL_CXML) || defined(INTEL_MKL)


#if defined(CRAY_T3X)

#include <fortran.h>
#define PREFIX
#define ml_fcd fcd

#define DASUM_F77   F77_BLAS_MANGLE(sasum,SASUM)
#define DAXPY_F77   F77_BLAS_MANGLE(saxpy,SAXPY)
#define DCOPY_F77   F77_BLAS_MANGLE(scopy,SCOPY)
#define DDOT_F77    F77_BLAS_MANGLE(sdot,SDOT)
#define DNRM2_F77   F77_BLAS_MANGLE(snrm2,SNRM2)
#define DSCAL_F77   F77_BLAS_MANGLE(sscal,SSCAL)
#define IDAMAX_F77  F77_BLAS_MANGLE(isamax,ISAMAX)
#define DGEMV_F77   F77_BLAS_MANGLE(sgemv,SGEMV)
#define DGER_F77    F77_BLAS_MANGLE(sger,SGER)
#define DTRMV_F77   F77_BLAS_MANGLE(strmv,STRMV)
#define DGEMM_F77   F77_BLAS_MANGLE(sgemm,SGEMM)
#define DSYMM_F77   F77_BLAS_MANGLE(ssymm,SSYMM)
#define DTRMM_F77   F77_BLAS_MANGLE(strmm,STRMM)
#define DTRSM_F77   F77_BLAS_MANGLE(strsm,STRSM)

#elif defined(INTEL_CXML)

#define PREFIX __stdcall
#define ml_fcd char *, unsigned int

#define DASUM_F77   F77_BLAS_MANGLE(dasum,DASUM)
#define DAXPY_F77   F77_BLAS_MANGLE(daxpy,DAXPY)
#define DCOPY_F77   F77_BLAS_MANGLE(dcopy,DCOPY)
#define DDOT_F77    F77_BLAS_MANGLE(ddot,DDOT)
#define DNRM2_F77   F77_BLAS_MANGLE(dnrm2,DNRM2)
#define DSCAL_F77   F77_BLAS_MANGLE(dscal,DSCAL)
#define IDAMAX_F77  F77_BLAS_MANGLE(idamax,IDAMAX)
#define DGEMV_F77   F77_BLAS_MANGLE(dgemv,DGEMV)
#define DGER_F77    F77_BLAS_MANGLE(dger,DGER)
#define DTRMV_F77   F77_BLAS_MANGLE(dtrmv,DTRMV)
#define DGEMM_F77   F77_BLAS_MANGLE(dgemm,DGEMM)
#define DSYMM_F77   F77_BLAS_MANGLE(dsymm,DSYMM)
#define DTRMM_F77   F77_BLAS_MANGLE(dtrmm,DTRMM)
#define DTRSM_F77   F77_BLAS_MANGLE(dtrsm,DTRSM)


#elif defined(INTEL_MKL)

#define PREFIX
#define ml_fcd char *

#define DASUM_F77   F77_BLAS_MANGLE(dasum,DASUM)
#define DAXPY_F77   F77_BLAS_MANGLE(daxpy,DAXPY)
#define DCOPY_F77   F77_BLAS_MANGLE(dcopy,DCOPY)
#define DDOT_F77    F77_BLAS_MANGLE(ddot,DDOT)
#define DNRM2_F77   F77_BLAS_MANGLE(dnrm2,DNRM2)
#define DSCAL_F77   F77_BLAS_MANGLE(dscal,DSCAL)
#define IDAMAX_F77  F77_BLAS_MANGLE(idamax,IDAMAX)
#define DGEMV_F77   F77_BLAS_MANGLE(dgemv,DGEMV)
#define DGER_F77    F77_BLAS_MANGLE(dger,DGER)
#define DTRMV_F77   F77_BLAS_MANGLE(dtrmv,DTRMV)
#define DGEMM_F77   F77_BLAS_MANGLE(dgemm,DGEMM)
#define DSYMM_F77   F77_BLAS_MANGLE(dsymm,DSYMM)
#define DTRMM_F77   F77_BLAS_MANGLE(dtrmm,DTRMM)
#define DTRSM_F77   F77_BLAS_MANGLE(dtrsm,DTRSM)


#endif

/* All three of these machines use a simple uppercase mangling of Fortran names */

/* if F77_BLAS_MANGLE is defined undefine it because we want to redefine */

#ifdef F77_BLAS_MANGLE
#undef F77_BLAS_MANGLE
#endif


#define F77_BLAS_MANGLE(lcase,UCASE) UCASE

#else /* Define ml_fcd for all other machines */

#define PREFIX
#define ml_fcd const char *

/* Use autoconf's definition of F77_BLAS_MANGLE
   unless using old make system */

#ifdef TRILINOS_NO_CONFIG_H

#ifdef F77_BLAS_MANGLE
#undef F77_BLAS_MANGLE
#endif

#ifdef TRILINOS_HAVE_NO_FORTRAN_UNDERSCORE
#define F77_BLAS_MANGLE(lcase,UCASE) lcase
#else /* TRILINOS_HAVE_NO_FORTRAN_UNDERSCORE not defined*/
#define F77_BLAS_MANGLE(lcase,UCASE) lcase ## _
#endif /* TRILINOS_HAVE_NO_FORTRAN_UNDERSCORE */
#endif /* TRILINOS_NO_CONFIG_H */

#define DASUM_F77   F77_BLAS_MANGLE(dasum,DASUM)
#define DAXPY_F77   F77_BLAS_MANGLE(daxpy,DAXPY)
#define DCOPY_F77   F77_BLAS_MANGLE(dcopy,DCOPY)
#define DDOT_F77    F77_BLAS_MANGLE(ddot,DDOT)
#define DNRM2_F77   F77_BLAS_MANGLE(dnrm2,DNRM2)
#define DSCAL_F77   F77_BLAS_MANGLE(dscal,DSCAL)
#define IDAMAX_F77  F77_BLAS_MANGLE(idamax,IDAMAX)
#define DGEMV_F77   F77_BLAS_MANGLE(dgemv,DGEMV)
#define DGER_F77    F77_BLAS_MANGLE(dger,DGER)
#define DTRMV_F77   F77_BLAS_MANGLE(dtrmv,DTRMV)
#define DGEMM_F77   F77_BLAS_MANGLE(dgemm,DGEMM)
#define DSYMM_F77   F77_BLAS_MANGLE(dsymm,DSYMM)
#define DTRMM_F77   F77_BLAS_MANGLE(dtrmm,DTRMM)
#define DTRSM_F77   F77_BLAS_MANGLE(dtrsm,DTRSM)


#endif


#define SSCAL_F77   F77_BLAS_MANGLE(sscal,SSCAL)
#define SCOPY_F77   F77_BLAS_MANGLE(scopy,SCOPY)
#define SAXPY_F77   F77_BLAS_MANGLE(saxpy,SAXPY)
#define SDOT_F77    F77_BLAS_MANGLE(sdot,SDOT)
#define SNRM2_F77   F77_BLAS_MANGLE(snrm2,SNRM2)
#define SASUM_F77   F77_BLAS_MANGLE(sasum,SASUM)
#define ISAMAX_F77  F77_BLAS_MANGLE(isamax,ISAMAX)

#define SGEMV_F77   F77_BLAS_MANGLE(sgemv,SGEMV)
#define SGER_F77    F77_BLAS_MANGLE(sger,SGER)
#define STRMV_F77   F77_BLAS_MANGLE(strmv,STRMV)
#define SGEMM_F77   F77_BLAS_MANGLE(sgemm,SGEMM)
#define SSYMM_F77   F77_BLAS_MANGLE(ssymm,SSYMM)
#define STRMM_F77   F77_BLAS_MANGLE(strmm,STRMM)
#define STRSM_F77   F77_BLAS_MANGLE(strsm,STRSM)

/* Explicitly define each F77 name for all BLAS kernels */

#ifdef __cplusplus
extern "C" {
#endif

/* Aztec-2.1 already contains these definitions in the header files */
#ifndef HAVE_ML_AZTEC2_1
/* Double precision BLAS 1 */
double PREFIX DASUM_F77(const int* n, const double x[], const int* incx);
void PREFIX DAXPY_F77(const int* n, const double* alpha, const double x[], const int* incx, double y[], const int* incy);
void PREFIX DCOPY_F77(const int* n, const double *x, const int* incx, double *y, const int* incy);
double PREFIX DDOT_F77(const int* n, const double x[], const int* incx, const double y[], const int* incy);
double PREFIX DNRM2_F77(const int* n, const double x[], const int* incx);
void PREFIX DSCAL_F77(const int* n, const double* alpha, double *x, const int* incx);
int PREFIX IDAMAX_F77(const int* n, const double *x, const int* incx);

/* Single precision BLAS 1 */
float PREFIX SASUM_F77(const int* n, const float x[], const int* incx);
void PREFIX SAXPY_F77(const int* n, const float* alpha, const float x[], const int* incx, float y[], const int* incy);
void PREFIX SCOPY_F77(const int* n, const float *x, const int* incx, float *y, const int* incy);
float PREFIX SDOT_F77(const int* n, const float x[], const int* incx, const float y[], const int* incy);
float PREFIX SNRM2_F77(const int* n, const float x[], const int* incx);
void PREFIX SSCAL_F77(const int* n, const float* alpha, float *x, const int* incx);
int PREFIX ISAMAX_F77(const int* n, const float *x, const int* incx);

/* Double precision BLAS 2 */
void PREFIX DGEMV_F77(ml_fcd, const int* m, const int* n, const double* alpha, const double A[], const int* lda,
		       const double x[], const int* incx, const double* beta, double y[], const int* incy);
void PREFIX DTRMV_F77(ml_fcd, ml_fcd, ml_fcd, const int *n,
		      const double *a, const int *lda, double *x, const int *incx);
void PREFIX DGER_F77(const int *m, const int *n, const double *alpha, const double *x, const int *incx, const double *y,
		     const int *incy, double *a, const int *lda);


/* Single precision BLAS 2 */
void PREFIX SGEMV_F77(ml_fcd, const int* m, const int* n, const float* alpha, const float A[], const int* lda,
		       const float x[], const int* incx, const float* beta, float y[], const int* incy);
void PREFIX STRMV_F77(ml_fcd, ml_fcd, ml_fcd, const int *n,
		      const float *a, const int *lda, float *x, const int *incx);
void PREFIX SGER_F77(const int *m, const int *n, const float *alpha, const float *x, const int *incx, const float *y,
		     const int *incy, float *a, const int *lda);

/* Double precision BLAS 3 */
void PREFIX DGEMM_F77(ml_fcd, ml_fcd, const int *m, const int *
		      n, const int *k, const double *alpha, const double *a, const int *lda,
		      const double *b, const int *ldb, const double *beta, double *c, const int *ldc);
void PREFIX DSYMM_F77(ml_fcd, ml_fcd, const int *m, const int * n,
		      const double *alpha, const double *a, const int *lda,
		      const double *b, const int *ldb, const double *beta, double *c, const int *ldc);
void PREFIX DTRMM_F77(ml_fcd, ml_fcd, ml_fcd, ml_fcd,
		      const int *m, const int *n, const double *alpha, const double *a, const int * lda, double *b, const int *ldb);
void PREFIX DTRSM_F77(ml_fcd, ml_fcd, ml_fcd, ml_fcd,
		      const int *m, const int *n, const double *alpha, const double *a, const int *
		      lda, double *b, const int *ldb);

/* Single precision BLAS 3 */
void PREFIX SGEMM_F77(ml_fcd, ml_fcd, const int *m, const int *
		      n, const int *k, const float *alpha, const float *a, const int *lda,
		      const float *b, const int *ldb, const float *beta, float *c, const int *ldc);
void PREFIX SSYMM_F77(ml_fcd, ml_fcd, const int *m, const int * n,
		      const float *alpha, const float *a, const int *lda,
		      const float *b, const int *ldb, const float *beta, float *c, const int *ldc);
void PREFIX STRMM_F77(ml_fcd, ml_fcd, ml_fcd, ml_fcd,
		      const int *m, const int *n, const float *alpha, const float *a, const int * lda, float *b, const int *ldb);
void PREFIX STRSM_F77(ml_fcd, ml_fcd, ml_fcd, ml_fcd,
		      const int *m, const int *n, const float *alpha, const float *a, const int *
		      lda, float *b, const int *ldb);

void PREFIX XERBLA_F77(ml_fcd, int *info);

#endif

#ifdef __cplusplus
}
#endif

#endif /* ML_BLAS_LAPACK_WRAPPERS_H */
