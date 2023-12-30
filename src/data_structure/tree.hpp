#pragma once
#include "cp-library/src/template/template.hpp"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
using Set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using MultiSet = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;