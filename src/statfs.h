#ifndef _IOS1COMPAT_STATFS_H_
#define _IOS1COMPAT_STATFS_H_

#include <string.h>
#include <sys/mount.h>

struct statfs32 {
  short f_otype;                 /* TEMPORARY SHADOW COPY OF f_type */
  short f_oflags;                /* TEMPORARY SHADOW COPY OF f_flags */
  long f_bsize;                  /* fundamental file system block size */
  long f_iosize;                 /* optimal transfer block size */
  long f_blocks;                 /* total data blocks in file system */
  long f_bfree;                  /* free blocks in fs */
  long f_bavail;                 /* free blocks avail to non-superuser */
  long f_files;                  /* total file nodes in file system */
  long f_ffree;                  /* free file nodes in fs */
  fsid_t f_fsid;                 /* file system id */
  uid_t f_owner;                 /* user that mounted the filesystem */
  short f_reserved1;             /* spare for later */
  short f_type;                  /* type of filesystem */
  long f_flags;                  /* copy of mount exported flags */
  long f_reserved2[2];           /* reserved for future use */
  char f_fstypename[MFSNAMELEN]; /* fs type name */
  char f_mntonname[MNAMELEN];    /* directory on which mounted */
  char f_mntfromname[MNAMELEN];  /* mounted filesystem */
  char f_reserved3;              /* For alignment */
  long f_reserved4[4];           /* For future use */
};

static inline void statfs_32_to_64(struct statfs *out, struct statfs32 *in) {
  out->f_bsize = in->f_bsize;
  out->f_iosize = in->f_iosize;
  out->f_blocks = in->f_blocks;
  out->f_bfree = in->f_bfree;
  out->f_bfree = in->f_bfree;
  out->f_bavail = in->f_bavail;
  out->f_files = in->f_files;
  out->f_ffree = in->f_ffree;
  out->f_fsid = in->f_fsid;
  out->f_owner = in->f_owner;
  out->f_type = in->f_type;
  out->f_flags = in->f_flags;
  out->f_fssubtype = in->f_reserved1;
  memcpy(out->f_fstypename, in->f_fstypename, MFSNAMELEN);
  memcpy(out->f_mntonname, in->f_mntonname, MNAMELEN);
  memcpy(out->f_mntfromname, in->f_mntfromname, MNAMELEN);
  bzero(out->f_reserved, sizeof(out->f_reserved));
}

#endif
