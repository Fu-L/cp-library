a.out: main.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o a.out main.cpp
debug: main.cpp
	g++ -std=gnu++20 -Wall -Wextra -fsanitize=address,undefined -O2 -o debug main.cpp
tle: tle.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o tle tle.cpp
gen: gen.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o gen gen.cpp
judge: judge.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o judge judge.cpp

.PHONY: clean
clean:
	rm a.out tle gen judge combined.cpp test/random*

.PHONY: acl
acl:
	python3 expander.py main.cpp

.PHONY: in
in:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o gen gen.cpp && oj g/i ./gen

.PHONY: out
out:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o tle tle.cpp && oj g/o -c ./tle

.PHONY: t
t:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o a.out main.cpp && oj t

.PHONY: et
et:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o a.out main.cpp && oj t -e 1e-6

.PHONY: j
j:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o judge judge.cpp && oj t --judge-command "./judge"

.PHONY: re
re:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o judge judge.cpp && oj t/r ./judge

.PHONY: s
s:
	acc s -s -- -w 0 -l 5001
