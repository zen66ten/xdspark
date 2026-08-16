# xdspark

XDP program + Go daemon that count bytes and packets per IP protocol on a
network interface, aggregate them over a sliding window, and draw cool
sparklines in a terminal. Observability only: every packet still passes
through the host stack untouched.

Two halves:

- `coral/` - the XDP program (kernel): classify by protocol byte, bump a PERCPU_ARRAY counter
- `teal/` - the Go daemon (userspace): load/attach, poll the map, window, render

Requires `clang` + `libbpf-devel` and a Go module dependency on `github.com/cilium/ebpf`.
