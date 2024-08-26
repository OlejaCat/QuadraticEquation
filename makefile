CFLAGS = -Wall -Wextra -std=c11 -Og
ifeq ($(CC), clang)
CFLAGS += -Wconversion -Wdangling -Wdeprecated -Wdocumentation -Wformat -Wfortify-source -Wgcc-compat -Wgnu -Wignored-attributes -Wignored-pragmas -Wimplicit -Wmost -Wshadow-all -Wthread-safety -Wuninitialized -Wunused -Wformat
CFLAGS += -Wargument-outside-range -Wassign-enum -Wbitwise-instead-of-logical -Wc23-extensions -Wc11-extensions -Wcast-align -Wcast-function-type -Wcast-qual -Wcomma -Wcomment -Wcompound-token-split -Wconditional-uninitialized -Wduplicate-decl-specifier -Wduplicate-enum -Wduplicate-method-arg -Wduplicate-method-match -Wempty-body -Wempty-init-stmt -Wenum-compare -Wenum-constexpr-conversion -Wextra-tokens -Wfixed-enum-extension -Wfloat-equal -Wloop-analysis -Wframe-address -Wheader-guard -Winfinite-recursion -Wno-gnu-binary-literal -Wint-conversion -Wint-in-bool-context -Wmain -Wmisleading-indentation -Wmissing-braces -Wmissing-prototypes -Wover-aligned -Wundef -Wvla
endif
ifeq ($(CC), cc)
CFLAGS += -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-default -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-usage=8192 -Wstack-protector
endif
ifeq ($(CC), gcc)
CFLAGS += -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-default -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-usage=8192 -Wstack-protector
endif

LINKER_FLAGS = -lm

INCLUDE = -I include
CFLAGS += $(INCLUDE)

all: base

base: main.o helpful_functions.o solve_quadratic.o unit_test.o user_interaction.o user_interface.o command_processing.o
	@$(CC) $(LINKER_FLAGS) $(CFLAGS) main.o helpful_functions.o solve_quadratic.o unit_test.o user_interaction.o user_interface.o command_processing.o -o solve

main.o: source/main.c
	@$(CC) $(CFLAGS) -c source/main.c

helpful_functions.o: source/helpful_functions.c
	@$(CC) $(CFLAGS) -c source/helpful_functions.c

solve_quadratic.o: source/solve_quadratic.c
	@$(CC) $(CFLAGS) -c source/solve_quadratic.c

unit_test.o: source/unit_test.c
	@$(CC) $(CFLAGS) -c source/unit_test.c

user_interaction.o: source/user_interaction.c
	@$(CC) $(CFLAGS) -c source/user_interaction.c

user_interface.o: source/user_interface.c
	@$(CC) $(CFLAGS) -c source/user_interface.c

command_processing.o: source/command_processing.c
	@$(CC) $(CFLAGS) -c source/command_processing.c

clean:
	@rm -rf *.o solve
