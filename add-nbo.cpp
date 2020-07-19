#include<stdio.h>
#include<stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
//#include <Winsock2.h>
#include<netinet/in.h>

int main(int argc, char* argv[]){

	if(argc < 3){
		printf("Usage : %s <filename1> <filename2>\n", argv[0]);
	}
	FILE *fd[2];
	uint32_t input1, input2;

	fd[0]=fopen(argv[1],"rb");
	fd[1]=fopen(argv[2],"rb");

	fread(&input1,sizeof(uint32_t),1,fd[0]);
	fread(&input2,sizeof(uint32_t),1,fd[1]);

	input1=htonl(input1);
	input2=htonl(input2);
	printf("%d(0x%x)+%d(0x%x)=%d(0x%x)\n", input1,input1, input2,input2, input1+input2,input1+input2);

	fclose(fd[1]);
	fclose(fd[0]);
}
