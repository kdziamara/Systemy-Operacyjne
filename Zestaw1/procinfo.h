#ifndef PROCINFO_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define PROCINFO_H
#define _XOPEN_SOURCE 500

int procinfo(const char*);

#endif