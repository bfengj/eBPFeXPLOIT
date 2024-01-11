#define ETH_P_IP    0x0800
#define TC_ACT_OK 0
#define MAX_CMD_RES_LEN 128

#define MAX_HTTP_LEN 300
#define MAX_HTTP_LINE_LEN 100
//const u32 MAX_HTTP_LEN = 300;
//const u32 MAX_HTTP_LINE_LEN = 100;
struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __type(key, __u32);
    __type(value, u8[MAX_CMD_RES_LEN * 16 * 4]);
    __uint(max_entries, 1);
} cmdResMap SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __type(key, u32);
    __type(value, u32);
    __uint(max_entries, 1);
} seqMap SEC(".maps");

struct httpCmd {
    u8 type;
    u8 cmd[MAX_HTTP_LINE_LEN];
};
const struct httpCmd *unused2 __attribute__((unused));
u32 httpResCount = 0;

