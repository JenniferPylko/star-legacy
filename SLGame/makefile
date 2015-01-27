QCC = gmqcc
QCCFLAGS += \
	-std=gmqcc \
	-Werror -Wall \
	-O3 \
	-fadjust-vector-fields \
	-fftepp \
	-fftepp-predefs \
	-frelaxed-switch \
	-fshort-logic \
	-fno-perl-logic \
	-ftranslatable-strings \
	-fno-initialized-nonconstants \
	-fno-assign-function-types \
	-fcorrect-ternary \
	-fno-single-vector-defs \
	-fcorrect-logic \
	-ftrue-empty-strings \
	-fno-false-empty-strings \
	-futf8 \
	-fno-bail-on-werror \
	-floop-labels \
	-funtyped-nil \
	-fno-permissive \
	-finitialized-nonconstants \
	-fvariadic-args

all:
	test -d bin/ || mkdir -p bin/
	$(QCC) $(QCCFLAGS)
