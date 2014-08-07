define linefeed

endef

CFLAGS := -O2
EXTRA_CFLAGS := -Wall -Wextra
EXTRA_CPPFLAGS := -Iunity/src -Isrc

UNITY_SRCS := $(wildcard unity/src/*.c)
UNITY_OBJS := $(patsubst %.c,%.o,$(UNITY_SRCS))
TEST_CASE_SRCS := $(wildcard tests/test-*.c)
TEST_CASE_OBJS := $(patsubst %.c,%.o,$(TEST_CASE_SRCS))
TEST_RUNNERS := $(addprefix build/runners/,$(addsuffix -runner,$(notdir $(basename $(TEST_CASE_SRCS)))))

LIBRARY_SRCS := $(wildcard src/*.c)
LIBRARY_OBJS := $(patsubst %.c,%.o,$(LIBRARY_SRCS))

VERBOSE :=

ifeq ($(VERBOSE),)
    Q := @
else
    Q :=
endif

.PHONY: clean build-tests test test-summary

all: build-tests test

define make-runner-from-case
runner := $$(addprefix build/runners/,$$(addsuffix -runner,$$(notdir $$(basename $1))))
testobj := $$(basename $1).o

$$(testobj).o: EXTRA_CPPFLAGS += -Itests

$$(runner).c: $(1)
	$(Q)mkdir -p build/runners
	$(Q)ruby unity/auto/generate_test_runner.rb $$^ $$@

$$(runner).o: EXTRA_CPPFLAGS += -Itests

$$(runner): $$(testobj) $$(runner).o $(LIBRARY_OBJS) $(UNITY_OBJS)
	$(Q)cc -o $$@ $$^

build-tests: $$(runner)

endef


$(foreach c,$(TEST_CASE_SRCS),$(eval $(call make-runner-from-case,$c)))

foo: $(UNITY_OBJS)
	$(Q)cc -o foo $(UNITY_OBJS)

%.o: %.c
	$(Q)$(CC) -c $(CFLAGS) $(EXTRA_CFLAGS) $(CPPFLAGS) $(EXTRA_CPPFLAGS) $< -o $@

test: | $(TEST_RUNNERS)
	$(Q)$(foreach r,$(TEST_RUNNERS),$r; )

test-summary:
	$(Q)mkdir -p build/results
	$(Q)$(foreach r,$(TEST_RUNNERS),$r > build/results/$(notdir $r).log && mv build/results/$(notdir $r).log build/results/$(notdir $r).testpass || mv build/results/$(notdir $r).log build/results/$(notdir $r).testfail; )
	$(Q)ruby unity/auto/unity_test_summary.rb build/results/ ./

clean:
	$(Q)rm -rf $(UNITY_OBJS) foo build $(TEST_CASE_OBJS) $(LIBRARY_OBJS)
