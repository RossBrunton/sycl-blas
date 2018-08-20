#include "blas_test.hpp"
#include "../blas3_matrix_formats.hpp"

typedef ::testing::Types<
    blas_test_args<float, MatrixFormats<Conjugate, Normal>>
    #ifndef NO_DOUBLE_SUPPORT
    ,
    blas_test_args<double, MatrixFormats<Conjugate, Normal>>
    #endif
    > BlasTypes;

#define BlasTypes BlasTypes
#define TestName gemm_normal_normal

#include "blas3_gemm_def.hpp"