TARGETS=hex2b64 xor

%: %.c
	cc $< -o $@

all: $(TARGETS)
