#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>

struct coral_stats {
    __u64 rx_packets;
    __u64 rx_bytes;
};

struct {
    __uint(type, BPF_MAP_TYPE_PERCPU_ARRAY);
    __uint(max_entries, 256);
    __type(key, __u32);
    __type(value, struct coral_stats);
} stats SEC(".maps");




char _license[] SEC("license") = "GPL";