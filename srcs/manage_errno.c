#include "strace.h"

int get_errno_name(int key)
{
	key = 0 - key;
	switch (key) {
		case ENOENT:
			return printf("ENOENT (%s)", strerror(ENOENT));
		case EPERM:
			return printf("EPERM (%s)", strerror(EPERM));
		case ESRCH:
			return printf("ESRCH (%s)", strerror(ESRCH));
		case EINTR:
			return printf("EINTR (%s)", strerror(EINTR));
		case EIO:
			return printf("EIO (%s)", strerror(EIO));
		case ENXIO:
			return printf("ENXIO (%s)", strerror(ENXIO));
		case E2BIG:
			return printf("E2BIG (%s)", strerror(E2BIG));
		case ENOEXEC:
			return printf("ENOEXEC (%s)", strerror(ENOEXEC));
		case EBADF:
			return printf("EBADF (%s)", strerror(EBADF));
		case ECHILD:
			return printf("ECHILD (%s)", strerror(ECHILD));
		case EDEADLK:
			return printf("EDEADLK (%s)", strerror(EDEADLK));
		case ENOMEM:
			return printf("ENOMEM (%s)", strerror(ENOMEM));
		case EACCES:
			return printf("EACCES (%s)", strerror(EACCES));
		case EFAULT:
			return printf("EFAULT (%s)", strerror(EFAULT));
		case ENOTBLK:
			return printf("ENOTBLK (%s)", strerror(ENOTBLK));
		case EBUSY:
			return printf("EBUSY (%s)", strerror(EBUSY));
		case EEXIST:
			return printf("EEXIST (%s)", strerror(EEXIST));
		case EXDEV:
			return printf("EXDEV (%s)", strerror(EXDEV));
		case ENODEV:
			return printf("ENODEV (%s)", strerror(ENODEV));
		case ENOTDIR:
			return printf("ENOTDIR (%s)", strerror(ENOTDIR));
		case EISDIR:
			return printf("EISDIR (%s)", strerror(EISDIR));
		case EINVAL:
			return printf("EINVAL (%s)", strerror(EINVAL));
		case EMFILE:
			return printf("EMFILE (%s)", strerror(EMFILE));
		case ENFILE:
			return printf("ENFILE (%s)", strerror(ENFILE));
		case ENOTTY:
			return printf("ENOTTY (%s)", strerror(ENOTTY));
		case ETXTBSY:
			return printf("ETXTBSY (%s)", strerror(ETXTBSY));
		case EFBIG:
			return printf("EFBIG (%s)", strerror(EFBIG));
		case ENOSPC:
			return printf("ENOSPC (%s)", strerror(ENOSPC));
		case ESPIPE:
			return printf("ESPIPE (%s)", strerror(ESPIPE));
		case EROFS:
			return printf("EROFS (%s)", strerror(EROFS));
		case EMLINK:
			return printf("EMLINK (%s)", strerror(EMLINK));
		case EPIPE:
			return printf("EPIPE (%s)", strerror(EPIPE));
		case EDOM:
			return printf("EDOM (%s)", strerror(EDOM));
		case ERANGE:
			return printf("ERANGE (%s)", strerror(ERANGE));
		case EAGAIN:
			return printf("EAGAIN (%s)", strerror(EAGAIN));
		case EINPROGRESS:
			return printf("EINPROGRESS (%s)", strerror(EINPROGRESS));
		case EALREADY:
			return printf("EALREADY (%s)", strerror(EALREADY));
		case ENOTSOCK:
			return printf("ENOTSOCK (%s)", strerror(ENOTSOCK));
		case EMSGSIZE:
			return printf("ENOTSOCK (%s)", strerror(ENOTSOCK));
		case EPROTOTYPE:
			return printf("EPROTOTYPE (%s)", strerror(EPROTOTYPE));
		case ENOPROTOOPT:
			return printf("ENOPROTOOPT (%s)", strerror(ENOPROTOOPT));
		case EPROTONOSUPPORT:
			return printf("EPROTONOSUPPORT (%s)", strerror(EPROTONOSUPPORT));
		case ESOCKTNOSUPPORT:
			return printf("ESOCKTNOSUPPORT (%s)", strerror(ESOCKTNOSUPPORT));
		case EOPNOTSUPP:
			return printf("EOPNOTSUPP (%s)", strerror(EOPNOTSUPP));
		case EPFNOSUPPORT:
			return printf("EPFNOSUPPORT (%s)", strerror(EPFNOSUPPORT));
		case EAFNOSUPPORT:
			return printf("EAFNOSUPPORT (%s)", strerror(EAFNOSUPPORT));
		case EADDRINUSE:
			return printf("EADDRINUSE (%s)", strerror(EADDRINUSE));
		case EADDRNOTAVAIL:
			return printf("EADDRNOTAVAIL (%s)", strerror(EADDRNOTAVAIL));
		case ENETDOWN:
			return printf("ENETDOWN (%s)", strerror(ENETDOWN));
		case ENETUNREACH:
			return printf("ENETUNREACH (%s)", strerror(ENETUNREACH));
		case ENETRESET:
			return printf("ENETRESET (%s)", strerror(ENETRESET));
		case ECONNABORTED:
			return printf("ECONNABORTED (%s)", strerror(ECONNABORTED));
		case ECONNRESET:
			return printf("ECONNRESET (%s)", strerror(ECONNRESET));
		case ENOBUFS:
			return printf("ENOBUFS (%s)", strerror(ENOBUFS));
		case EISCONN:
			return printf("EISCONN (%s)", strerror(EISCONN));
		case ENOTCONN:
			return printf("ENOTCONN (%s)", strerror(ENOTCONN));
		case EDESTADDRREQ:
			return printf("EDESTADDRREQ (%s)", strerror(EDESTADDRREQ));
		case ESHUTDOWN:
			return printf("ESHUTDOWN (%s)", strerror(ESHUTDOWN));
		case ETOOMANYREFS:
			return printf("ETOOMANYREFS (%s)", strerror(ETOOMANYREFS));
		case ETIMEDOUT:
			return printf("ETIMEDOUT (%s)", strerror(ETIMEDOUT));
		case ECONNREFUSED:
			return printf("ECONNREFUSED (%s)", strerror(ECONNREFUSED));
		case ELOOP:
			return printf("ELOOP (%s)", strerror(ELOOP));
		case ENAMETOOLONG:
			return printf("ENAMETOOLONG (%s)", strerror(ENAMETOOLONG));
		case EHOSTDOWN:
			return printf("EHOSTDOWN (%s)", strerror(EHOSTDOWN));
		case EHOSTUNREACH:
			return printf("EHOSTUNREACH (%s)", strerror(EHOSTUNREACH));
		case ENOTEMPTY:
			return printf("ENOTEMPTY (%s)", strerror(ENOTEMPTY));
		case EUSERS:
			return printf("EUSERS (%s)", strerror(EUSERS));
		case EDQUOT:
			return printf("EDQUOT (%s)", strerror(EDQUOT));
		case ESTALE:
			return printf("ESTALE (%s)", strerror(ESTALE));
		case EREMOTE:
			return printf("EREMOTE (%s)", strerror(EREMOTE));
		case ENOLCK:
			return printf("ENOLCK (%s)", strerror(ENOLCK));
		case ENOSYS:
			return printf("ENOSYS (%s)", strerror(ENOSYS));
		case EILSEQ:
			return printf("EILSEQ (%s)", strerror(EILSEQ));
		case EBADMSG:
			return printf("EBADMSG (%s)", strerror(EBADMSG));
		case EIDRM:
			return printf("EIDRM (%s)", strerror(EIDRM));
		case EMULTIHOP:
			return printf("EMULTIHOP (%s)", strerror(EMULTIHOP));
		case ENODATA:
			return printf("ENODATA (%s)", strerror(ENODATA));
		case ENOLINK:
			return printf("ENOLINK (%s)", strerror(ENOLINK));
		case ENOMSG:
			return printf("ENOMSG (%s)", strerror(ENOMSG));
		case ENOSR:
			return printf("ENOSR (%s)", strerror(ENOSR));
		case ENOSTR:
			return printf("ENOSTR (%s)", strerror(ENOSTR));
		case EOVERFLOW:
			return printf("EOVERFLOW (%s)", strerror(EOVERFLOW));
		case EPROTO:
			return printf("EPROTO (%s)", strerror(EPROTO));
		case ETIME:
			return printf("ETIME (%s)", strerror(ETIME));
		case ECANCELED:
			return printf("ECANCELED (%s)", strerror(ECANCELED));
		case EOWNERDEAD:
			return printf("EOWNERDEAD (%s)", strerror(EOWNERDEAD));
		case ENOTRECOVERABLE:
			return printf("ENOTRECOVERABLE (%s)", strerror(ENOTRECOVERABLE));
		case ERESTART:
			return printf("ERESTART (%s)", strerror(ERESTART));
		case ECHRNG:
			return printf("ECHRNG (%s)", strerror(ECHRNG));
		case EL2NSYNC:
			return printf("EL2NSYNC (%s)", strerror(EL2NSYNC));
		case EL3HLT:
			return printf("EL3HLT (%s)", strerror(EL3HLT));
		case EL3RST:
			return printf("EL3RST (%s)", strerror(EL3RST));
		case ELNRNG:
			return printf("ELNRNG (%s)", strerror(ELNRNG));
		case EUNATCH:
			return printf("EUNATCH (%s)", strerror(EUNATCH));
		case ENOCSI:
			return printf("ENOCSI (%s)", strerror(ENOCSI));
		case EL2HLT:
			return printf("EL2HLT (%s)", strerror(EL2HLT));
		case EBADE:
			return printf("EBADE (%s)", strerror(EBADE));
		case EBADR:
			return printf("EBADR (%s)", strerror(EBADR));
		case EXFULL:
			return printf("EXFULL (%s)", strerror(EXFULL));
		case ENOANO:
			return printf("ENOANO (%s)", strerror(ENOANO));
		case EBADRQC:
			return printf("EBADRQC (%s)", strerror(EBADRQC));
		case EBADSLT:
			return printf("EBADSLT (%s)", strerror(EBADSLT));
		case EBFONT:
			return printf("EBFONT (%s)", strerror(EBFONT));
		case ENONET:
			return printf("ENONET (%s)", strerror(ENONET));
		case ENOPKG:
			return printf("ENOPKG (%s)", strerror(ENOPKG));
		case EADV:
			return printf("EADV (%s)", strerror(EADV));
		case ESRMNT:
			return printf("ESRMNT (%s)", strerror(ESRMNT));
		case ECOMM:
			return printf("ECOMM (%s)", strerror(ECOMM));
		case EDOTDOT:
			return printf("EDOTDOT (%s)", strerror(EDOTDOT));
		case ENOTUNIQ:
			return printf("ENOTUNIQ (%s)", strerror(ENOTUNIQ));
		case EBADFD:
			return printf("EBADFD (%s)", strerror(EBADFD));
		case EREMCHG:
			return printf("EREMCHG (%s)", strerror(EREMCHG));
		case ELIBACC:
			return printf("ELIBACC (%s)", strerror(ELIBACC));
		case ELIBBAD:
			return printf("ELIBBAD (%s)", strerror(ELIBBAD));
		case ELIBSCN:
			return printf("ELIBSCN (%s)", strerror(ELIBSCN));
		case ELIBMAX:
			return printf("ELIBMAX (%s)", strerror(ELIBMAX));
		case ELIBEXEC:
			return printf("ELIBEXEC (%s)", strerror(ELIBEXEC));
		case ESTRPIPE:
			return printf("ESTRPIPE (%s)", strerror(ESTRPIPE));
		case EUCLEAN:
			return printf("EUCLEAN (%s)", strerror(EUCLEAN));
		case ENOTNAM:
			return printf("ENOTNAM (%s)", strerror(ENOTNAM));
		case ENAVAIL:
			return printf("ENAVAIL (%s)", strerror(ENAVAIL));
		case EISNAM:
			return printf("EISNAM (%s)", strerror(EISNAM));
		case EREMOTEIO:
			return printf("EREMOTEIO (%s)", strerror(EREMOTEIO));
		case ENOMEDIUM:
			return printf("ENOMEDIUM (%s)", strerror(ENOMEDIUM));
		case EMEDIUMTYPE:
			return printf("EMEDIUMTYPE (%s)", strerror(EMEDIUMTYPE));
		case ENOKEY:
			return printf("ENOKEY (%s)", strerror(ENOKEY));
		case EKEYEXPIRED:
			return printf("EKEYEXPIRED (%s)", strerror(EKEYEXPIRED));
		case EKEYREVOKED:
			return printf("EKEYREVOKED (%s)", strerror(EKEYREVOKED));
		case EKEYREJECTED:
			return printf("EKEYREJECTED (%s)", strerror(EKEYREJECTED));
		case ERFKILL:
			return printf("ERFKILL (%s)", strerror(ERFKILL));
		case EHWPOISON:
			return printf("EHWPOISON (%s)", strerror(EHWPOISON));
		default:
			return printf("errno not found");
	}
}
