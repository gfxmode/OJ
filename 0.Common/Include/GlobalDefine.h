#ifndef __GLOBAL_DEFINE_H__
#define __GLOBAL_DEFINE_H__

#define CHECK_NULL(ptr, ret) \
    { \
        if (NULL == ptr) \
        { \
            printf("ptr is null"); \
            return ret; \
        } \
    }

#endif // __GLOBAL_DEFINE_H__

