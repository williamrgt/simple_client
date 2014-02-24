#include <stdio.h>
#include <string.h>
#include "client.h"

int main(void)
{
	char buf[1024];
	unsigned char bin_data[1024];
	unsigned char value[1024];
	int buf_len;
	int i;

	memset(buf,0,sizeof(buf));
	memset(bin_data,0,sizeof(bin_data));
	memset(value,0,sizeof(value));

	printf(" BUFFER: ");
	fgets(buf,sizeof(buf),stdin);

	Asc_to_hexasc(buf,strlen(buf),value);
	Hex_to_bin(value,bin_data);

	//printf("bin_data=%02X%02X%02X%02X%02X\n",bin_data[0],bin_data[1],bin_data[2],bin_data[3],bin_data[4]);

	buf_len = strlen(value) / 2;
	memcpy(&buf[0],&bin_data[0],buf_len);

	if(simple_client(buf,buf_len) == 1);
		printf("BUFFER SENDED!\n");

	return 0;
}