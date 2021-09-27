#include<stdio.h>
#include<math.h>
int img[600][600];
int out[600][600];

FILE *f1,*f2;
int i ,j,d,c=5;



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


int Log_Transformation(){
	for(i=1;i<=512;i++)
	{
	 for(j=1;j<=512;j++)
	 {
	   out[i][j]=c*log(1+img[i][j]); 
	   if (out[i][j]>255){
	   	out[i][j]=255;

	   }
	   if(out[i][j]<0){
	   	out[i][j]=0;
	   }


	 }  
  }
 return 0;
}

int outputfile(){
	f2=fopen("Log Transformations.pgm","w");
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
	Log_Transformation();
	outputfile();
  return 0;
}
  
  