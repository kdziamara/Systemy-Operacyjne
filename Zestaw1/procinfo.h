#ifndef PROCINFO_H
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

#define PROCINFO_H

int procinfo(const char*);

#endif