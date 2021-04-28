#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.styles"), aligned (8)))
#else
# define SECTION
#endif

#ifdef _MSC_VER
static const SECTION union { const guint8 data[557]; const double alignment; void * const ptr;}  styles_resource_data = { {
  0107, 0126, 0141, 0162, 0151, 0141, 0156, 0164, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 
  0030, 0000, 0000, 0000, 0254, 0000, 0000, 0000, 0000, 0000, 0000, 0050, 0005, 0000, 0000, 0000, 
  0000, 0000, 0000, 0000, 0001, 0000, 0000, 0000, 0003, 0000, 0000, 0000, 0005, 0000, 0000, 0000, 
  0005, 0000, 0000, 0000, 0324, 0265, 0002, 0000, 0377, 0377, 0377, 0377, 0254, 0000, 0000, 0000, 
  0001, 0000, 0114, 0000, 0260, 0000, 0000, 0000, 0264, 0000, 0000, 0000, 0156, 0073, 0232, 0243, 
  0002, 0000, 0000, 0000, 0264, 0000, 0000, 0000, 0013, 0000, 0166, 0000, 0300, 0000, 0000, 0000, 
  0004, 0002, 0000, 0000, 0012, 0113, 0040, 0023, 0004, 0000, 0000, 0000, 0004, 0002, 0000, 0000, 
  0014, 0000, 0114, 0000, 0020, 0002, 0000, 0000, 0024, 0002, 0000, 0000, 0302, 0257, 0211, 0013, 
  0000, 0000, 0000, 0000, 0024, 0002, 0000, 0000, 0004, 0000, 0114, 0000, 0030, 0002, 0000, 0000, 
  0034, 0002, 0000, 0000, 0136, 0022, 0205, 0204, 0003, 0000, 0000, 0000, 0034, 0002, 0000, 0000, 
  0012, 0000, 0114, 0000, 0050, 0002, 0000, 0000, 0054, 0002, 0000, 0000, 0057, 0000, 0000, 0000, 
  0003, 0000, 0000, 0000, 0125, 0156, 0151, 0143, 0157, 0155, 0142, 0056, 0143, 0163, 0163, 0000, 
  0064, 0001, 0000, 0000, 0000, 0000, 0000, 0000, 0057, 0052, 0012, 0124, 0157, 0040, 0143, 0150, 
  0141, 0156, 0147, 0145, 0040, 0164, 0150, 0151, 0163, 0040, 0154, 0151, 0143, 0145, 0156, 0163, 
  0145, 0040, 0150, 0145, 0141, 0144, 0145, 0162, 0054, 0040, 0143, 0150, 0157, 0157, 0163, 0145, 
  0040, 0114, 0151, 0143, 0145, 0156, 0163, 0145, 0040, 0110, 0145, 0141, 0144, 0145, 0162, 0163, 
  0040, 0151, 0156, 0040, 0120, 0162, 0157, 0152, 0145, 0143, 0164, 0040, 0120, 0162, 0157, 0160, 
  0145, 0162, 0164, 0151, 0145, 0163, 0056, 0012, 0124, 0157, 0040, 0143, 0150, 0141, 0156, 0147, 
  0145, 0040, 0164, 0150, 0151, 0163, 0040, 0164, 0145, 0155, 0160, 0154, 0141, 0164, 0145, 0040, 
  0146, 0151, 0154, 0145, 0054, 0040, 0143, 0150, 0157, 0157, 0163, 0145, 0040, 0124, 0157, 0157, 
  0154, 0163, 0040, 0174, 0040, 0124, 0145, 0155, 0160, 0154, 0141, 0164, 0145, 0163, 0012, 0141, 
  0156, 0144, 0040, 0157, 0160, 0145, 0156, 0040, 0164, 0150, 0145, 0040, 0164, 0145, 0155, 0160, 
  0154, 0141, 0164, 0145, 0040, 0151, 0156, 0040, 0164, 0150, 0145, 0040, 0145, 0144, 0151, 0164, 
  0157, 0162, 0056, 0012, 0052, 0057, 0012, 0057, 0052, 0040, 0012, 0040, 0040, 0040, 0040, 0103, 
  0162, 0145, 0141, 0164, 0145, 0144, 0040, 0157, 0156, 0040, 0072, 0040, 0101, 0160, 0162, 0040, 
  0066, 0054, 0040, 0062, 0060, 0062, 0061, 0054, 0040, 0061, 0061, 0072, 0060, 0061, 0072, 0063, 
  0060, 0040, 0120, 0115, 0012, 0040, 0040, 0040, 0040, 0101, 0165, 0164, 0150, 0157, 0162, 0040, 
  0040, 0040, 0040, 0040, 0072, 0040, 0152, 0141, 0143, 0157, 0142, 0012, 0052, 0057, 0012, 0100, 
  0151, 0155, 0160, 0157, 0162, 0164, 0040, 0047, 0056, 0056, 0057, 0123, 0164, 0171, 0154, 0145, 
  0163, 0057, 0115, 0145, 0151, 0156, 0056, 0143, 0163, 0163, 0047, 0073, 0012, 0100, 0151, 0155, 
  0160, 0157, 0162, 0164, 0040, 0047, 0056, 0056, 0057, 0123, 0164, 0171, 0154, 0145, 0163, 0057, 
  0110, 0157, 0155, 0145, 0056, 0143, 0163, 0163, 0047, 0073, 0012, 0012, 0000, 0000, 0050, 0165, 
  0165, 0141, 0171, 0051, 0163, 0143, 0141, 0154, 0143, 0165, 0154, 0141, 0164, 0157, 0162, 0057, 
  0001, 0000, 0000, 0000, 0143, 0157, 0155, 0057, 0004, 0000, 0000, 0000, 0141, 0166, 0151, 0156, 
  0164, 0141, 0156, 0147, 0165, 0057, 0000, 0000, 0002, 0000, 0000, 0000
} };
#else /* _MSC_VER */
static const SECTION union { const guint8 data[557]; const double alignment; void * const ptr;}  styles_resource_data = {
  "\107\126\141\162\151\141\156\164\000\000\000\000\000\000\000\000"
  "\030\000\000\000\254\000\000\000\000\000\000\050\005\000\000\000"
  "\000\000\000\000\001\000\000\000\003\000\000\000\005\000\000\000"
  "\005\000\000\000\324\265\002\000\377\377\377\377\254\000\000\000"
  "\001\000\114\000\260\000\000\000\264\000\000\000\156\073\232\243"
  "\002\000\000\000\264\000\000\000\013\000\166\000\300\000\000\000"
  "\004\002\000\000\012\113\040\023\004\000\000\000\004\002\000\000"
  "\014\000\114\000\020\002\000\000\024\002\000\000\302\257\211\013"
  "\000\000\000\000\024\002\000\000\004\000\114\000\030\002\000\000"
  "\034\002\000\000\136\022\205\204\003\000\000\000\034\002\000\000"
  "\012\000\114\000\050\002\000\000\054\002\000\000\057\000\000\000"
  "\003\000\000\000\125\156\151\143\157\155\142\056\143\163\163\000"
  "\064\001\000\000\000\000\000\000\057\052\012\124\157\040\143\150"
  "\141\156\147\145\040\164\150\151\163\040\154\151\143\145\156\163"
  "\145\040\150\145\141\144\145\162\054\040\143\150\157\157\163\145"
  "\040\114\151\143\145\156\163\145\040\110\145\141\144\145\162\163"
  "\040\151\156\040\120\162\157\152\145\143\164\040\120\162\157\160"
  "\145\162\164\151\145\163\056\012\124\157\040\143\150\141\156\147"
  "\145\040\164\150\151\163\040\164\145\155\160\154\141\164\145\040"
  "\146\151\154\145\054\040\143\150\157\157\163\145\040\124\157\157"
  "\154\163\040\174\040\124\145\155\160\154\141\164\145\163\012\141"
  "\156\144\040\157\160\145\156\040\164\150\145\040\164\145\155\160"
  "\154\141\164\145\040\151\156\040\164\150\145\040\145\144\151\164"
  "\157\162\056\012\052\057\012\057\052\040\012\040\040\040\040\103"
  "\162\145\141\164\145\144\040\157\156\040\072\040\101\160\162\040"
  "\066\054\040\062\060\062\061\054\040\061\061\072\060\061\072\063"
  "\060\040\120\115\012\040\040\040\040\101\165\164\150\157\162\040"
  "\040\040\040\040\072\040\152\141\143\157\142\012\052\057\012\100"
  "\151\155\160\157\162\164\040\047\056\056\057\123\164\171\154\145"
  "\163\057\115\145\151\156\056\143\163\163\047\073\012\100\151\155"
  "\160\157\162\164\040\047\056\056\057\123\164\171\154\145\163\057"
  "\110\157\155\145\056\143\163\163\047\073\012\012\000\000\050\165"
  "\165\141\171\051\163\143\141\154\143\165\154\141\164\157\162\057"
  "\001\000\000\000\143\157\155\057\004\000\000\000\141\166\151\156"
  "\164\141\156\147\165\057\000\000\002\000\000\000" };
#endif /* !_MSC_VER */

static GStaticResource static_resource = { styles_resource_data.data, sizeof (styles_resource_data.data) - 1 /* nul terminator */, NULL, NULL, NULL };

G_MODULE_EXPORT
GResource *styles_get_resource (void);
GResource *styles_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a usable way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#ifndef __GTK_DOC_IGNORE__

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

#include <stdlib.h>

#define G_HAS_CONSTRUCTORS 1

/* We do some weird things to avoid the constructors being optimized
 * away on VS2015 if WholeProgramOptimization is enabled. First we
 * make a reference to the array from the wrapper to make sure its
 * references. Then we use a pragma to make sure the wrapper function
 * symbol is always included at the link stage. Also, the symbols
 * need to be extern (but not dllexport), even though they are not
 * really used from another object file.
 */

/* We need to account for differences between the mangling of symbols
 * for x86 and x64/ARM/ARM64 programs, as symbols on x86 are prefixed
 * with an underscore but symbols on x64/ARM/ARM64 are not.
 */
#ifdef _M_IX86
#define G_MSVC_SYMBOL_PREFIX "_"
#else
#define G_MSVC_SYMBOL_PREFIX ""
#endif

#define G_DEFINE_CONSTRUCTOR(_func) G_MSVC_CTOR (_func, G_MSVC_SYMBOL_PREFIX)
#define G_DEFINE_DESTRUCTOR(_func) G_MSVC_DTOR (_func, G_MSVC_SYMBOL_PREFIX)

#define G_MSVC_CTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _wrapper(void) { _func(); g_slist_find (NULL,  _array ## _func); return 0; } \
  __pragma(comment(linker,"/include:" _sym_prefix # _func "_wrapper")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _wrapper;

#define G_MSVC_DTOR(_func,_sym_prefix) \
  static void _func(void); \
  extern int (* _array ## _func)(void);              \
  int _func ## _constructor(void) { atexit (_func); g_slist_find (NULL,  _array ## _func); return 0; } \
   __pragma(comment(linker,"/include:" _sym_prefix # _func "_constructor")) \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif

#endif /* __GTK_DOC_IGNORE__ */

#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(resource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(resource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(resource_destructor)
#endif
G_DEFINE_DESTRUCTOR(resource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void resource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void resource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
