#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "client.h"

/*
	Returns:
	0:  cant create socket
	-1: cant connect
	-2: cant send buf
	1: OK, buffer has been send

*/

int simple_client(char *buf, int size)
{
	int handle;
	struct sockaddr_in addr;

	memset(&addr,0,sizeof(struct sockaddr_in));

	addr.sin_family      = AF_INET;
	addr.sin_port        = htons(8800);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(&addr.sin_zero,0,sizeof(addr.sin_zero));

	handle = socket(AF_INET,SOCK_STREAM,0);
	if(!handle)
		return 0;

	if(connect(handle,(struct sockaddr*)&addr,sizeof(addr)) == -1)
		return -1;

	printf("CONECTED!\n");
	printf("SENDING BUFFER...\n\n");

	if(send(handle,(void *)buf,(size_t)size, 0) == -1);
		return -2;

	close(handle);
	return 1;

}

// convert 2 bytes hexas to 1 binary byte
unsigned short Hex_to_byte(unsigned char *buf, unsigned short default_value)
{
	unsigned short rc = 0;
	int i;
	for (i = 0; i < 2; i++)
	{
		rc = rc * 16;

		if ( (buf[i] >= '0') && (buf[i] <= '9') )
		{
			rc = rc + (buf[i] - '0');
		}
		else
		{
			if ( (buf[i] >= 'A') && (buf[i] <= 'F') )
			{
				rc = rc + (buf[i] - 'A') + 10;
			}
			else
				return default_value;
		}
	}
	return rc;
}

void Hex_to_bin(unsigned char * source, unsigned char * dest)
{
	int i,j,ch;

	for(i=0, j=0; source[i] != '\0'; i+=2, j++)
	{
		ch = Hex_to_byte(&source[i],0x00);
		sprintf(&dest[j],"%c",ch);
	}
}

void Byte_to_hex(unsigned char *dest, unsigned char  fonte)
{
	char lista[] = "0123456789ABCDEF";
	unsigned char octed1, octed2;

	octed1 = (fonte / 16) & 0x0F;
	octed2 = fonte & 0x0F;
	dest[0] = lista[octed1];
	dest[1] = lista[octed2];
	dest[2] = 0;
}

void Asc_to_hexasc(unsigned char * source, int sizeSource ,unsigned char * dest)
{
	int i,j;

	for(i=0, j=0; i < sizeSource; i++, j+=2)
	{
		Byte_to_hex(&dest[j],source[i]);
	}
}
