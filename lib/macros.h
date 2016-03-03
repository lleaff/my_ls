#ifndef MACROS_H
#define MACROS_H

#ifndef MIN
#define MIN(x, y) ((x) > (y) ? (y) : (x))
#endif /* MIN */

#ifndef MAX
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#endif /* MAX */

#ifndef STRLEN
#define STRLEN(s) (sizeof(s) - 1)
#endif /* STRLEN */

#endif /* MACROS_H */
