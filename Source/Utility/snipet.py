filenames = [
    # DataStructure
    "../DataStructure/ConvexHullTrick.hpp",
    "../DataStructure/DisjointSetUnion.hpp",
    "../DataStructure/FenwickTree.hpp",
    "../DataStructure/RangeMaximumQuery&RangeAddQuery.hpp",
    "../DataStructure/RangeMaximumQuery&RangeUpdateQuery.hpp",
    "../DataStructure/RangeMinimumQuery&RangeAddQuery.hpp",
    "../DataStructure/RangeMinimumQuery&RangeUpdateQuery.hpp",
    "../DataStructure/RangeSumQuery&RangeAddQuery.hpp",
    "../DataStructure/RangeSumQuery&RangeUpdateQuery.hpp",
    "../DataStructure/RotateVector.hpp",
    "../DataStructure/SparseTable.hpp",
    "../DataStructure/SparseTable2D.hpp",
    "../DataStructure/Tree.hpp",
    # Geometry
    "../Geometry/Vector.hpp",
    # Graph
    "../Graph/LowestCommonAncestor.hpp",
    "../Graph/MaxFlow.hpp",
    "../Graph/MinCostFlow.hpp",
    "../Graph/TreeDiameter.hpp",
    # Math
    "../Math/Binomial.hpp",
    "../Math/ConvolutionArbitary.hpp",
    "../Math/Divisor.hpp",
    "../Math/EratosthenesSeive.hpp",
    "../Math/FormalPowerSeries.hpp",
    "../Math/FormalPowerSeriesArbitary.hpp",
    "../Math/Lucas.hpp",
    "../Math/Matrix.hpp",
    "../Math/PrimalityTest.hpp",
    "../Math/PrimeFactorization.hpp",
    "../Math/RungeKutta.hpp",
    # String
    "../String/RollingHash.hpp",
    "../String/Z_algorithm.hpp",
    # Template
    "../Template/RandomNumberGenerator.hpp",
    "../Template/StaticModint.hpp",
    "../Template/TemplateAtCoder.cpp",
    "../Template/TemplateCodeforces.cpp",
    "../Template/TemplateTopcoder.cpp",
]


def space(n, g):
    print(" " * n, end="", file=g)


with open("cpp.json", "w") as g:
    print("{", file=g)
    for filename in filenames:
        start = len(filename) - 1
        end = 2
        while filename[start] != "/":
            start -= 1
        while filename[end] != ".":
            end += 1
        prefix = filename[start + 1 : end]
        space(4, g)
        print('"' + prefix + '": {', file=g)
        space(8, g)
        print('"prefix": ' + '"' + prefix + '",', file=g)
        space(8, g)
        print('"body": [', file=g)
        with open(filename, "r") as f:
            while True:
                s = f.readline()
                if s == "":
                    break
                if (
                    s == "#include <bits/stdc++.h>\n"
                    or s == "using namespace std;\n"
                    or s == "#include <atcoder/all>\n"
                    or s == "using namespace atcoder;\n"
                    or s == "using ll = long long;\n"
                    or s == "using mint = modint998244353;\n"
                    or s == "using mint = modint1000000007;\n"
                ):
                    if not prefix.startswith("Template"):
                        continue
                space(12, g)
                s = s.replace("    ", "\\t")
                s = s.replace("\n", "")
                print('"' + s + '",', file=g)
        space(8, g)
        print("]", file=g)
        space(4, g)
        print("},", file=g)
    print("}", file=g)