#define DEBUG 1
#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...) \
  bpf_printk(fmt, ##args)
#else
#define DEBUG_PRINT(fmt, args...) \
  do { } while (0)
#endif