#include <stdio.h>
struct sz_struct { int r; int c; };
typedef struct sz_struct  sz;

#define r1 2
#define c1 2
#define r2 2
#define c2 3
#define r3 4
#define c3 4

struct MatStruct{
    int* address;
    int r,c;
};

typedef struct MatStruct Matrix;

void printMat(Matrix mat){
    for(int i=0; i<mat.r; i++)
    {
        for(int j=0; j<mat.c; j++)
        {

            printf( "%d, ", *( mat.address + (i * mat.c + j) ) );

        }
        printf("\n");
    }
}

Matrix matrix_add(Matrix mat1, Matrix mat2){
    Matrix result;
    if( (mat1.r == mat2.r) && (mat1.c == mat2.c) ){
        result = mat1;

        for(int i=0; i<mat1.r; i++){
            for(int j=0; j<mat1.c; j++){
                *( result.address + (i * result.c + j) ) = 
                *( mat1.address + (i * mat1.c + j) ) +
                *( mat2.address + (i * mat2.c + j) );
            }
        }
    }else{
        printf("Given matrices are not compatible.\n");
    }
    return result;
}

Matrix matrix_sub(Matrix mat1, Matrix mat2){
    Matrix result;
    if( (mat1.r == mat2.r) && (mat1.c == mat2.c) ){
        result = mat1;

        for(int i=0; i<mat1.r; i++){
            for(int j=0; j<mat1.c; j++){
                *( result.address + (i * result.c + j) ) = 
                *( mat1.address + (i * mat1.c + j) ) -
                *( mat2.address + (i * mat2.c + j) );
            }
        }
    }else{
        printf("Given matrices are not compatible.\n");
    }
    return result;
}

Matrix matrix_mul(Matrix mat1, Matrix mat2){
    Matrix result;
    int sum;
    if( mat1.c == mat2.r )
    {
        result.r = mat1.r;
        result.c = mat2.c;
        for(int h=0; h<mat1.r; h++)
        {
            for(int i=0; i<mat2.c; i++)
            {
                sum = 0;

                for(int j=0; j<mat1.c; j++)
                {
                    sum += (    *( mat1.address + (h * mat1.c + j) )   )  *  (    *( mat2.address + (j * mat2.c + i) )   );
                }

                *( result.address + (h * result.c + i) ) = sum;
            }
        }
    }else{
        printf("Given matrices are not compatible.\n");
    }
    return result;
}

void co_mat(Matrix mat, int index, Matrix* return_mat){
    
}

int determinant(Matrix mat){
    
    printMat(mat);
    printf("\n");
    if(mat.r>1){
        Matrix mat2;
        mat2.r = mat.r-1;
        mat2.c = mat.c-1;
        int matArray2[mat2.r][mat2.c];
        int sum = 0;
        char sign = 1;
        int i2,j2;
        for(int h=0; h<mat.c; h++){
            i2 = 0;
            for(int i=1; i<mat.r; i++){
                j2 = 0;
                for(int j=0; j<mat.c; j++){
                    if(j!=h){
                        matArray2[i2][j2] = *( mat.address + (i * mat.c + j) );
                        j2++;
                    }
                }
                i2++;
            }
            mat2.address = matArray2[0];
            sum += sign * ( *( mat.address + (0 * mat.c + h) ) ) * determinant(mat2);
            sign*=-1;
        }
        return sum;
    }else{
        return *(mat.address);
    }
}

int main(){
    int matArray1[r1][c1] = {
                        {3,2},
                        {2,3}
                    };

    Matrix mat1 = {matArray1[0],r1,c1};

    int matArray2[r2][c2] = {
                        {1,2,3},
                        {4,5,6}
                    };
    
    Matrix mat2 = {matArray2[0],r2,c2};

    int matArray3[r3][c3] = {
                        {1,2,3,4},
                        {4,5,6,7},
                        {1,-2,-3,4},
                        {-4,5,6,7}
                    };
    
    Matrix mat3 = {matArray3[0],r3,c3};
    printf("%d\n",determinant(mat3));
    return 0;
}