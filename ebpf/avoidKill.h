#define EPERM 1
#define	ESRCH		 3	/* No such process */

const volatile pid_t pidAvoidKill[MAX_PID_NUM];
struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __type(key, u32);
    __type(value, u32);
    __uint(max_entries, 8192);
} avoidKillPidMap SEC(".maps");

