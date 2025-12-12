/*
 * lib/libstatsinfo.h
 *
 * Copyright (c) 2009-2025, NTT, Inc.
 */

#ifndef LIBSTATSINFO_H
#define LIBSTATSINFO_H

#include "postgres.h"
#include "access/hash.h"

#ifdef WIN32
extern ssize_t readlink(const char *path, char *target, size_t size);
extern pid_t getppid(void);
#endif

extern pid_t	forkexec(const char *cmd, int *outStdin);
extern bool		get_diskspace(const char *path, int64 *total, int64 *avail);

extern int		wait_sampling_max;
extern bool		wait_sampling_save;

extern int		rusage_max;     /* max entries. TODO: Sould use same setting of pg_stat_statements.max */
extern bool		rusage_save;
extern int		rusage_track;	/* tracking level */
extern bool		rusage_track_planning;	/* whether to track planning duration */
extern bool		rusage_track_utility;	/* whether to track utility duration */

extern HTAB		*wait_sampling_hash;

#endif   /* LIBSTATSINFO_H */
