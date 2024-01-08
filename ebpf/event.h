
struct event {
    u8 type;
    u32 pid;
    u8 comm[TASK_COMM_LEN];
    bool success;
};
const struct event *unused1 __attribute__((unused));

// Ringbuffer Map to pass messages from kernel to user

struct {
    __uint(type, BPF_MAP_TYPE_RINGBUF);
    __uint(max_entries, 4 * 1024 * 1024);//?
} rb SEC(".maps");