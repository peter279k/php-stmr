PHP_ARG_ENABLE(stmr, whether to enable stmr support,
[  --enable-stmr          Enable stmr support], no)

if test "$PHP_STMR" != "no"; then
  AC_DEFINE(HAVE_STMR, 1, [ Have stmr support ])
  PHP_NEW_EXTENSION(stmr, php_stmr.c, $ext_shared)
fi
