include config.mk

all: bin/day01 \
	 bin/day02 \
	 bin/day03 \
	 bin/day04

bin/%: src/%.cpp | bin
	c++ $(CPPFLAGS) $^ -o $@

clean:
	rm -rf bin

bin:
	mkdir $@

.PHONY: all clean
