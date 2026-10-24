#include <iostream>

int randint(int min, int max)
{
    return min+(rand()%(max-min+1));
}

int**matrix(int min, int max, int rows, int cols)
{
   int**arr= new int*[rows];
   for(int i=0; i<rows;++i)
   {
    arr[i]=new int[cols];
   }

   for(int i=0; i<rows; ++i)
   {
    for(int j=0; j<cols; ++j)
    {
        arr[i][j]=randint(min, max);
    }
   }
   return arr;
}

void printmatrix(int**arr, int rows, int cols)
{
    for(int i=0; i<rows; ++i)
   {
    for(int j=0; j<cols; ++j)
    {
        std::cout<<arr[i][j]<<" ";
    }
    std::cout<<"\n";
   } 
}

void deletematrix(int**arr, int rows)
{
    for(int i=0; i<rows; ++i)
   {
    delete[]arr[i];
   } 
   delete[]arr;
}

int**transponirmatrix(int**arr, int rows, int cols)
{
    int**trarr= new int*[rows];
   for(int i=0; i<rows;++i)
   {
    trarr[i]=new int[cols];
   }

   for(int i=0; i<rows; ++i)
   {
    for(int j=0; j<cols; ++j)
    {
        trarr[i][j]=arr[j][i];
    }
   }
return trarr;
}



int main()
{
    int min=0;
    int max=5;
    int rows=6;
    int cols=4;
    int**M=nullptr;
    int**T=nullptr;


    std::cout<<"matrix:\n";
    M=matrix(min,max,rows,cols);
    printmatrix(M,rows,cols);


    std::cout<<"transponirovannaya matrix:\n";
    T=transponirmatrix(M,rows,cols);
    printmatrix(T,cols,rows);

    deletematrix(M,rows);
    deletematrix(T,cols);


    return 0;
}