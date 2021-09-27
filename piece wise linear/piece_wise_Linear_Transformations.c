#include<stdio.h>
#include<math.h>
int img[600][600];
int out[600][600];

FILE *f1,*f2;
int i ,j,d;

int openfile(){
	f1=fopen("lena.txt","r");
	for(i=1;i<=512;i++)
	{
	 for(j=1;j<=512;j++)
	 {
	 fscanf(f1,"%d ",&d);
	 img[i][j]=d;
	 }  
	}
	fclose(f1);
 return 0;
}


int piece_wise_Linear_Transformations (){
	int x;
	for (i=1;i<=512;i++){
		for(j=1;j<=512;j++){
			x=img[i][j];
			if( x<50){
				out[i][j]=50;
			}
			if(x>150){
				out[i][j]=150;
			}

		}
	}
 return 0;
}

int outputfile(){
	f2=fopen("Piece-wise Linear Transformations.pgm","w");
  fprintf(f2,"P2 512 512 255\n");
    for(i=1;i<=512;i++)
	{
	 for(j=1;j<=512;j++)
	 {
	 	fprintf(f2,"%d ",out[i][j]);
	
	 }  
	 fprintf(f2,"\n");
}
  fclose(f2);
  return 0;

}

  int main()
{
	openfile();
	piece_wise_Linear_Transformations();
	outputfile();
  return 0;
}
  