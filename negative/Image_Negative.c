#include<stdio.h>
int img[600][600];
int out[600][600];

int i ,j,d;
FILE *f1,*f2;



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

int image_negative()
{
	for(i=1;i<=512;i++)
	{
	 for(j=1;j<=512;j++)
	 {
	   out[i][j]=255-img[i][j];// negative image
	 }  
  }
  return 0;

}
int outputfile(){
	f2=fopen("negative.pgm","w");

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
 image_negative();
 outputfile();
 
return 0;
}


