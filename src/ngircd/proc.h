/*
 * ngIRCd -- The Next Generation IRC Daemon
 * Copyright (c)2001-2010 Alexander Barton (alex@barton.de)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * Please read the file COPYING, README and AUTHORS for more information.
 *
 * Process management (header)
 */

#ifndef __proc_h__
#define __proc_h__

/* This struct must not be accessed directly! */
typedef struct _Proc_Stat {
	pid_t pid;	/* PID of the child process or 0 if none */
	int pipe_fd;	/* Pipe file descriptor or -1 if none */
} PROC_STAT;

#define Proc_InProgress(x)	((x)->pid != 0)
#define Proc_GetPipeFd(x)	((x)->pipe_fd)

GLOBAL void Proc_InitStruct PARAMS((PROC_STAT *proc));

GLOBAL pid_t Proc_Fork PARAMS((PROC_STAT *proc, int *pipefds,
			       void (*cbfunc)(int, short)));

GLOBAL void Proc_Kill PARAMS((PROC_STAT *proc));

#endif

/* -eof- */