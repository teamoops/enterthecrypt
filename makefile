TARGETS=ascii2hex

%: %.c
	cc $< -o $@

all: $(TARGETS)
