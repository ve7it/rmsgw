#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netax25/ax25.h>
#include <netax25/axconfig.h>

int main( int argc, char *argv[])
{
	if( argc != 2 )
	{
		fprintf( stderr, "Usage: %s <portname>\n", argv[0]);
		return -1;
	}

	if( ax25_config_load_ports() == 0 )
	{
		fprintf( stderr, "Failed to load the AX.25 port configuration.\n");
		return -2;
	}

	const char *dev = ax25_config_get_dev( argv[1]);
	if( !dev )
	{
		fprintf( stderr, "Unable to find device for port %s.\n", argv[1]);
		return 1;
	}

	printf( "%s\n", dev);
	return 0;
}

