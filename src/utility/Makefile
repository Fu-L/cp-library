a.out: main.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o a.out main.cpp
debug: main.cpp
	g++ -std=gnu++20 -Wall -Wextra -fsanitize=undefined,address -O2 -o debug main.cpp
bundle: bundled.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o bundle bundled.cpp
tle: tle.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o tle tle.cpp
gen: gen.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o gen gen.cpp
judge: judge.cpp
	g++ -std=gnu++20 -Wall -Wextra -O2 -o judge judge.cpp

.PHONY: clean in out t et j re b s
clean:
	rm a.out debug tle gen judge bundled.cpp test/random*

in:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o gen gen.cpp && oj g/i ./gen

out:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o tle tle.cpp && oj g/o -c ./tle

t:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o a.out main.cpp && oj t

et:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o a.out main.cpp && oj t -e 1e-6

j:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o judge judge.cpp && oj t --judge-command "./judge"

re:
	g++ -std=gnu++20 -Wall -Wextra -O2 -o judge judge.cpp && oj t/r ./judge

b:
	grep -v 'debug' main.cpp > bundle_tmp.cpp
	oj-bundle -I ../../../cp-library/src bundle_tmp.cpp | grep -v -e '^#line ' -e '^#pragma once' > bundled.cpp
	rm bundle_tmp.cpp
	code bundled.cpp

s:
	grep -v 'debug' main.cpp > bundle_tmp.cpp
	oj-bundle -I ../../../cp-library/src bundle_tmp.cpp | grep -v -e '^#line ' -e '^#pragma once' > bundled.cpp
	rm bundle_tmp.cpp
	acc s -s -- -w 0 -l 5001 --no-open