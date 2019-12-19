#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
#define check_error(return_val,msg){ \
	if(return_val != 0){	\
		fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
		exit(-1);\
	}\
}
