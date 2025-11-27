/*-------------------------------------------------------------------------
 *
 * pg_control.c
 *
 * Copyright (c) 2009-2025, NIPPON TELEGRAPH AND TELEPHONE CORPORATION
 *
 *-------------------------------------------------------------------------
 */

#include "c.h"
#include "../common.h"

#include <fcntl.h>
#include <unistd.h>

bool
readControlFile(ControlFileData *ctrl, const char *pgdata)
{
	char		path[MAXPGPATH];
	int			fd;
	pg_crc32	crc;

	snprintf(path, MAXPGPATH, "%s/global/pg_control", pgdata);

	if ((fd = open(path, O_RDONLY | PG_BINARY, 0)) == -1)
		return false;

	if (read(fd, ctrl, sizeof(ControlFileData)) != sizeof(ControlFileData))
		return false;
	close(fd);

	/* Check the CRC. */
	INIT_CRC32(crc);
	COMP_CRC32(crc,
			   (char *) ctrl,
			   offsetof(ControlFileData, crc));
	FIN_CRC32(crc);

	if (!EQ_CRC32(crc, ctrl->crc))
		return false;

	return true;
}
