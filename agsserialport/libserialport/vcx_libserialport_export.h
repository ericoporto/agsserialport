
#ifndef SP_API_H
#define SP_API_H

#ifdef SP_LIBSERIALPORT_STATIC_DEFINE
#  define SP_API
#  define SP_PRIV
#else
#  ifndef SP_API
#    ifdef serialport_EXPORTS
        /* We are building this library */
#      define SP_API 
#    else
        /* We are using this library */
#      define SP_API 
#    endif
#  endif

#  ifndef SP_PRIV
#    define SP_PRIV 
#  endif
#endif

#ifndef SP_DEPR
#  define SP_DEPR __declspec(deprecated)
#endif

#ifndef SP_DEPR_EXPORT
#  define SP_DEPR_EXPORT SP_API SP_DEPR
#endif

#ifndef SP_DEPR_NO_EXPORT
#  define SP_DEPR_NO_EXPORT SP_PRIV SP_DEPR
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef SP_NO_DEPR
#    define SP_NO_DEPR
#  endif
#endif

#endif /* SP_API_H */
