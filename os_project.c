						//BANKERS ALGORITHM IN C PROGRAMMING LANGUAGE
#include<stdio.h>
#include<sys/types.h>
//Driver Code
int main()
{
	pid_t p,r,i,j,k;
	p = 5;   //Number of Processes P0,P1,P2,P3,P4  
	r = 3;	 //Number of Resources
	 	 
	//Allocation Array
	pid_t allocation[5][3] = {
								{0,1,0}, 
								{2,0,0},
								{3,0,2},
								{2,1,1},
								{0,0,2}	
							};
							
	//Max Array						
	pid_t max[5][3] = {
						{7,5,3},
						{3,2,2},
						{9,0,2},
						{2,2,2},
						{4,3,3}	
					};
					
	//Available Array
	pid_t available[3] = {3,3,2};
	
	//Need Array
	pid_t need[p][r];
	for(i=0;i<p;i++){
		for(j=0;j<r;j++){
			need[i][j] = max[i][j] - allocation[i][j];			
		}
	}
	
	//Process Array
	pid_t process[p];
	for(i=0;i<p;i++){
		process[i] = 0;
	}
	
	//Logic Part
	pid_t output[p],h=0,c=0;
	for(i=0;i<p;i++){
		for(j=0;j<p;j++){
			if(process[j] == 0){
				pid_t flag = 0;
				for(k=0;k<r;k++){
					if(need[j][k] > available[k]){
						flag = 1;
						break;
					}
				}
				
				if(flag == 0){
					output[h++] = j;
					for(c=0;c<r;c++){
						available[c] = available[c] + allocation[j][c];
					}
					process[j] = 1;
				}
			}
		}
	}
	
								//OUTPUT CUSTOMISATION
printf("\t\t\tRequired Safe Sequence is : ");			
for(i=0;i<p-1;i++){
	printf("P%d ->",output[i]);
}	
	printf("P%d",output[p-1]);						
}
