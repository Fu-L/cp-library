#pragma once
#include "../template/template.hpp"
#include "../template/policy_based_data_structure.hpp"
using SortedSet = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using SortedMultiSet = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;