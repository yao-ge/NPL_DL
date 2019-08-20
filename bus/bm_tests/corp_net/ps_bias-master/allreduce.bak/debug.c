#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>

FILE *log_fp = 0;

void log_init()
{
    log_fp = fopen("/home/log.txt", "w");

}
void log_print(const char *format, ...)
{
    if(log_fp==0)
        log_init();
    va_list list;
    va_start(list, format);
    vfprintf(log_fp, format, list);
    va_end(list);
    fflush(log_fp);
}


void log_end()
{
    fclose(log_fp);

}
