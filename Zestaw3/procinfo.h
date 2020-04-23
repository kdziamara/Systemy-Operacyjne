#ifndef PROCINFO_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define PROCINFO_H
#define _XOPEN_SOURCE 500
#define _XOPEN_SOURCE_EXTENDED
#define _POSIX_C_SOURCE 200809L


int procinfo(const char*);

#endif