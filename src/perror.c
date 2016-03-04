#include "my_ls.h"
#include <errno.h>

/*
 * Taken from:
 * http://man7.org/linux/man-pages/man3/errno.3.html
 */

static int ERRNO_VALS[] = {
#ifdef E2BIG
    E2BIG,
#endif
#ifdef EACCES
    EACCES,
#endif
#ifdef EADDRINUSE
    EADDRINUSE,
#endif
#ifdef EADDRNOTAVAIL
    EADDRNOTAVAIL,
#endif
#ifdef EAFNOSUPPORT
    EAFNOSUPPORT,
#endif
#ifdef EAGAIN
    EAGAIN,
#endif
#ifdef EALREADY
    EALREADY,
#endif
#ifdef EBADE
    EBADE,
#endif
#ifdef EBADF
    EBADF,
#endif
#ifdef EBADFD
    EBADFD,
#endif
#ifdef EBADMSG
    EBADMSG,
#endif
#ifdef EBADR
    EBADR,
#endif
#ifdef EBADRQC
    EBADRQC,
#endif
#ifdef EBADSLT
    EBADSLT,
#endif
#ifdef EBUSY
    EBUSY,
#endif
#ifdef ECANCELED
    ECANCELED,
#endif
#ifdef ECHILD
    ECHILD,
#endif
#ifdef ECHRNG
    ECHRNG,
#endif
#ifdef ECOMM
    ECOMM,
#endif
#ifdef ECONNABORTED
    ECONNABORTED,
#endif
#ifdef ECONNREFUSED
    ECONNREFUSED,
#endif
#ifdef ECONNRESET
    ECONNRESET,
#endif
#ifdef EDEADLK
    EDEADLK,
#endif
#ifdef EDEADLOCK
    EDEADLOCK,
#endif
#ifdef EDESTADDRREQ
    EDESTADDRREQ,
#endif
#ifdef EDOM
    EDOM,
#endif
#ifdef EDQUOT
    EDQUOT,
#endif
#ifdef EEXIST
    EEXIST,
#endif
#ifdef EFAULT
    EFAULT,
#endif
#ifdef EFBIG
    EFBIG,
#endif
#ifdef EHOSTDOWN
    EHOSTDOWN,
#endif
#ifdef EHOSTUNREACH
    EHOSTUNREACH,
#endif
#ifdef EIDRM
    EIDRM,
#endif
#ifdef EILSEQ
    EILSEQ,
#endif
#ifdef EINPROGRESS
    EINPROGRESS,
#endif
#ifdef EINTR
    EINTR,
#endif
#ifdef EINVAL
    EINVAL,
#endif
#ifdef EIO
    EIO,
#endif
#ifdef EISCONN
    EISCONN,
#endif
#ifdef EISDIR
    EISDIR,
#endif
#ifdef EISNAM
    EISNAM,
#endif
#ifdef EKEYEXPIRED
    EKEYEXPIRED,
#endif
#ifdef EKEYREJECTED
    EKEYREJECTED,
#endif
#ifdef EKEYREVOKED
    EKEYREVOKED,
#endif
#ifdef EL2HLT
    EL2HLT,
#endif
#ifdef EL2NSYNC
    EL2NSYNC,
#endif
#ifdef EL3HLT
    EL3HLT,
#endif
#ifdef EL3RST
    EL3RST,
#endif
#ifdef ELIBACC
    ELIBACC,
#endif
#ifdef ELIBBAD
    ELIBBAD,
#endif
#ifdef ELIBMAX
    ELIBMAX,
#endif
#ifdef ELIBSCN
    ELIBSCN,
#endif
#ifdef ELIBEXEC
    ELIBEXEC,
#endif
#ifdef ELOOP
    ELOOP,
#endif
#ifdef EMEDIUMTYPE
    EMEDIUMTYPE,
#endif
#ifdef EMFILE
    EMFILE,
#endif
#ifdef EMLINK
    EMLINK,
#endif
#ifdef EMSGSIZE
    EMSGSIZE,
#endif
#ifdef EMULTIHOP
    EMULTIHOP,
#endif
#ifdef ENAMETOOLONG
    ENAMETOOLONG,
#endif
#ifdef ENETDOWN
    ENETDOWN,
#endif
#ifdef ENETRESET
    ENETRESET,
#endif
#ifdef ENETUNREACH
    ENETUNREACH,
#endif
#ifdef ENFILE
    ENFILE,
#endif
#ifdef ENOBUFS
    ENOBUFS,
#endif
#ifdef ENODATA
    ENODATA,
#endif
#ifdef ENODEV
    ENODEV,
#endif
#ifdef ENOENT
    ENOENT,
#endif
#ifdef ENOEXEC
    ENOEXEC,
#endif
#ifdef ENOKEY
    ENOKEY,
#endif
#ifdef ENOLCK
    ENOLCK,
#endif
#ifdef ENOLINK
    ENOLINK,
#endif
#ifdef ENOMEDIUM
    ENOMEDIUM,
#endif
#ifdef ENOMEM
    ENOMEM,
#endif
#ifdef ENOMSG
    ENOMSG,
#endif
#ifdef ENONET
    ENONET,
#endif
#ifdef ENOPKG
    ENOPKG,
#endif
#ifdef ENOPROTOOPT
    ENOPROTOOPT,
#endif
#ifdef ENOSPC
    ENOSPC,
#endif
#ifdef ENOSR
    ENOSR,
#endif
#ifdef ENOSTR
    ENOSTR,
#endif
#ifdef ENOSYS
    ENOSYS,
#endif
#ifdef ENOTBLK
    ENOTBLK,
#endif
#ifdef ENOTCONN
    ENOTCONN,
#endif
#ifdef ENOTDIR
    ENOTDIR,
#endif
#ifdef ENOTEMPTY
    ENOTEMPTY,
#endif
#ifdef ENOTSOCK
    ENOTSOCK,
#endif
#ifdef ENOTSUP
    ENOTSUP,
#endif
#ifdef ENOTTY
    ENOTTY,
#endif
#ifdef ENOTUNIQ
    ENOTUNIQ,
#endif
#ifdef ENXIO
    ENXIO,
#endif
#ifdef EOPNOTSUPP
    EOPNOTSUPP,
#endif
#ifdef EOVERFLOW
    EOVERFLOW,
#endif
#ifdef EPERM
    EPERM,
#endif
#ifdef EPFNOSUPPORT
    EPFNOSUPPORT,
#endif
#ifdef EPIPE
    EPIPE,
#endif
#ifdef EPROTO
    EPROTO,
#endif
#ifdef EPROTONOSUPPORT
    EPROTONOSUPPORT,
#endif
#ifdef EPROTOTYPE
    EPROTOTYPE,
#endif
#ifdef ERANGE
    ERANGE,
#endif
#ifdef EREMCHG
    EREMCHG,
#endif
#ifdef EREMOTE
    EREMOTE,
#endif
#ifdef EREMOTEIO
    EREMOTEIO,
#endif
#ifdef ERESTART
    ERESTART,
#endif
#ifdef EROFS
    EROFS,
#endif
#ifdef ESHUTDOWN
    ESHUTDOWN,
#endif
#ifdef ESPIPE
    ESPIPE,
#endif
#ifdef ESOCKTNOSUPPORT
    ESOCKTNOSUPPORT,
#endif
#ifdef ESRCH
    ESRCH,
#endif
#ifdef ESTALE
    ESTALE,
#endif
#ifdef ESTRPIPE
    ESTRPIPE,
#endif
#ifdef ETIME
    ETIME,
#endif
#ifdef ETIMEDOUT
    ETIMEDOUT,
#endif
#ifdef ETXTBSY
    ETXTBSY,
#endif
#ifdef EUCLEAN
    EUCLEAN,
#endif
#ifdef EUNATCH
    EUNATCH,
#endif
#ifdef EUSERS
    EUSERS,
#endif
#ifdef EWOULDBLOCK
    EWOULDBLOCK,
#endif
#ifdef EXDEV
    EXDEV,
#endif
#ifdef EXFULL
    EXFULL
#endif
};

static char *ERRNO_MSGS[] = {
#ifdef E2BIG
    "Argument list too long", 
#endif
#ifdef EACCES
    "Permission denied", 
#endif
#ifdef EADDRINUSE
    "Address already in use", 
#endif
#ifdef EADDRNOTAVAIL
    "Address not available", 
#endif
#ifdef EAFNOSUPPORT
    "Address family not supported", 
#endif
#ifdef EAGAIN
    "Resource temporarily unavailable", 
#endif
#ifdef EALREADY
    "Connection already in progress", 
#endif
#ifdef EBADE
    "Invalid exchange", 
#endif
#ifdef EBADF
    "Bad file descriptor", 
#endif
#ifdef EBADFD
    "File descriptor in bad state", 
#endif
#ifdef EBADMSG
    "Bad message", 
#endif
#ifdef EBADR
    "Invalid request descriptor", 
#endif
#ifdef EBADRQC
    "Invalid request code", 
#endif
#ifdef EBADSLT
    "Invalid slot", 
#endif
#ifdef EBUSY
    "Device or resource busy", 
#endif
#ifdef ECANCELED
    "Operation canceled", 
#endif
#ifdef ECHILD
    "No child processes", 
#endif
#ifdef ECHRNG
    "Channel number out of range", 
#endif
#ifdef ECOMM
    "Communication error on send", 
#endif
#ifdef ECONNABORTED
    "Connection aborted", 
#endif
#ifdef ECONNREFUSED
    "Connection refused", 
#endif
#ifdef ECONNRESET
    "Connection reset", 
#endif
#ifdef EDEADLK
    "Resource deadlock avoided", 
#endif
#ifdef EDEADLOCK
    "Synonym for EDEADLK", 
#endif
#ifdef EDESTADDRREQ
    "Destination address required", 
#endif
#ifdef EDOM
    "Mathematics argument out of domain of function", 
#endif
#ifdef EDQUOT
    "Disk quota exceeded", 
#endif
#ifdef EEXIST
    "File exists", 
#endif
#ifdef EFAULT
    "Bad address", 
#endif
#ifdef EFBIG
    "File too large", 
#endif
#ifdef EHOSTDOWN
    "Host is down", 
#endif
#ifdef EHOSTUNREACH
    "Host is unreachable", 
#endif
#ifdef EIDRM
    "Identifier removed", 
#endif
#ifdef EILSEQ
    "Illegal byte sequence", 
#endif
#ifdef EINPROGRESS
    "Operation in progress", 
#endif
#ifdef EINTR
    "Interrupted function call;", 
#endif
#ifdef EINVAL
    "Invalid argument", 
#endif
#ifdef EIO
    "Input/output error", 
#endif
#ifdef EISCONN
    "Socket is connected", 
#endif
#ifdef EISDIR
    "Is a directory", 
#endif
#ifdef EISNAM
    "Is a named type file", 
#endif
#ifdef EKEYEXPIRED
    "Key has expired", 
#endif
#ifdef EKEYREJECTED
    "Key was rejected by service", 
#endif
#ifdef EKEYREVOKED
    "Key has been revoked", 
#endif
#ifdef EL2HLT
    "Level 2 halted", 
#endif
#ifdef EL2NSYNC
    "Level 2 not synchronized", 
#endif
#ifdef EL3HLT
    "Level 3 halted", 
#endif
#ifdef EL3RST
    "Level 3 halted", 
#endif
#ifdef ELIBACC
    "Cannot access a needed shared library", 
#endif
#ifdef ELIBBAD
    "Accessing a corrupted shared library", 
#endif
#ifdef ELIBMAX
    "Attempting to link in too many shared libraries", 
#endif
#ifdef ELIBSCN
    "lib section in a.out corrupted", 
#endif
#ifdef ELIBEXEC
    "Cannot exec a shared library directly", 
#endif
#ifdef ELOOP
    "Too many levels of symbolic links", 
#endif
#ifdef EMEDIUMTYPE
    "Wrong medium type", 
#endif
#ifdef EMFILE
    "Too many open files;", 
#endif
#ifdef EMLINK
    "Too many links", 
#endif
#ifdef EMSGSIZE
    "Message too long", 
#endif
#ifdef EMULTIHOP
    "Multihop attempted", 
#endif
#ifdef ENAMETOOLONG
    "Filename too long", 
#endif
#ifdef ENETDOWN
    "Network is down", 
#endif
#ifdef ENETRESET
    "Connection aborted by network", 
#endif
#ifdef ENETUNREACH
    "Network unreachable", 
#endif
#ifdef ENFILE
    "Too many open files in system", 
#endif
#ifdef ENOBUFS
    "No buffer space available", 
#endif
#ifdef ENODATA
    "No message is available on the STREAM head read queue", 
#endif
#ifdef ENODEV
    "No such device", 
#endif
#ifdef ENOENT
    "No such file or directory", 
#endif
#ifdef ENOEXEC
    "Exec format error", 
#endif
#ifdef ENOKEY
    "Required key not available", 
#endif
#ifdef ENOLCK
    "No locks available", 
#endif
#ifdef ENOLINK
    "Link has been severed", 
#endif
#ifdef ENOMEDIUM
    "No medium found", 
#endif
#ifdef ENOMEM
    "Not enough space", 
#endif
#ifdef ENOMSG
    "No message of the desired type", 
#endif
#ifdef ENONET
    "Machine is not on the network", 
#endif
#ifdef ENOPKG
    "Package not installed", 
#endif
#ifdef ENOPROTOOPT
    "Protocol not available", 
#endif
#ifdef ENOSPC
    "No space left on device", 
#endif
#ifdef ENOSR
    "No STREAM resources", 
#endif
#ifdef ENOSTR
    "Not a STREAM", 
#endif
#ifdef ENOSYS
    "Function not implemented", 
#endif
#ifdef ENOTBLK
    "Block device required", 
#endif
#ifdef ENOTCONN
    "The socket is not connected", 
#endif
#ifdef ENOTDIR
    "Not a directory", 
#endif
#ifdef ENOTEMPTY
    "Directory not empty", 
#endif
#ifdef ENOTSOCK
    "Not a socket", 
#endif
#ifdef ENOTSUP
    "Operation not supported", 
#endif
#ifdef ENOTTY
    "Inappropriate I/O control operation", 
#endif
#ifdef ENOTUNIQ
    "Name not unique on network", 
#endif
#ifdef ENXIO
    "No such device or address", 
#endif
#ifdef EOPNOTSUPP
    "Operation not supported on socket", 
#endif
#ifdef EOVERFLOW
    "Value too large to be stored in data type", 
#endif
#ifdef EPERM
    "Operation not permitted", 
#endif
#ifdef EPFNOSUPPORT
    "Protocol family not supported", 
#endif
#ifdef EPIPE
    "Broken pipe", 
#endif
#ifdef EPROTO
    "Protocol error", 
#endif
#ifdef EPROTONOSUPPORT
    "Protocol not supported", 
#endif
#ifdef EPROTOTYPE
    "Protocol wrong type for socket", 
#endif
#ifdef ERANGE
    "Result too large", 
#endif
#ifdef EREMCHG
    "Remote address changed", 
#endif
#ifdef EREMOTE
    "Object is remote", 
#endif
#ifdef EREMOTEIO
    "Remote I/O error", 
#endif
#ifdef ERESTART
    "Interrupted system call should be restarted", 
#endif
#ifdef EROFS
    "Read-only filesystem", 
#endif
#ifdef ESHUTDOWN
    "Cannot send after transport endpoint shutdown", 
#endif
#ifdef ESPIPE
    "Invalid seek", 
#endif
#ifdef ESOCKTNOSUPPORT
    "Socket type not supported", 
#endif
#ifdef ESRCH
    "No such process", 
#endif
#ifdef ESTALE
    "Stale file handle", 
#endif
#ifdef ESTRPIPE
    "Streams pipe error", 
#endif
#ifdef ETIME
    "Timer expired", 
#endif
#ifdef ETIMEDOUT
    "Connection timed out", 
#endif
#ifdef ETXTBSY
    "Text file busy", 
#endif
#ifdef EUCLEAN
    "Structure needs cleaning", 
#endif
#ifdef EUNATCH
    "Protocol driver not attached", 
#endif
#ifdef EUSERS
    "Too many users", 
#endif
#ifdef EWOULDBLOCK
    "Operation would block", 
#endif
#ifdef EXDEV
    "Improper link", 
#endif
#ifdef EXFULL
    "Exchange full" 
#endif
};

void my_perror(char *str)
{
    int errindex;

    my_puterr(str);
    my_puterr(": ");
    errindex = int_in_arr(errno, ERRNO_VALS, ARRLEN(ERRNO_VALS));
    if (errindex == -1)
        my_puterr("Unknown error");
    else
        my_puterr(ERRNO_MSGS[errindex]);
    my_putstr(".\n");
}
