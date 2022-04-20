#pragma once

#define CONCAT_(l, r) l ## r
#define CONCAT(l, r) CONCAT_(l, r)

# define BOOST_PP_BOOL(x) BOOST_PP_BOOL_I(x)
# define BOOST_PP_BOOL_I(x) BOOST_PP_BOOL_ ## x
# define BOOST_PP_BOOL_0 0
# define BOOST_PP_BOOL_1 1
# define BOOST_PP_BOOL_2 1
# define BOOST_PP_BOOL_3 1
# define BOOST_PP_BOOL_4 1
# define BOOST_PP_BOOL_5 1
# define BOOST_PP_BOOL_6 1
# define BOOST_PP_BOOL_7 1
# define BOOST_PP_BOOL_8 1
# define BOOST_PP_BOOL_9 1
# define BOOST_PP_BOOL_10 1
# define BOOST_PP_BOOL_11 1
# define BOOST_PP_BOOL_12 1
# define BOOST_PP_BOOL_13 1
# define BOOST_PP_BOOL_14 1
# define BOOST_PP_BOOL_15 1
# define BOOST_PP_BOOL_16 1
# define BOOST_PP_BOOL_17 1
# define BOOST_PP_BOOL_18 1
# define BOOST_PP_BOOL_19 1
# define BOOST_PP_BOOL_20 1
# define BOOST_PP_BOOL_21 1
# define BOOST_PP_BOOL_22 1
# define BOOST_PP_BOOL_23 1
# define BOOST_PP_BOOL_24 1
# define BOOST_PP_BOOL_25 1
# define BOOST_PP_BOOL_26 1
# define BOOST_PP_BOOL_27 1
# define BOOST_PP_BOOL_28 1
# define BOOST_PP_BOOL_29 1
# define BOOST_PP_BOOL_30 1
# define BOOST_PP_BOOL_31 1
# define BOOST_PP_BOOL_32 1
# define BOOST_PP_BOOL_33 1
# define BOOST_PP_BOOL_34 1
# define BOOST_PP_BOOL_35 1
# define BOOST_PP_BOOL_36 1
# define BOOST_PP_BOOL_37 1
# define BOOST_PP_BOOL_38 1
# define BOOST_PP_BOOL_39 1
# define BOOST_PP_BOOL_40 1
# define BOOST_PP_BOOL_41 1
# define BOOST_PP_BOOL_42 1
# define BOOST_PP_BOOL_43 1
# define BOOST_PP_BOOL_44 1
# define BOOST_PP_BOOL_45 1
# define BOOST_PP_BOOL_46 1
# define BOOST_PP_BOOL_47 1
# define BOOST_PP_BOOL_48 1
# define BOOST_PP_BOOL_49 1
# define BOOST_PP_BOOL_50 1
# define BOOST_PP_BOOL_51 1
# define BOOST_PP_BOOL_52 1
# define BOOST_PP_BOOL_53 1
# define BOOST_PP_BOOL_54 1
# define BOOST_PP_BOOL_55 1
# define BOOST_PP_BOOL_56 1
# define BOOST_PP_BOOL_57 1
# define BOOST_PP_BOOL_58 1
# define BOOST_PP_BOOL_59 1
# define BOOST_PP_BOOL_60 1
# define BOOST_PP_BOOL_61 1
# define BOOST_PP_BOOL_62 1
# define BOOST_PP_BOOL_63 1

#define BOOST_PP_IIF(bit, t, f) BOOST_PP_IIF_OO((bit, t, f))
#define BOOST_PP_IIF_OO(par) BOOST_PP_IIF_I ## par
#define BOOST_PP_IIF_I(bit, t, f) BOOST_PP_IIF_II(BOOST_PP_IIF_ ## bit(t, f))
#define BOOST_PP_IIF_II(id) id
#define BOOST_PP_IIF_0(t, f) f
#define BOOST_PP_IIF_1(t, f) t
#define BOOST_PP_IF(cond, t, f) BOOST_PP_IIF(BOOST_PP_BOOL(cond), t, f)

#ifdef _MSC_VER // Microsoft compilers

#   define GET_ARG_COUNT(...)  INTERNAL_EXPAND_ARGS_PRIVATE(INTERNAL_ARGS_AUGMENTER(__VA_ARGS__))

#   define INTERNAL_ARGS_AUGMENTER(...) unused, __VA_ARGS__
#   define INTERNAL_EXPAND(x) x
#   define INTERNAL_EXPAND_ARGS_PRIVATE(...) INTERNAL_EXPAND(INTERNAL_GET_ARG_COUNT_PRIVATE(__VA_ARGS__, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#   define INTERNAL_GET_ARG_COUNT_PRIVATE(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count

#else // Non-Microsoft compilers

#   define GET_ARG_COUNT(...) INTERNAL_GET_ARG_COUNT_PRIVATE(0, ## __VA_ARGS__, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#   define INTERNAL_GET_ARG_COUNT_PRIVATE(_0, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_, _10_, _11_, _12_, _13_, _14_, _15_, _16_, _17_, _18_, _19_, _20_, _21_, _22_, _23_, _24_, _25_, _26_, _27_, _28_, _29_, _30_, _31_, _32_, _33_, _34_, _35_, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, _65, _66, _67, _68, _69, _70, count, ...) count

#endif

#ifdef _MSC_VER // Microsoft compilers
#define EXPAND_PRI(s,f,a,...) (s,f,a,__VA_ARGS__)
#define EXPAND(s,f,a,...) EXPAND_PRI(s,f,a,__VA_ARGS__)
#define DOPAIR0(s,f,a,O)
#define DOPAIR2(s,f,a,t,v) f(a,t,v)
#define DOPAIR4(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR2 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR6(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR4 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR8(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR6 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR10(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR8 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR12(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR10 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR14(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR12 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR16(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR14 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR18(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR16 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR20(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR18 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR22(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR20 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR24(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR22 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR26(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR24 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR28(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR26 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR30(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR28 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR32(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR30 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR34(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR32 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR36(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR34 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR38(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR36 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR40(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR38 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR42(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR40 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR44(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR42 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR46(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR44 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR48(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR46 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR50(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR48 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR52(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR50 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR54(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR52 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR56(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR54 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR58(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR56 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR60(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR58 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR62(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR60 EXPAND(s,f,a,__VA_ARGS__)
#define DOPAIR64(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR62 EXPAND(s,f,a,__VA_ARGS__)
#define EXPAND_CALL_PRI(sepatator,fun,funarg,...) (sepatator,fun,funarg,__VA_ARGS__)
#define EXPAND_CALL(sepatator,fun,funarg,...) EXPAND_CALL_PRI(sepatator,fun,funarg,__VA_ARGS__)
#define VA_FOREACH_PAIR_PRI(sepatator,fun,funarg,...) \
        CONCAT(DOPAIR,GET_ARG_COUNT(__VA_ARGS__)) EXPAND_CALL(sepatator,fun,funarg,__VA_ARGS__)
#define VA_FOREACH_PAIR(sepatator,fun,funarg,...) \
        VA_FOREACH_PAIR_PRI(sepatator,fun,funarg,__VA_ARGS__)

#else
#define DOPAIR0(s,f,a,O)
#define DOPAIR2(s,f,a,t,v) f(a,t,v)
#define DOPAIR4(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR2(s,f,a,__VA_ARGS__)
#define DOPAIR6(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR4(s,f,a,__VA_ARGS__)
#define DOPAIR8(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR6(s,f,a,__VA_ARGS__)
#define DOPAIR10(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR8(s,f,a,__VA_ARGS__)
#define DOPAIR12(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR10(s,f,a,__VA_ARGS__)
#define DOPAIR14(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR12(s,f,a,__VA_ARGS__)
#define DOPAIR16(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR14(s,f,a,__VA_ARGS__)
#define DOPAIR18(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR16(s,f,a,__VA_ARGS__)
#define DOPAIR20(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR18(s,f,a,__VA_ARGS__)
#define DOPAIR22(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR20(s,f,a,__VA_ARGS__)
#define DOPAIR24(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR22(s,f,a,__VA_ARGS__)
#define DOPAIR26(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR24(s,f,a,__VA_ARGS__)
#define DOPAIR28(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR26(s,f,a,__VA_ARGS__)
#define DOPAIR30(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR28(s,f,a,__VA_ARGS__)
#define DOPAIR32(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR30(s,f,a,__VA_ARGS__)
#define DOPAIR34(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR32(s,f,a,__VA_ARGS__)
#define DOPAIR36(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR34(s,f,a,__VA_ARGS__)
#define DOPAIR38(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR36(s,f,a,__VA_ARGS__)
#define DOPAIR40(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR38(s,f,a,__VA_ARGS__)
#define DOPAIR42(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR40(s,f,a,__VA_ARGS__)
#define DOPAIR44(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR42(s,f,a,__VA_ARGS__)
#define DOPAIR46(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR44(s,f,a,__VA_ARGS__)
#define DOPAIR48(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR46(s,f,a,__VA_ARGS__)
#define DOPAIR50(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR48(s,f,a,__VA_ARGS__)
#define DOPAIR52(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR50(s,f,a,__VA_ARGS__)
#define DOPAIR54(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR52(s,f,a,__VA_ARGS__)
#define DOPAIR56(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR54(s,f,a,__VA_ARGS__)
#define DOPAIR58(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR56(s,f,a,__VA_ARGS__)
#define DOPAIR60(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR58(s,f,a,__VA_ARGS__)
#define DOPAIR62(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR60(s,f,a,__VA_ARGS__)
#define DOPAIR64(s,f,a,t,v,...) DOPAIR2(s,f,a,t,v) s DOPAIR62(s,f,a,__VA_ARGS__)


#define VA_FOREACH_PAIR_(sepatator,fun,funarg,...) \
        CONCAT(DOPAIR,GET_ARG_COUNT(__VA_ARGS__))(sepatator,fun,funarg,__VA_ARGS__)
#define VA_FOREACH_PAIR(sepatator,fun,funarg,...) \
        VA_FOREACH_PAIR_(sepatator,fun,funarg,__VA_ARGS__)

#endif

#define DEF_STRUCT_FIELD_DEF(t,v) t v
#define DEF_STRUCT_FIELD(a,t,v) DEF_STRUCT_FIELD_DEF(t,v);

#define DEF_STRUCT(CLSNAME, ...)\
struct CLSNAME {\
    VA_FOREACH_PAIR(,DEF_STRUCT_FIELD, , __VA_ARGS__)\
};