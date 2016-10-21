TARGETS=ascii2hex xor onlyascii
CFLAGS=-std=c99 -g

%: %.c
	cc $(CFLAGS) $< -o $@

all: $(TARGETS)
