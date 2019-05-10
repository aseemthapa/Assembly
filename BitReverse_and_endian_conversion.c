#include <stdio.h>

extern unsigned int assembly_project(unsigned int,int);
//extern assembly_endian_conversion(unsigned int);

//int** binary_conv(int* a){
	//int binary[3][32],n,bin,i,j;
	
//	return binary;
//}

int main()
{
        unsigned int a[3];
	unsigned int x1[3];
	int binary[3][32];
	int n=0,bin=0;
	unsigned int y1[3];
	int i,j;
	
	for(i=0;i<3;i++){
		printf("Enter: ");
		scanf("%x",&a[i]);
	}

	//binary = binary_conv(a);
	for(i=0;i<3;i++){
		n = a[i];
		for (j=31;j>=0;j--){
			bin = n>>j;
			if (bin & 1) binary[i][31-j] = 1;
			else binary[i][31-j] = 0;
		}
	}
	for(i=0;i<3;i++){
		printf("array[%d]\t=  ",i);
		for(j=0;j<32;j++){
			printf("%d",binary[i][j]);
			
		}
		printf(",  %u,  %x\n",a[i],a[i]);
		//scanf("%x",&a[i]);
	}
	

	printf("Bit Reverse:\n");
	for(i=0;i<3;i++){		
		x1[i] = assembly_project(a[i],0); //0 for bit reverse
		//printf("array[%d]\t=\t%x,\t%u\n",i,x1[i],x1[i]);
	}

	for(i=0;i<3;i++){
		n = x1[i];
		for (j=31;j>=0;j--){
			bin = n>>j;
			if (bin & 1) binary[i][31-j] = 1;
			else binary[i][31-j] = 0;
		}
	}
	
	for(i=0;i<3;i++){
		printf("array[%d]\t=  ",i);
		for(j=0;j<32;j++){
			printf("%d",binary[i][j]);
			
		}
		printf(",  %u,  %x\n",x1[i],x1[i]);
		//scanf("%x",&a[i]);
	}
	
	printf("Endian Conversion:\n");

	for(i=0;i<3;i++){		
		y1[i] = assembly_project(a[i],1); //1 for endian conversion
		//printf("array[%d]\t=\t%x,\t%u\n",i,y1[i],y1[i]);
	}
	for(i=0;i<3;i++){
		n = y1[i];
		for (j=31;j>=0;j--){
			bin = n>>j;
			if (bin & 1) binary[i][31-j] = 1;
			else binary[i][31-j] = 0;
		}
	}
	
	for(i=0;i<3;i++){
		printf("array[%d]\t=  ",i);
		for(j=0;j<32;j++){
			printf("%d",binary[i][j]);
			
		}
		printf(",  %u,  %x\n",y1[i],y1[i]);
		//scanf("%x",&a[i]);
	}

	return 0;
}

