#ifndef __KSU_COMPAT_419_H
#define __KSU_COMPAT_419_H

#include <linux/string.h>
#include <linux/version.h>
#include <linux/uaccess.h>

/*
 * Linux 4.19 compatibility:
 * These *_nofault helpers are not available in the original
 * Samsung 4.19 kernel used by SM-A042F.
 *
 * The regular uaccess helpers already perform fault-safe user
 * memory access, so use them as compatibility implementations.
 */

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 8, 0)

#ifndef strncpy_from_user_nofault
#define strncpy_from_user_nofault(dst, src, count) \
	strncpy_from_user((dst), (src), (count))
#endif

#ifndef copy_from_user_nofault
#define copy_from_user_nofault(to, from, n) \
	copy_from_user((to), (from), (n))
#endif

#ifndef copy_to_user_nofault
#define copy_to_user_nofault(to, from, n) \
	copy_to_user((to), (from), (n))
#endif


#endif /* LINUX_VERSION_CODE < 5.8.0 */

#endif /* __KSU_COMPAT_419_H */

#ifndef copy_to_kernel_nofault
#define copy_to_kernel_nofault(to, from, n) ({ \
    memcpy((to), (from), (n)); \
    0; \
})
#endif
