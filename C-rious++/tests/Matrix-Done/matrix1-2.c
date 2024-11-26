#include <stdio.h>
#include <math.h>
struct sz_struct { int r; int c; };
typedef struct sz_struct  sz;

#define r1 2
#define c1 2
#define r2 2
#define c2 3
#define r3 8
#define c3 8

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

void co_mat(Matrix mat, int index_i,int index_j, int* co_array){
    int i2,j2;
    i2 = 0;
    for(int i=0; i<mat.r; i++){
        if( i!= index_i ){
            j2 = 0;
            for(int j=0; j<mat.c; j++){
                if( (j!=index_j) ){
                    *( co_array + (i2 * (mat.c-1) + j2) ) = *( mat.address + (i * mat.c + j) );
                    j2++;
                }
            }
            i2++;
        }
    }
}

int determinant(Matrix mat){
    if(mat.r>1){
        Matrix mat2;
        mat2.r = mat.r-1;
        mat2.c = mat.c-1;
        int matArray2[mat2.r][mat2.c];
        mat2.address = matArray2[0];
        int sum = 0;
        char sign = 1;
        for(int h=0; h<mat.c; h++){
            co_mat(mat,0,h,mat2.address);
            sum += sign * ( *( mat.address + (0 * mat.c + h) ) ) * determinant(mat2);
            sign*=-1;
        }
        return sum;
    }else{
        return *(mat.address);
    }
}

void adjoint(Matrix mat, int* adj){
    Matrix mat2;
    mat2.r = mat.r-1;
    mat2.c = mat.c-1;
    int matArray2[mat2.r][mat2.c];
    mat2.address = matArray2[0];
     for(int i=0; i<mat.r; i++){
        for(int j=0; j<mat.c; j++){
            co_mat(mat,i,j,mat2.address);
            *( adj+ (j * mat.c + i) ) = pow(-1,i+j) * determinant(mat2);
        }
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
                        {1,2,3,4,1,2,3,4},
                        {4,5,6,7,1,2,3,4},
                        {1,-2,-3,4,4,5,-6,7},
                        {1,2,3,-4,1,2,3,4},
                        {4,-5,2,3,4,6,7,1},
                        {1,4,3,-4,2,-3,6,7},
                        {1,4,4,5,-2,-3,6,7},
                        {-4,5,6,7,7,4,5,6}
                    };

    Matrix mat3 = {matArray3[0],r3,c3};
    

    int matArray3_adj[r3][c3];
    Matrix mat4 = {matArray3_adj[0],r3,c3};


    adjoint(mat3,mat4.address);
    printf("%d\n",determinant(mat1));
    printMat(mat4);
    return 0;
}