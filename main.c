#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(void) {
	int node,edge,cnt,i,j,a;
	char a1,b1;
	FILE *f;
	f=fopen("graph.gv","w");
	fputs("graph G {\n",f);
	printf("Enter a node:\n");
	scanf("%d", &node);
	int arr[node][node];
	printf("Enter:\n\t0 - if not connected \n\t1: eif connected\n\n");
	for( j=0; j<node; j++){
		a1='A';
		b1='A';
		a1=a1+j;
		for(i=0; i<node; i++){
			printf("Node %d connected to node %d node: ", j+1,i+1);
			scanf("%d", &a);
			if (arr[j][i]!=1){
				if (a==1){
					arr[j][i] =arr[i][j]= 1;
					fprintf(f,"%c--%c;\n",a1,b1);
				}
			if (a==0){
				arr[j][i]=0;
			}}
			b1++;
		}
	}
	for( j=0; j<node; j++){
		a1='A';
		b1='A';
		a1=a1+j;
		cnt=0;
		for(i=0; i<node; i++){
			if (arr[j][i]==0)
			cnt++;
			if (cnt==node) {
				fprintf(f,"%c\n",b1);
			}
			b1++;
		}
	}
	printf("\n\tAdjacency matrix:\n");
	for( i=0; i<node; i++){
		printf("\t");
		for( j=0; j<node; j++){
			printf("%2d ", arr[j][i]);
		}
		printf("\n");
	}
fputs("}",f);
fclose(f);
return 0;
}
