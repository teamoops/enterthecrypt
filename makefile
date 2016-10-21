TARGETS=ascii2hex xor onlyascii

%: %.c
	cc $< -o $@

all: $(TARGETS)
