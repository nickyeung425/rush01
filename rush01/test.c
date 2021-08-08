#include <stdio.h>
#include <stdlib.h>           
int main(int argc, char* argv[]) //command line arguments
{
  int ***arr;                    //triple pointer
  int block,row,column;          //variables for block, rows and columns
  int i,j,k;                     //nested for loop
  printf("enter the blocks, rows and columns: ");
  scanf("%d %d %d",&block,&row,&column);
  arr=(int ***)malloc(sizeof(int ***)*block);
  for(i=0;i<block;i++) 
  {
    arr[i]=(int **)malloc(sizeof(int*)*row);
    for(j=0;j<row;j++) 
	{
      arr[i][j]=(int *)malloc(sizeof(int)*column);
    }
  }
  for(i=0;i<block;i++) 
  {
    for(j=0;j<row;j++) 
	{
      for(k=0;k<column;k++) 
	  {
        arr[i][j][k] = 1;
      }
    }
  }
  printf("Printing 3D Array:\n");
  for(i=0;i<block;i++) 
  {
    for(j=0;j<row;j++) 
	{
      for(k=0;k<column;k++) 
	  {
        printf("%.2d ",arr[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}